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

            std::string_view Lsht = (clib_util::editorID::get_editorID(limboshout)).c_str();
            logger::info("Shout {} EDID {}"sv, actor->GetName(), Lsht);
            if (hash(Lsht.data(), Lsht.size())){
                logger::info("successful process");
            }else{
                logger::info("failed proccess");
            }
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
            case "zz005AlduinFroststorms"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon24BSoDaan"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin21BSoDaan"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon24AJiid"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin21AJiid"));
                    }
                }
                break;

            case "zz05AlduinFirestorms"_h:
            case "dunCGDragonStormCallShout"_h:
            case "MQ206AlduinFirestormShout"_h:
            case "005StormShoutsFIRE"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon20BToorNah"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin08BToorNah"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon20AGaar"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin08AGaar"));
                    }
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
            case "zz005AlduinLightningstorms"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon17BBahQo"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin18BBahQo"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon17AStrun"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin18AStrun"));
                    }
                }
                break;

            case "ks_DragonCycloneShout"_h:
            case "ks_DragonCycloneShoutALDUIN"_h:
            case "ks_DragonCycloneShoutODAH"_h:
            case "ks_DragonCycloneShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon19BGaarNos"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin15BGaarNos"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing15BGaarNos"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax12BGaarNos"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon19AVen"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin15AVen"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing15AVen"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax12AVen"));
                    }
                }
                break;

            case "ks_DragonDrainVitalityShout"_h:
            case "ks_DragonDrainVitalityShoutALDUIN"_h:
            case "ks_DragonDrainVitalityShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon08BLahHaas"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin14BLahHaas"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing14BLahHaas"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon08AGaan"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin14AGaan"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing14AGaan"));
                    }
                }
                break;

            case "KS_DLC2BendWillShout_Alduin"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin11BHahDov"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin11AGol"));
                }
                break;

            case "Serio_EDR_GravityBlastShout"_h:
            case "Serio_EDR_GravityBlastShoutALDUIN"_h:
            case "Serio_EDR_GravityBlastShoutODAH"_h:
            case "Serio_EDR_GravityBlastShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon12BFusGaar"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin11BFusGaar"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing11BFusGaar"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax10BFusGaar"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon12AGol"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin11AGol"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing11AGol"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax10AGol"));
                    }
                }
                break;

            case "Serio_EDR_BackfireRecoilShout"_h:
            case "Serio_EDR_BackfireRecoilShoutALDUIN"_h:
            case "Serio_EDR_BackfireRecoilShoutODAH"_h:
            case "Serio_EDR_BackfireRecoilShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon13BFiikZun"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin10BFiikZun"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing10BFiikZun"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax09BFiikZun"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon13AQah"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin10AQah"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing10AQah"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax09AQah"));
                    }
                }
                break;

            case "ks_DragonBecomeEtherealShout"_h:
            case "ks_DragonBecomeEtherealShoutALDUIN"_h:
            case "ks_DragonBecomeEtherealShoutODAH"_h:
            case "ks_DragonBecomeEtherealShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon18BZiiGron"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin07BZiiGron"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing07BZiiGron"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax07BZiiGron"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon18AFeim"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin07AFeim"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing07AFeim"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax07AFeim"));
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
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon01BRoDah"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin01BRoDah"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing01BRoDah"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax01BRoDah"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon01AFus"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin01AFus"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing01AFus"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax01AFus"));
                    }
                }
                break;

            case "ks_DragonDismayAreaShout"_h:
            case "ks_DragonDismayAreaShoutALDUIN"_h:
            case "ks_DragonDismayAreaShoutODAH"_h:
            case "ks_DragonDismayAreaShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon02BRuMaar"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin02BRuMaar"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing02BRuMaar"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax02BRuMaar"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon02AFaas"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin02AFaas"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing02AFaas"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax02AFaas"));
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
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon03BSlenNus"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin03BSlenNus"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing03BSlenNus"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax03BSlenNus"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon03AIiz"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin03AIiz"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing03AIiz"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax03AIiz"));
                    }
                }
                break;

            case "ks_DragonDisarmShout"_h:
            case "ks_DragonDisarmShoutALDUIN"_h:
            case "ks_DragonDisarmShoutODAH"_h:
            case "ks_DragonDisarmShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon04BHaalViik"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin04BHaalViik"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing04BHaalViik"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax04BHaalViik"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon04AZun"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin04AZun"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing04AZun"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax04AZun"));
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
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon05BTorShul"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin05BTorShul"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing05BToorShul"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax05BTorShul"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon05AYol"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin05AYol"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing05AYol"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax05AYol"));
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
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon06BKrahDiin"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin06BKrahDiin"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing06BKrahDiin"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax06BKrahDiin"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon06AFo"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin06AFo"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing06AFo"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax06AFo"));
                    }
                }
                break;

            case "Serio_EDR_ChainSuppressionShout"_h:
            case "Serio_EDR_ChainSuppressionShoutALDUIN"_h:
            case "Serio_EDR_ChainSuppressionShoutODAH"_h:
            case "Serio_EDR_ChainSuppressionShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon11BLahMey"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin09BLahMey"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing09BLahMey"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax08BLahMey"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon11AHah"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin09AHah"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing09AHah"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax08AHah"));
                    }
                }
                break;

            case "Serio_EDR_StaggerSpikesShout"_h:
            case "Serio_EDR_StaggerSpikesShoutALDUIN"_h:
            case "Serio_EDR_StaggerSpikesShoutODAH"_h:
            case "Serio_EDR_StaggerSpikesShoutPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon10BKriidGol"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin12BKriidGol"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing12BKriidGol"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax11BKriidGol"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon10AKlo"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin12AKlo"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing12AKlo"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax11AKlo"));
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
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon14BLunAus"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin13BLunAus"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing13BLunAus"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon14AKrii"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin13AKrii"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing13AKrii"));
                    }
                }
                break;

            case "L_DragonShockBreathShout"_h:
            case "L_DragonShockBreathShoutALDUIN2"_h:
            case "L_DragonShockBallShout"_h:
            case "L_DragonShockBallShoutALDUIN2"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon16BAgSlen"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin16BAgSlen"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon16ASov"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin16ASov"));
                    }
                }
                break;

            case "ks_DragonSoulTearShout"_h:
            case "ks_DragonSoulTearShout_ALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon09BVaazZol"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin17BVaazZol"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon09ARii"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin17ARii"));
                    }
                }
                break;

            case "Serio_EDR_DevourMoonLightShout"_h:
            case "Serio_EDR_DevourMoonLightShoutALDUIN"_h:
            case "Serio_EDR_DevourMoonLightShoutODAH"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon21BKunShaan"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin20BKunShaan"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing16BKunShaan"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon21ADu"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin20ADu"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing16ADu"));
                    }
                }
                break;

            case "005StormShoutsALLD"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon22BVaazDaan"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon22AVul"));
                }
                break;

            case "Serio_EDR_StormBarrageShout"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon23BVulVu"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragon23ASul"));
                }
                break;

            case "PaarthurnaxClearSkies"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax15BVahKoor"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax15ALok"));
                }
                break;

            case "PaarthurnaxBattleFury"_h:
                if (SpellFire){
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax19BVurShaan"));
                }else{
                    util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax19AMid"));
                }
                break;

            case "005ShockForgetShouts"_h:
            case "005ShockForgetShoutsALDUIN"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon28BBahRein"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin25BBahRein"));
                    }
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon28AMul"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin25AMul"));
                    }
                }
                break;

            case "005FireForgetShouts"_h:
            case "005FireForgetShoutsALDUIN"_h:
            case "005FireForgetShoutsODAH"_h:
            case "005FireForgetShoutsPAAR"_h:
                if (SpellFire){
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon29BVolAg"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin26BVolAg"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing19BVolAg"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax18BVolAg"));
                    }
                    
                }else{
                    if (IsActorTypeDragon){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragon29AToor"));
                    }
                    if (IsActorTypeAlduin){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonAlduin26AToor"));
                    }
                    if (IsActorTypeOdahviing){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonOdahviing19AToor"));
                    }
                    if (IsActorTypePaarthurnax){
                        util::playSound(actor, util::GetSoundRecord("VOCShoutDragonPaarthurnax18AToor"));
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
        bool IsActorTypeDragon = actor->HasKeywordString("DragonVoiceKey");
        bool IsActorTypePaarthurnax = actor->HasKeywordString("MasterPaarthurnaxKey");
        bool IsActorTypeAlduin = actor->HasKeywordString("AlduinUnitedKey");
        bool IsActorTypeOdahviing = actor->HasKeywordString("OdahviingKey");
        switch (hash(eventTag.data(), eventTag.size())) {
        case "BeginCastVoice"_h:

            if (IsActorTypeDragon || IsActorTypeAlduin || IsActorTypeOdahviing || IsActorTypePaarthurnax){
                GetEquippedShout(actor);
                logger::info("anim_event BeginCastVoice");
            }

            break;

        case "Voice_SpellFire_Event"_h:

            if (IsActorTypeDragon || IsActorTypeAlduin || IsActorTypeOdahviing || IsActorTypePaarthurnax){
                GetEquippedShout(actor, true);
                logger::info("anim_event Voice_SpellFire_Event");
            }

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