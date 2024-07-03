#include "hook.h"

namespace hooks
{
    RE::TESForm;
    void on_animation_event::GetEquippedShout(RE::Actor *actor, bool SpellFire){
        auto limboshout = actor->GetActorRuntimeData().selectedPower;

        if (limboshout && limboshout->Is(RE::FormType::Shout))
        {
            auto data = RE::TESDataHandler::GetSingleton();
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
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin04BTorShul", "Dragons shout with voice - KS2 Patch.esp")));
                } else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin04AYol", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "005SummonShouts"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon07BQothZaam", "Dragons shout with voice - KS2 Patch.esp")));
                } else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon07ADiil", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "005StormShoutsDECIEVE"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon15BLoSah", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon15AFiik", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "005SahloknirStormShout"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon15BSahDiin", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon15AFiik", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "005StormShoutsBLOOD"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon30BSosHaas", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon30ALun", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;
            
            case "005UniqueBreathShouts"_h:
            case "005UniqueBreathShoutsALDUIN"_h:
            case "005UniqueBreathShoutsODAH"_h:
            case "005UniqueBreathShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon27BYolRon", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin24BYolRon", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing18BYolRon", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax17BYolRon", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon27AVah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin24AVah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing18AVah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax17AVah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "005VolleyBreathShouts"_h:
            case "005VolleyBreathShoutsALDUIN"_h:
            case "005VolleyBreathShoutsODAH"_h:
            case "005VolleyBreathShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon26BDaIiz", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin23BDaIiz", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing17BDaIiz", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax16BDaIiz", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon26AGron", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin23AGron", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing17AGron", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax16AGron", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "PaarthurnaxElementalFury"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax14BGrahDun", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax14ASu", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "PaarthurnaxWhirlwindTempest"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax13BNahKest", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax13AWuld", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "ks_DragonMoonBlast"_h:
            case "ks_DragonMoonBlastALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon25BJiidViin", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin22BJiidViin", "Dragons shout with voice - KS2 Patch.esp")));
                    }

                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon25ASos", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin22ASos", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "005StormShoutsFROST"_h:
            case "zz005AlduinFroststorms"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon24BSoDaan", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin21BSoDaan", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon24AJiid", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin21AJiid", "Dragons shout with voice - KS2 Patch.esp")));
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
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon20BToorNah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        logger::info("ending shout");
                        util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(0x8A8, "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon20AGaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        logger::info("Starting shout");
                        util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(0x8A7, "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

                RE::BShkbAnimationGraph;

            case "zz005DevourSoul_Alduin"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin19BDiiDu", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin19AZiiLos", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "005StormShoutsSHOCK"_h:
            case "zz005AlduinLightningstorms"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon17BBahQo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin18BBahQo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon17AStrun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin18AStrun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "ks_DragonCycloneShout"_h:
            case "ks_DragonCycloneShoutALDUIN"_h:
            case "ks_DragonCycloneShoutODAH"_h:
            case "ks_DragonCycloneShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon19BGaarNos", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin15BGaarNos", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing15BGaarNos", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax12BGaarNos", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon19AVen", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin15AVen", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing15AVen", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax12AVen", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "ks_DragonDrainVitalityShout"_h:
            case "ks_DragonDrainVitalityShoutALDUIN"_h:
            case "ks_DragonDrainVitalityShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon08BLahHaas", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin14BLahHaas", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing14BLahHaas", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon08AGaan", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin14AGaan", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing14AGaan", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "KS_DLC2BendWillShout_Alduin"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin11BHahDov", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin11AGol", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "Serio_EDR_GravityBlastShout"_h:
            case "Serio_EDR_GravityBlastShoutALDUIN"_h:
            case "Serio_EDR_GravityBlastShoutODAH"_h:
            case "Serio_EDR_GravityBlastShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon12BFusGaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin11BFusGaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing11BFusGaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax10BFusGaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon12AGol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin11AGol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing11AGol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax10AGol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "Serio_EDR_BackfireRecoilShout"_h:
            case "Serio_EDR_BackfireRecoilShoutALDUIN"_h:
            case "Serio_EDR_BackfireRecoilShoutODAH"_h:
            case "Serio_EDR_BackfireRecoilShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon13BFiikZun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin10BFiikZun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing10BFiikZun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax09BFiikZun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon13AQah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin10AQah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing10AQah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax09AQah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "ks_DragonBecomeEtherealShout"_h:
            case "ks_DragonBecomeEtherealShoutALDUIN"_h:
            case "ks_DragonBecomeEtherealShoutODAH"_h:
            case "ks_DragonBecomeEtherealShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon18BZiiGron", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin07BZiiGron", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing07BZiiGron", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax07BZiiGron", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon18AFeim", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin07AFeim", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing07AFeim", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax07AFeim", "Dragons shout with voice - KS2 Patch.esp")));
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
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon01BRoDah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin01BRoDah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing01BRoDah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax01BRoDah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon01AFus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin01AFus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing01AFus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax01AFus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "ks_DragonDismayAreaShout"_h:
            case "ks_DragonDismayAreaShoutALDUIN"_h:
            case "ks_DragonDismayAreaShoutODAH"_h:
            case "ks_DragonDismayAreaShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon02BRuMaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin02BRuMaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing02BRuMaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax02BRuMaar", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon02AFaas", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin02AFaas", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing02AFaas", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax02AFaas", "Dragons shout with voice - KS2 Patch.esp")));
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
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon03BSlenNus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin03BSlenNus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing03BSlenNus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax03BSlenNus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon03AIiz", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin03AIiz", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing03AIiz", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax03AIiz", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "ks_DragonDisarmShout"_h:
            case "ks_DragonDisarmShoutALDUIN"_h:
            case "ks_DragonDisarmShoutODAH"_h:
            case "ks_DragonDisarmShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon04BHaalViik", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin04BHaalViik", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing04BHaalViik", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax04BHaalViik", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon04AZun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin04AZun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing04AZun", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax04AZun", "Dragons shout with voice - KS2 Patch.esp")));
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
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon05BTorShul", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin05BTorShul", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing05BToorShul", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax05BTorShul", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon05AYol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin05AYol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing05AYol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax05AYol", "Dragons shout with voice - KS2 Patch.esp")));
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
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon06BKrahDiin", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin06BKrahDiin", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing06BKrahDiin", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax06BKrahDiin", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon06AFo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin06AFo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing06AFo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax06AFo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "Serio_EDR_ChainSuppressionShout"_h:
            case "Serio_EDR_ChainSuppressionShoutALDUIN"_h:
            case "Serio_EDR_ChainSuppressionShoutODAH"_h:
            case "Serio_EDR_ChainSuppressionShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon11BLahMey", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin09BLahMey", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing09BLahMey", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax08BLahMey", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon11AHah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin09AHah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing09AHah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax08AHah", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "Serio_EDR_StaggerSpikesShout"_h:
            case "Serio_EDR_StaggerSpikesShoutALDUIN"_h:
            case "Serio_EDR_StaggerSpikesShoutODAH"_h:
            case "Serio_EDR_StaggerSpikesShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon10BKriidGol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin12BKriidGol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing12BKriidGol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax11BKriidGol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon10AKlo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin12AKlo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing12AKlo", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax11AKlo", "Dragons shout with voice - KS2 Patch.esp")));
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
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon14BLunAus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin13BLunAus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing13BLunAus", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon14AKrii", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin13AKrii", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing13AKrii", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "L_DragonShockBreathShout"_h:
            case "L_DragonShockBreathShoutALDUIN2"_h:
            case "L_DragonShockBallShout"_h:
            case "L_DragonShockBallShoutALDUIN2"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon16BAgSlen", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin16BAgSlen", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon16ASov", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin16ASov", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "ks_DragonSoulTearShout"_h:
            case "ks_DragonSoulTearShout_ALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon09BVaazZol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin17BVaazZol", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon09ARii", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin17ARii", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "Serio_EDR_DevourMoonLightShout"_h:
            case "Serio_EDR_DevourMoonLightShoutALDUIN"_h:
            case "Serio_EDR_DevourMoonLightShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon21BKunShaan", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin20BKunShaan", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing16BKunShaan", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon21ADu", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin20ADu", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing16ADu", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "005StormShoutsALLD"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon22BVaazDaan", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon22AVul", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "Serio_EDR_StormBarrageShout"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon23BVulVu", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon23ASul", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "PaarthurnaxClearSkies"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax15BVahKoor", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax15ALok", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "PaarthurnaxBattleFury"_h:
                if (SpellFire){
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax19BVurShaan", "Dragons shout with voice - KS2 Patch.esp")));
                }else{
                    //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax19AMid", "Dragons shout with voice - KS2 Patch.esp")));
                }
                break;

            case "005ShockForgetShouts"_h:
            case "005ShockForgetShoutsALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon28BBahRein", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin25BBahRein", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon28AMul", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin25AMul", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                }
                break;

            case "005FireForgetShouts"_h:
            case "005FireForgetShoutsALDUIN"_h:
            case "005FireForgetShoutsODAH"_h:
            case "005FireForgetShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon29BVolAg", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin26BVolAg", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing19BVolAg", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax18BVolAg", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragon29AToor", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeAlduin){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonAlduin26AToor", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypeOdahviing){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonOdahviing19AToor", "Dragons shout with voice - KS2 Patch.esp")));
                    }
                    if (IsActorTypePaarthurnax){
                        //util::playSound(actor,(data->LookupForm<RE::BGSSoundDescriptorForm>("VOCShoutDragonPaarthurnax18AToor", "Dragons shout with voice - KS2 Patch.esp")));
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

// uti/l::playSound(actor, RE::TESForm::LookupByEditorID<RE::TESForm>

//Actors\\Character