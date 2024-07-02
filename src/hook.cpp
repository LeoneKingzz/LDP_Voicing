#include "hook.h"

namespace hooks
{
    RE::TESForm;
    void on_animation_event::GetEquippedShout(RE::Actor *actor, bool SpellFire){
        auto limboshout = actor->GetActorRuntimeData().selectedPower;

        if (limboshout && limboshout->Is(RE::FormType::Shout))
        {
            bool IsActorTypeDragon = actor->HasKeywordString("DragonVoiceKey");
            bool IsActorTypePaarthurnax = actor->HasKeywordString("MasterPaarthurnaxKey");
            bool IsActorTypeAlduin = actor->HasKeywordString("AlduinUnitedKey");
            bool IsActorTypeOdahviing = actor->HasKeywordString("OdahviingKey");

            if (!(IsActorTypeDragon || IsActorTypeAlduin || IsActorTypeOdahviing || IsActorTypePaarthurnax)){
                logger::info("failed");
                return;
            }else{
                logger::info("DragonCheck passed");
            }

            std::string_view Lsht = (clib_util::editorID::get_editorID(limboshout)).data();
            logger::info("Shout {} EDID {}"sv, actor->GetName(), Lsht);
            if (hash(Lsht.data(), Lsht.size())){
                logger::info("DATA {} SIZE {}"sv, Lsht.data(), Lsht.size());
                logger::info("HASH {} ACTOR {}"sv, hash(Lsht.data(), Lsht.size()), actor->GetName());
            }else{
                logger::info("failed proccess");
            }
            switch (hash(Lsht.data(), Lsht.size()))
            {
            case "ks_DragonFlameWaveShoutALDUIN"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin04BTorShul")->As<RE::BGSSoundDescriptorForm>());
                } else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin04AYol")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "005SummonShouts"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon07BQothZaam")->As<RE::BGSSoundDescriptorForm>());
                } else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon07ADiil")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "005StormShoutsDECIEVE"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon15BLoSah")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon15AFiik")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "005SahloknirStormShout"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon15BSahDiin")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon15AFiik")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "005StormShoutsBLOOD"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon30BSosHaas")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon30ALun")->As<RE::BGSSoundDescriptorForm>());
                }
                break;
            
            case "005UniqueBreathShouts"_h:
            case "005UniqueBreathShoutsALDUIN"_h:
            case "005UniqueBreathShoutsODAH"_h:
            case "005UniqueBreathShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon27BYolRon")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin24BYolRon")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing18BYolRon")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax17BYolRon")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon27AVah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin24AVah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing18AVah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax17AVah")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "005VolleyBreathShouts"_h:
            case "005VolleyBreathShoutsALDUIN"_h:
            case "005VolleyBreathShoutsODAH"_h:
            case "005VolleyBreathShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon26BDaIiz")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin23BDaIiz")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing17BDaIiz")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax16BDaIiz")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon26AGron")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin23AGron")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing17AGron")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax16AGron")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "PaarthurnaxElementalFury"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax14BGrahDun")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax14ASu")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "PaarthurnaxWhirlwindTempest"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax13BNahKest")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax13AWuld")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "ks_DragonMoonBlast"_h:
            case "ks_DragonMoonBlastALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon25BJiidViin")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin22BJiidViin")->As<RE::BGSSoundDescriptorForm>());
                    }

                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon25ASos")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin22ASos")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "005StormShoutsFROST"_h:
            case "zz005AlduinFroststorms"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon24BSoDaan")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin21BSoDaan")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon24AJiid")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin21AJiid")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "zz05AlduinFirestorms"_h:
            case "dunCGDragonStormCallShout"_h:
            case "MQ206AlduinFirestormShout"_h:
            case "005StormShoutsFIRE"_h:
                logger::info("successful hash case switch");
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon20BToorNah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        logger::info("ending shout");
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin08BToorNah")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon20AGaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        logger::info("Starting shout");
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin08AGaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "zz005DevourSoul_Alduin"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin19BDiiDu")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin19AZiiLos")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "005StormShoutsSHOCK"_h:
            case "zz005AlduinLightningstorms"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon17BBahQo")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin18BBahQo")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon17AStrun")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin18AStrun")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "ks_DragonCycloneShout"_h:
            case "ks_DragonCycloneShoutALDUIN"_h:
            case "ks_DragonCycloneShoutODAH"_h:
            case "ks_DragonCycloneShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon19BGaarNos")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin15BGaarNos")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing15BGaarNos")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax12BGaarNos")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon19AVen")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin15AVen")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing15AVen")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax12AVen")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "ks_DragonDrainVitalityShout"_h:
            case "ks_DragonDrainVitalityShoutALDUIN"_h:
            case "ks_DragonDrainVitalityShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon08BLahHaas")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin14BLahHaas")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing14BLahHaas")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon08AGaan")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin14AGaan")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing14AGaan")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "KS_DLC2BendWillShout_Alduin"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin11BHahDov")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin11AGol")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "Serio_EDR_GravityBlastShout"_h:
            case "Serio_EDR_GravityBlastShoutALDUIN"_h:
            case "Serio_EDR_GravityBlastShoutODAH"_h:
            case "Serio_EDR_GravityBlastShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon12BFusGaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin11BFusGaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing11BFusGaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax10BFusGaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon12AGol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin11AGol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing11AGol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax10AGol")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "Serio_EDR_BackfireRecoilShout"_h:
            case "Serio_EDR_BackfireRecoilShoutALDUIN"_h:
            case "Serio_EDR_BackfireRecoilShoutODAH"_h:
            case "Serio_EDR_BackfireRecoilShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon13BFiikZun")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin10BFiikZun")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing10BFiikZun")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax09BFiikZun")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon13AQah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin10AQah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing10AQah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax09AQah")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "ks_DragonBecomeEtherealShout"_h:
            case "ks_DragonBecomeEtherealShoutALDUIN"_h:
            case "ks_DragonBecomeEtherealShoutODAH"_h:
            case "ks_DragonBecomeEtherealShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon18BZiiGron")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin07BZiiGron")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing07BZiiGron")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax07BZiiGron")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon18AFeim")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin07AFeim")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing07AFeim")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax07AFeim")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "MQ101DragonUnrelentingForceShout"_h:
            case "Serio_EDR_UnrelentingForceShout"_h:
            case "Serio_EDR_UnrelentingForceShoutALDUIN"_h:
            case "Serio_EDR_UnrelentingForceShoutODAH"_h:
            case "Serio_EDR_UnrelentingForceShoutPAAR"_h:
            case "ks_DragonUnrelentingForceAreaShout"_h:
            case "ks_DragonUnrelentingForceAreaShoutALDUIN"_h:
            case "ks_DragonUnrelentingForceAreaShoutODAH"_h:
            case "ks_DragonUnrelentingForceAreaShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon01BRoDah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin01BRoDah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing01BRoDah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax01BRoDah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon01AFus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin01AFus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing01AFus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax01AFus")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "ks_DragonDismayAreaShout"_h:
            case "ks_DragonDismayAreaShoutALDUIN"_h:
            case "ks_DragonDismayAreaShoutODAH"_h:
            case "ks_DragonDismayAreaShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon02BRuMaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin02BRuMaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing02BRuMaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax02BRuMaar")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon02AFaas")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin02AFaas")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing02AFaas")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax02AFaas")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "ks_DragonIceFormShout"_h:
            case "ks_DragonIceFormShoutALDUIN"_h:
            case "ks_DragonIceFormShoutODAH"_h:
            case "ks_DragonIceFormShoutPAAR"_h:
            case "005FrostForgetShouts"_h:
            case "005FrostForgetShoutsALDUIN"_h:
            case "005FrostForgetShoutsODAH"_h:
            case "005FrostForgetShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon03BSlenNus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin03BSlenNus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing03BSlenNus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax03BSlenNus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon03AIiz")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin03AIiz")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing03AIiz")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax03AIiz")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "ks_DragonDisarmShout"_h:
            case "ks_DragonDisarmShoutALDUIN"_h:
            case "ks_DragonDisarmShoutODAH"_h:
            case "ks_DragonDisarmShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon04BHaalViik")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin04BHaalViik")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing04BHaalViik")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax04BHaalViik")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon04AZun")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin04AZun")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing04AZun")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax04AZun")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "L_DragonFireBreathShoutDRAGON"_h:
            case "L_DragonFireBreathShoutALDUIN2"_h:
            case "L_DragonFireBreathShoutODAH"_h:
            case "L_DragonFireBreathShoutPAAR"_h:
            case "L_DragonFireBallShout"_h:
            case "L_DragonFireBallShoutALDUIN2"_h:
            case "L_DragonFireBallShoutODAH"_h:
            case "L_DragonFireBallShoutPAAR"_h:
            case "ks_DragonFlameWaveShout"_h:
            case "ks_DragonFlameWaveShoutODAH"_h:
            case "ks_DragonFlameWaveShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon05BTorShul")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin05BTorShul")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing05BToorShul")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax05BTorShul")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon05AYol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin05AYol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing05AYol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax05AYol")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "L_DragonFrostBreathShout"_h:
            case "L_DragonFrostBreathShoutALDUIN"_h:
            case "L_DragonFrostBreathShoutODAH"_h:
            case "L_DragonFrostBreathShoutPAAR"_h:
            case "L_DragonFrostIceStormShout"_h:
            case "L_DragonFrostIceStormShoutALDUIN"_h:
            case "L_DragonFrostIceStormShoutODAH"_h:
            case "L_DragonFrostIceStormShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon06BKrahDiin")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin06BKrahDiin")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing06BKrahDiin")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax06BKrahDiin")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon06AFo")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin06AFo")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing06AFo")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax06AFo")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "Serio_EDR_ChainSuppressionShout"_h:
            case "Serio_EDR_ChainSuppressionShoutALDUIN"_h:
            case "Serio_EDR_ChainSuppressionShoutODAH"_h:
            case "Serio_EDR_ChainSuppressionShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon11BLahMey")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin09BLahMey")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing09BLahMey")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax08BLahMey")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon11AHah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin09AHah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing09AHah")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax08AHah")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "Serio_EDR_StaggerSpikesShout"_h:
            case "Serio_EDR_StaggerSpikesShoutALDUIN"_h:
            case "Serio_EDR_StaggerSpikesShoutODAH"_h:
            case "Serio_EDR_StaggerSpikesShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon10BKriidGol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin12BKriidGol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing12BKriidGol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax11BKriidGol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon10AKlo")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin12AKlo")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing12AKlo")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax11AKlo")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "ks_DragonMarkedforDeathShout"_h:
            case "ks_DragonMarkedforDeathShoutALDUIN"_h:
            case "ks_DragonMarkedforDeathShoutODAH"_h:
            case "Serio_EDR_MarkedForDeathShout"_h:
            case "Serio_EDR_MarkedForDeathShoutALDUIN"_h:
            case "Serio_EDR_MarkedForDeathShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon14BLunAus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin13BLunAus")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing13BLunAus")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon14AKrii")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin13AKrii")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing13AKrii")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "L_DragonShockBreathShout"_h:
            case "L_DragonShockBreathShoutALDUIN2"_h:
            case "L_DragonShockBallShout"_h:
            case "L_DragonShockBallShoutALDUIN2"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon16BAgSlen")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin16BAgSlen")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon16ASov")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin16ASov")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "ks_DragonSoulTearShout"_h:
            case "ks_DragonSoulTearShout_ALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon09BVaazZol")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin17BVaazZol")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon09ARii")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin17ARii")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "Serio_EDR_DevourMoonLightShout"_h:
            case "Serio_EDR_DevourMoonLightShoutALDUIN"_h:
            case "Serio_EDR_DevourMoonLightShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon21BKunShaan")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin20BKunShaan")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing16BKunShaan")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon21ADu")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin20ADu")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing16ADu")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "005StormShoutsALLD"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon22BVaazDaan")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon22AVul")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "Serio_EDR_StormBarrageShout"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon23BVulVu")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon23ASul")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "PaarthurnaxClearSkies"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax15BVahKoor")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax15ALok")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "PaarthurnaxBattleFury"_h:
                if (SpellFire){
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax19BVurShaan")->As<RE::BGSSoundDescriptorForm>());
                }else{
                    util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax19AMid")->As<RE::BGSSoundDescriptorForm>());
                }
                break;

            case "005ShockForgetShouts"_h:
            case "005ShockForgetShoutsALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon28BBahRein")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin25BBahRein")->As<RE::BGSSoundDescriptorForm>());
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon28AMul")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin25AMul")->As<RE::BGSSoundDescriptorForm>());
                    }
                }
                break;

            case "005FireForgetShouts"_h:
            case "005FireForgetShoutsALDUIN"_h:
            case "005FireForgetShoutsODAH"_h:
            case "005FireForgetShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon29BVolAg")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin26BVolAg")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing19BVolAg")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax18BVolAg")->As<RE::BGSSoundDescriptorForm>());
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragon29AToor")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonAlduin26AToor")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonOdahviing19AToor")->As<RE::BGSSoundDescriptorForm>());
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, RE::TESForm::LookupByEditorID("VOCShoutDragonPaarthurnax18AToor")->As<RE::BGSSoundDescriptorForm>());
                    }
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
            logger::info("anim_event BeginCastVoice");

            break;

        case "Voice_SpellFire_Event"_h:

            GetEquippedShout(actor, true);
            logger::info("anim_event Voice_SpellFire_Event");

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