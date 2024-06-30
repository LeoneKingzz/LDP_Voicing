#include "hook.h"

namespace hooks
{
	void on_animation_event::ProcessEvent(RE::BSTEventSink<RE::BSAnimationGraphEvent>* a_sink, RE::BSAnimationGraphEvent* a_event, RE::BSTEventSource<RE::BSAnimationGraphEvent>* a_eventSource)
	{
		if (!a_event->holder) {
			return;
		}
		std::string_view eventTag = a_event->tag.data();
		RE::Actor* actor = const_cast<RE::TESObjectREFR*>(a_event->holder)->As<RE::Actor>();
		switch (hash(eventTag.data(), eventTag.size())) {
        case "BeginCastVoice"_h:

            break;

        case "Voice_SpellFire_Event"_h:

            RE::BGSSoundDescriptorForm *a_desc;

            util::playSound(actor,a_desc);

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