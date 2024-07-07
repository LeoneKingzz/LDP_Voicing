typedef unsigned char		UInt8;		//!< An unsigned 8-bit integer value
typedef unsigned short		UInt16;		//!< An unsigned 16-bit integer value
typedef unsigned long		UInt32;		//!< An unsigned 32-bit integer value
typedef unsigned long long	UInt64;		//!< An unsigned 64-bit integer value
typedef signed char			SInt8;		//!< A signed 8-bit integer value
typedef signed short		SInt16;		//!< A signed 16-bit integer value
typedef signed long			SInt32;		//!< A signed 32-bit integer value
typedef signed long long	SInt64;		//!< A signed 64-bit integer value
typedef float				Float32;	//!< A 32-bit floating point value
typedef double				Float64;	//!< A 64-bit floating point value

#include "Windows.h"
#include "../skse/PluginAPI.h"
#include "../skse/skse_version.h"

// Include to register papyrus command.
#include "../skse/PapyrusVM.h"
#include "../skse/PapyrusNativeFunctions.h"
#include "../skse/GameReferences.h"

#define USE_AUTOSAVE

#define START_ASM1(b) void * jumpAddress = NULL; _asm { mov jumpAddress, offset b##CodeStart
#define START_ASM2(b) jmp b##CodeEnd
#define START_ASM3(b) b##CodeStart:

#define END_ASM(b, addr1, addr2) b##CodeEnd: \
} \
	WriteJump(addr1, addr2, (int)jumpAddress);

bool WriteJump(int addressFrom1, int addressFrom2, int addressTo)
{
	DWORD oldProtect = 0;

	int len1 = addressFrom2 - addressFrom1;
	if (VirtualProtect((void *)addressFrom1, len1, PAGE_EXECUTE_READWRITE, &oldProtect))
	{
		*((unsigned char *)addressFrom1) = (unsigned char)0xE9;
		*((int *)(addressFrom1 + 1)) = (int)addressTo - addressFrom1 - 5;
		for (int i = 5; i < len1; i++)
			*((unsigned char *)(i + addressFrom1)) = (unsigned char)0x90;
		if (VirtualProtect((void *)addressFrom1, len1, oldProtect, &oldProtect))
			return true;
	}

	return false;
}

bool WriteMemory(int address, char * data, int length)
{
	DWORD oldProtect = 0;

	if (VirtualProtect((void *)address, length, PAGE_EXECUTE_READWRITE, &oldProtect))
	{
		memcpy((void*)address, data, length);
		if (VirtualProtect((void *)address, length, oldProtect, &oldProtect))
			return true;
	}

	return false;
}

int _allow_Save = 0;
int _is_AutoSave = 0;
int _is_Rest = 0;
int _is_ManualMode = 0;

void AutoSaveNow()
{
	if (_is_Rest == 0)
		return;
	_is_Rest = 0;

	_allow_Save = 1;
#ifdef USE_AUTOSAVE
	static int autoSaveFunc = 0x8F0B40;
#else
	static int autoSaveFunc = 0x8F0B50;
#endif
	_asm
	{
		call autoSaveFunc
	}
}

UInt32 i_GetVersion(StaticFunctionTag * base)
{
	return 1;
}

void i_SetManualSave(StaticFunctionTag * base, UInt32 mode)
{
	_is_ManualMode = mode != 0 ? 1 : 0;
}

void i_DoManualSave(StaticFunctionTag * base)
{
	_is_Rest = 1;
	AutoSaveNow();
}

bool _registerFunctions(VMClassRegistry * registry)
{
	const char * className = "SaveGamePlugin";

	UInt32 fl = 0;
	{
		const char * methodName = "SetManualSave";
		registry->RegisterFunction(new NativeFunction1<StaticFunctionTag, void, UInt32>(methodName, className, i_SetManualSave, registry));
		registry->SetFunctionFlags(className, methodName, fl);
	}
	{
		const char * methodName = "DoManualSave";
		registry->RegisterFunction(new NativeFunction0<StaticFunctionTag, void>(methodName, className, i_DoManualSave, registry));
		registry->SetFunctionFlags(className, methodName, fl);
	}
	{
		const char * methodName = "GetVersion";
		registry->RegisterFunction(new NativeFunction0<StaticFunctionTag, UInt32>(methodName, className, i_GetVersion, registry));
		registry->SetFunctionFlags(className, methodName, fl);
	}

	return true;
}

extern "C"
{
	bool SKSEPlugin_Query(const SKSEInterface * skse, PluginInfo * info)
	{
		// populate info structure
		info->infoVersion = PluginInfo::kInfoVersion;
		info->name = "SaveGamePlugin";
		info->version = 1;

		if (skse->isEditor || skse->runtimeVersion != RUNTIME_VERSION_1_9_32_0)
			return false;
		return true;
	}

	bool SKSEPlugin_Load(const SKSEInterface * skse)
	{
		// Check if what follows is resting or waiting. This is actually not needed due to next part, but do it anyway to make sure.
		{
			static int restAddr1 = 0x887B79;
			static int restAddr2 = 0x887B7F;
			{
				START_ASM1(AB)
					START_ASM2(AB)
					START_ASM3(AB)

					add ecx, 0x9C

					test al, al
					je ABWaitCode

					mov _is_Rest, 1
					jmp restAddr2

				ABWaitCode :
				mov _is_Rest, 0
					jmp restAddr2

					END_ASM(AB, restAddr1, restAddr2)
			};
		};

		// OnSleepStop, this is called from SleepWaitMenu during Rest.
		{
			static int stopAddr1 = 0x8CD030;
			static int stopAddr2 = 0x8CD035;
			{
				START_ASM1(AC)
					START_ASM2(AC)
					START_ASM3(AC)

					sub esp, 0xC
					push esi
					push edi
					
					pushad
					pushfd

					cmp _is_ManualMode, 0
					jne ACDoNothing

					call AutoSaveNow

				ACDoNothing :

					popfd
					popad

					jmp stopAddr2

					END_ASM(AC, stopAddr1, stopAddr2)
			};
		};

		// Prohibit saving (or allow).
		{
			static int testAddr1 = 0x681545;
			static int testAddr2 = 0x68154A;
			static int testFunc = 0x681180;

			{
				START_ASM1(AA)
					START_ASM2(AA)
					START_ASM3(AA)

					mov _is_AutoSave, ebx

					call testFunc

					test al, al
					je AADontCode

					test _is_AutoSave, 0xFF
#ifdef USE_AUTOSAVE
					je AADontCode
#else
					jne AADontCode
#endif

					cmp _allow_Save, 0
					je AADontCode

					mov _allow_Save, 0
					jmp testAddr2

				AADontCode :
				mov al, 0
					jmp testAddr2

					END_ASM(AA, testAddr1, testAddr2)
			};
		};

		// Register papyrus command. We don't include script with plugin but if someone wants to use this mod as a base to make their own custom saving mod then they can create script and use functions.
		{
			SKSEPapyrusInterface * papyrusInterface = (SKSEPapyrusInterface *)skse->QueryInterface(kInterface_Papyrus);
			if (papyrusInterface)
				papyrusInterface->Register(_registerFunctions);
		};

		return true;
	}
};
