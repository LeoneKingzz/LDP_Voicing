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
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin04BTorShul"));
                } else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin04AYol"));
                }
                break;

            case "005SummonShouts"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon07BQothZaam"));
                } else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon07ADiil"));
                }
                break;

            case "005StormShoutsDECIEVE"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon15BLoSah"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon15AFiik"));
                }
                break;

            case "005SahloknirStormShout"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon15BSahDiin"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon15AFiik"));
                }
                break;

            case "005StormShoutsBLOOD"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon30BSosHaas"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon30ALun"));
                }
                break;
            
            case "005UniqueBreathShouts"_h:
            case "005UniqueBreathShoutsALDUIN"_h:
            case "005UniqueBreathShoutsODAH"_h:
            case "005UniqueBreathShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon27BYolRon"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin24BYolRon"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing18BYolRon"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax17BYolRon"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon27AVah"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin24AVah"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing18AVah"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax17AVah"));
                    }
                }
                break;

            case "005VolleyBreathShouts"_h:
            case "005VolleyBreathShoutsALDUIN"_h:
            case "005VolleyBreathShoutsODAH"_h:
            case "005VolleyBreathShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon26BDaIiz"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin23BDaIiz"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing17BDaIiz"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax16BDaIiz"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon26AGron"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin23AGron"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing17AGron"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax16AGron"));
                    }
                }
                break;

            case "PaarthurnaxElementalFury"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax14BGrahDun"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax14ASu"));
                }
                break;

            case "PaarthurnaxWhirlwindTempest"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax13BNahKest"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax13AWuld"));
                }
                break;

            case "ks_DragonMoonBlast"_h:
            case "ks_DragonMoonBlastALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon25BJiidViin"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin22BJiidViin"));
                    }

                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon25ASos"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin22ASos"));
                    }
                }
                break;

            case "005StormShoutsFROST"_h:
            case "zz005AlduinFroststorms"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon24BSoDaan"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin21BSoDaan"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon24AJiid"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin21AJiid"));
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
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon20BToorNah"));
                    }
                    if (IsActorTypeAlduin){
                        logger::info("ending shout");
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin08BToorNah"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon20AGaar"));
                    }
                    if (IsActorTypeAlduin){
                        logger::info("Starting shout");
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin08AGaar"));
                    }
                }
                break;

                RE::BShkbAnimationGraph;

            case "zz005DevourSoul_Alduin"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin19BDiiDu"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin19AZiiLos"));
                }
                break;

            case "005StormShoutsSHOCK"_h:
            case "zz005AlduinLightningstorms"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon17BBahQo"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin18BBahQo"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon17AStrun"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin18AStrun"));
                    }
                }
                break;

            case "ks_DragonCycloneShout"_h:
            case "ks_DragonCycloneShoutALDUIN"_h:
            case "ks_DragonCycloneShoutODAH"_h:
            case "ks_DragonCycloneShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon19BGaarNos"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin15BGaarNos"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing15BGaarNos"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax12BGaarNos"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon19AVen"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin15AVen"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing15AVen"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax12AVen"));
                    }
                }
                break;

            case "ks_DragonDrainVitalityShout"_h:
            case "ks_DragonDrainVitalityShoutALDUIN"_h:
            case "ks_DragonDrainVitalityShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon08BLahHaas"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin14BLahHaas"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing14BLahHaas"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon08AGaan"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin14AGaan"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing14AGaan"));
                    }
                }
                break;

            case "KS_DLC2BendWillShout_Alduin"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin11BHahDov"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin11AGol"));
                }
                break;

            case "Serio_EDR_GravityBlastShout"_h:
            case "Serio_EDR_GravityBlastShoutALDUIN"_h:
            case "Serio_EDR_GravityBlastShoutODAH"_h:
            case "Serio_EDR_GravityBlastShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon12BFusGaar"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin11BFusGaar"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing11BFusGaar"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax10BFusGaar"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon12AGol"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin11AGol"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing11AGol"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax10AGol"));
                    }
                }
                break;

            case "Serio_EDR_BackfireRecoilShout"_h:
            case "Serio_EDR_BackfireRecoilShoutALDUIN"_h:
            case "Serio_EDR_BackfireRecoilShoutODAH"_h:
            case "Serio_EDR_BackfireRecoilShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon13BFiikZun"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin10BFiikZun"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing10BFiikZun"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax09BFiikZun"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon13AQah"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin10AQah"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing10AQah"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax09AQah"));
                    }
                }
                break;

            case "ks_DragonBecomeEtherealShout"_h:
            case "ks_DragonBecomeEtherealShoutALDUIN"_h:
            case "ks_DragonBecomeEtherealShoutODAH"_h:
            case "ks_DragonBecomeEtherealShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon18BZiiGron"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin07BZiiGron"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing07BZiiGron"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax07BZiiGron"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon18AFeim"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin07AFeim"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing07AFeim"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax07AFeim"));
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
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon01BRoDah"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin01BRoDah"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing01BRoDah"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax01BRoDah"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon01AFus"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin01AFus"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing01AFus"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax01AFus"));
                    }
                }
                break;

            case "ks_DragonDismayAreaShout"_h:
            case "ks_DragonDismayAreaShoutALDUIN"_h:
            case "ks_DragonDismayAreaShoutODAH"_h:
            case "ks_DragonDismayAreaShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon02BRuMaar"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin02BRuMaar"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing02BRuMaar"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax02BRuMaar"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon02AFaas"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin02AFaas"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing02AFaas"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax02AFaas"));
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
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon03BSlenNus"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin03BSlenNus"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing03BSlenNus"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax03BSlenNus"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon03AIiz"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin03AIiz"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing03AIiz"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax03AIiz"));
                    }
                }
                break;

            case "ks_DragonDisarmShout"_h:
            case "ks_DragonDisarmShoutALDUIN"_h:
            case "ks_DragonDisarmShoutODAH"_h:
            case "ks_DragonDisarmShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon04BHaalViik"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin04BHaalViik"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing04BHaalViik"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax04BHaalViik"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon04AZun"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin04AZun"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing04AZun"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax04AZun"));
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
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon05BTorShul"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin05BTorShul"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing05BToorShul"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax05BTorShul"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon05AYol"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin05AYol"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing05AYol"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax05AYol"));
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
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon06BKrahDiin"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin06BKrahDiin"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing06BKrahDiin"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax06BKrahDiin"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon06AFo"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin06AFo"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing06AFo"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax06AFo"));
                    }
                }
                break;

            case "Serio_EDR_ChainSuppressionShout"_h:
            case "Serio_EDR_ChainSuppressionShoutALDUIN"_h:
            case "Serio_EDR_ChainSuppressionShoutODAH"_h:
            case "Serio_EDR_ChainSuppressionShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon11BLahMey"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin09BLahMey"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing09BLahMey"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax08BLahMey"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon11AHah"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin09AHah"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing09AHah"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax08AHah"));
                    }
                }
                break;

            case "Serio_EDR_StaggerSpikesShout"_h:
            case "Serio_EDR_StaggerSpikesShoutALDUIN"_h:
            case "Serio_EDR_StaggerSpikesShoutODAH"_h:
            case "Serio_EDR_StaggerSpikesShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon10BKriidGol"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin12BKriidGol"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing12BKriidGol"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax11BKriidGol"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon10AKlo"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin12AKlo"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing12AKlo"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax11AKlo"));
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
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon14BLunAus"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin13BLunAus"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing13BLunAus"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon14AKrii"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin13AKrii"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing13AKrii"));
                    }
                }
                break;

            case "L_DragonShockBreathShout"_h:
            case "L_DragonShockBreathShoutALDUIN2"_h:
            case "L_DragonShockBallShout"_h:
            case "L_DragonShockBallShoutALDUIN2"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon16BAgSlen"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin16BAgSlen"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon16ASov"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin16ASov"));
                    }
                }
                break;

            case "ks_DragonSoulTearShout"_h:
            case "ks_DragonSoulTearShout_ALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon09BVaazZol"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin17BVaazZol"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon09ARii"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin17ARii"));
                    }
                }
                break;

            case "Serio_EDR_DevourMoonLightShout"_h:
            case "Serio_EDR_DevourMoonLightShoutALDUIN"_h:
            case "Serio_EDR_DevourMoonLightShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon21BKunShaan"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin20BKunShaan"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing16BKunShaan"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon21ADu"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin20ADu"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing16ADu"));
                    }
                }
                break;

            case "005StormShoutsALLD"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon22BVaazDaan"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon22AVul"));
                }
                break;

            case "Serio_EDR_StormBarrageShout"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon23BVulVu"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon23ASul"));
                }
                break;

            case "PaarthurnaxClearSkies"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax15BVahKoor"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax15ALok"));
                }
                break;

            case "PaarthurnaxBattleFury"_h:
                if (SpellFire){
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax19BVurShaan"));
                }else{
                    actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax19AMid"));
                }
                break;

            case "005ShockForgetShouts"_h:
            case "005ShockForgetShoutsALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon28BBahRein"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin25BBahRein"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon28AMul"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin25AMul"));
                    }
                }
                break;

            case "005FireForgetShouts"_h:
            case "005FireForgetShoutsALDUIN"_h:
            case "005FireForgetShoutsODAH"_h:
            case "005FireForgetShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon29BVolAg"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin26BVolAg"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing19BVolAg"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax18BVolAg"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragon29AToor"));
                    }
                    if (IsActorTypeAlduin){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonAlduin26AToor"));
                    }
                    if (IsActorTypeOdahviing){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonOdahviing19AToor"));
                    }
                    if (IsActorTypePaarthurnax){
                        actor->NotifyAnimationGraph(("SoundPlay.VOCShoutDragonPaarthurnax18AToor"));
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