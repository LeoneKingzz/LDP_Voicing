#include "hook.h"

namespace hooks
{
    void on_animation_event::GetEquippedShout(RE::Actor *actor, bool SpellFire){
        auto limboshout = actor->GetActorRuntimeData().selectedPower;

        if (limboshout && limboshout->Is(RE::FormType::Shout))
        {
            bool IsActorTypeDragon = actor->HasKeywordString("DragonVoiceKey");
            bool IsActorTypePaarthurnax = actor->HasKeywordString("MasterPaarthurnaxKey");
            bool IsActorTypeAlduin = actor->HasKeywordString("AlduinUnitedKey");
            bool IsActorTypeOdahviing = actor->HasKeywordString("OdahviingKey");

            std::string_view Lsht = limboshout->GetFormEditorID();
            switch (hash(Lsht.data(), Lsht.size()))
            {
            case "ks_DragonFlameWaveShoutALDUIN"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin04BTorShul"));
                } else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin04AYol"));
                }
                break;

            case "005SummonShouts"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon07BQothZaam"));
                } else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon07ADiil"));
                }
                break;

            case "005StormShoutsDECIEVE"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15BLoSah"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15AFiik"));
                }
                break;

            case "005SahloknirStormShout"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15BSahDiin"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15AFiik"));
                }
                break;

            case "005StormShoutsBLOOD"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon30BSosHaas"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon30ALun"));
                }
                break;
            
            case "005UniqueBreathShouts"_h:
            case "005UniqueBreathShoutsALDUIN"_h:
            case "005UniqueBreathShoutsODAH"_h:
            case "005UniqueBreathShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon27BYolRon"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin24BYolRon"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing18BYolRon"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax17BYolRon"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon27AVah"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin24AVah"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing18AVah"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax17AVah"));
                    }
                }
                break;

            case "005VolleyBreathShouts"_h:
            case "005VolleyBreathShoutsALDUIN"_h:
            case "005VolleyBreathShoutsODAH"_h:
            case "005VolleyBreathShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon26BDaIiz"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin23BDaIiz"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing17BDaIiz"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax16BDaIiz"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon26AGron"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin23AGron"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing17AGron"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax16AGron"));
                    }
                }
                break;

            case "PaarthurnaxElementalFury"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax14BGrahDun"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax14ASu"));
                }
                break;

            case "PaarthurnaxWhirlwindTempest"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax13BNahKest"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax13AWuld"));
                }
                break;

            case "ks_DragonMoonBlast"_h:
            case "ks_DragonMoonBlastALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon25BJiidViin"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin22BJiidViin"));
                    }

                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon25ASos"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin22ASos"));
                    }
                }
                break;

            case "005StormShoutsFROST"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon24BSoDaan"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon24AJiid"));
                }
                break;

            case "zz05AlduinFirestorms"_h:
            case "dunCGDragonStormCallShout"_h:
            case "MQ206AlduinFirestormShout"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin08BToorNah"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin08AGaar"));
                }
                break;

            case "zz005DevourSoul_Alduin"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin19BDiiDu"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin19AZiiLos"));
                }
                break;

            case "005StormShoutsSHOCK"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon17BBahQo"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon17AStrun"));
                }
                break;

            case "005SahloknirStormShout"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15BSahDiin"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15AFiik"));
                }
                break;

            case "005SahloknirStormShout"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15BSahDiin"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15AFiik"));
                }
                break;

            case "005SahloknirStormShout"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15BSahDiin"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15AFiik"));
                }
                break;

            case "005SahloknirStormShout"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15BSahDiin"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon15AFiik"));
                }
                break;
            }
        }
       
    }







	void on_animation_event::ProcessEvent(RE::BSTEventSink<RE::BSAnimationGraphEvent>* a_sink, RE::BSAnimationGraphEvent* a_event, RE::BSTEventSource<RE::BSAnimationGraphEvent>* a_eventSource)
	{
		if (!a_event->holder) {
			return;
		}
		std::string_view eventTag = a_event->tag.data();
		RE::Actor* actor = const_cast<RE::TESObjectREFR*>(a_event->holder)->As<RE::Actor>();
		switch (hash(eventTag.data(), eventTag.size())) {
        case "BeginCastVoice"_h:
            GetEquippedShout(actor);

            break;

        case "Voice_SpellFire_Event"_h:

            GetEquippedShout(actor, true);

            break;
	
		
		}
	}

	EventResult on_animation_event::ProcessEvent_NPC(RE::BSTEventSink<RE::BSAnimationGraphEvent>* a_sink, RE::BSAnimationGraphEvent* a_event, RE::BSTEventSource<RE::BSAnimationGraphEvent>* a_eventSource)
	{
		ProcessEvent(a_sink, a_event, a_eventSource);
		return _ProcessEvent_NPC(a_sink, a_event, a_eventSource);
	}

	EventResult on_animation_event::ProcessEvent_PC(RE::BSTEventSink<RE::BSAnimationGraphEvent>* a_sink, RE::BSAnimationGraphEvent* a_event, RE::BSTEventSource<RE::BSAnimationGraphEvent>* a_eventSource)
	{
		ProcessEvent(a_sink, a_event, a_eventSource);
		return _ProcessEvent_PC(a_sink, a_event, a_eventSource);
	}

}

// const auto caster = a_defender->GetMagicCaster(RE::MagicSystem::CastingSource::kInstant);
// float a_reprisal = (EldenParry::GetSingleton()->AttackerBeatsParry(a_aggressor, a_defender));
// auto bHasEldenParryPerk2 = a_defender->HasPerk(RE::BGSPerk::LookupByEditorID("ORD_Bck20_TimedBlock_Perk_50_OrdASISExclude")->As<RE::BGSPerk>());
// auto bHasEldenParryPerk1 = a_defender->HasPerk(RE::BGSPerk::LookupByEditorID("ORD_Bck20_TimedBlock_Perk_20_OrdASISExclude")->As<RE::BGSPerk>());
// if (bHasEldenParryPerk2 || bHasEldenParryPerk1)
// {
//     RE::MagicItem *eldenArmorSpell = nullptr;
//     if (bHasEldenParryPerk2 == true)
//     {
//         eldenArmorSpell = RE::TESForm::LookupByEditorID<RE::MagicItem>("ORD_Bck_TimedBlock_Spell_Proc_2");
//     }
//     else if (bHasEldenParryPerk1)
//     {
//         eldenArmorSpell = RE::TESForm::LookupByEditorID<RE::MagicItem>("ORD_Bck_TimedBlock_Spell_Proc");
//     }
//     caster->CastSpellImmediate(eldenArmorSpell, true, a_defender, 1, false, 45, a_defender);
// }

// const auto ActorTypeDragon = RE::BGSKeyword::LookupByEditorID("ActorTypeDragon")->As<RE::BGSKeyword>();
// auto UDDragonAISpell = RE::TESForm::LookupByEditorID<RE::SpellItem>("aaaUDDragonAISpell");

// bool IsActorTypeDragon = Dragon->HasKeyword(ActorTypeDragon);
// bool HasUDDragonAISpell = Dragon->HasSpell(UDDragonAISpell);