// Licensed under the MIT License.

#include "Menu.hpp"
#include "Drawing.h"
#include "../common.hpp"
#include "../Utils/Config/settings_manger.h"
#include <algorithm>
#include <chrono>
#include <thread>
#include "../Utils/Saving/States/Misc/disables_default_states.h"

void playSoundFrontend(const char* name, const char* soundset)
{
	AUDIO::_STOP_SOUND_WITH_NAME(name, soundset);
	AUDIO::PLAY_SOUND_FRONTEND(name, soundset, true, 0);
}

enum eUIFeedChannel
{
	kFeedChannel_Invalid = 0,
	kFeedChannel_Help = 1,
	kFeedChannel_Location = 2,
	kFeedChannel_Objective = 3,
	kFeedChannel_Subtitle = 4,
	kFeedChannel_Ticker = 5,
	kFeedChannel_Toast = 6,
	kFeedChannel_Isolated = 7,
	kFeedChannel_Transportation = 8,
	kFeedChannel_MissionName = 9,
	kFeedChannel_ReticleMessage = 10,
	kFeedChannel_Shards = 11,
	kFeedChannel_ScoretimerMessage = 12,
	kFeedChannel_VoiceChat = 13,
	kFeedChannel_Count = 14,
};

void CNativeMenu::Update()
{
	CheckInput();
	HandleInput();
	DisableCommonInputs();

	if (m_IsOpen)
	{
		if (m_CurrentSubmenu == nullptr) return;

		UIFEED::UI_FEED_CLEAR_CHANNEL(kFeedChannel_Help, true, true);
		UIFEED::UI_FEED_CLEAR_CHANNEL(kFeedChannel_Toast, true, true);
		UIFEED::UI_FEED_CLEAR_CHANNEL(kFeedChannel_Location, true, true);

		Drawing::DrawMenu();

		for (int i = 0; i < m_CurrentSubmenu->GetNumberOfOptions(); i++) {
			Option* option = m_CurrentSubmenu->GetOption(i);
			if (option != nullptr) {
				Drawing::DrawOption(option);
			}
			else {
				PRINT_ERROR("Option index ", i, " in submenu ", (int)m_CurrentSubmenuID, " is null");
			}
		}

		if (disables_disable_radar_when_menu_is_open_bool) {
			MAP::DISPLAY_RADAR(false); 
		}
		else {
			MAP::DISPLAY_RADAR(true); 
		}
	}

	if (m_CurrentSubmenu != nullptr) {
		m_CurrentSubmenuID = m_CurrentSubmenu->ID;
	}

	// HUD::_UI_PROMPT_SET_VISIBLE(m_SelectPrompt, m_IsOpen);
	// HUD::_UI_PROMPT_SET_ENABLED(m_SelectPrompt, m_IsOpen);
	// HUD::_UI_PROMPT_SET_VISIBLE(m_BackPrompt, m_IsOpen);
	// HUD::_UI_PROMPT_SET_ENABLED(m_BackPrompt, m_IsOpen);
}

void CNativeMenu::SetEnabled(bool bEnabled, bool bPlaySounds)
{
	m_IsOpen = bEnabled;

	if (bPlaySounds) {
		if (m_IsOpen) {
			playSoundFrontend("MENU_ENTER", "HUD_PLAYER_MENU");
		}
		else {
			playSoundFrontend("MENU_CLOSE", "HUD_PLAYER_MENU");
		}
	}

	if (m_IsOpen) {
		MAP::DISPLAY_RADAR(false);
	}
	else {
		MAP::DISPLAY_RADAR(true);
	}
}

void CNativeMenu::CheckInput()
{
	m_ControlIndex = PAD::IS_USING_KEYBOARD_AND_MOUSE(0) ? 0 : 2;

	std::string openKey = SettingsManager::keyboardOpenKey;
	std::string numpadOpenKey = SettingsManager::numpadOpenKey;
	std::string controllerOpenKey = SettingsManager::controllerOpenKey;

	std::cout << "Loaded Open Key: " << openKey << std::endl;
	std::cout << "Loaded Numpad Open Key: " << numpadOpenKey << std::endl;
	std::cout << "Loaded Controller Open Key: " << controllerOpenKey << std::endl;

	int openKeyCode = SettingsManager::GetVirtualKeyFromString(openKey);
	int numpadOpenKeyCode = SettingsManager::GetVirtualKeyFromString(numpadOpenKey);
	int controllerComboCode = SettingsManager::GetVirtualKeyFromString(controllerOpenKey);


	m_OpenKeyPressed =
		(openKeyCode > 0 && IsKeyJustUp(openKeyCode)) ||
		(numpadOpenKeyCode > 0 && IsKeyJustUp(numpadOpenKeyCode)) ||
		(controllerComboCode != 0 && PAD::IS_CONTROL_PRESSED(m_ControlIndex, INPUT_FRONTEND_RB) &&
			PAD::IS_CONTROL_PRESSED(m_ControlIndex, controllerComboCode));

	m_EnterKeyPressed = IsKeyJustUp(VK_NUMPAD5) ||
		PAD::IS_CONTROL_JUST_RELEASED(m_ControlIndex, INPUT_GAME_MENU_ACCEPT);

	m_BackKeyPressed = IsKeyJustUp(VK_NUMPAD0) ||
		PAD::IS_CONTROL_JUST_RELEASED(m_ControlIndex, INPUT_GAME_MENU_CANCEL);

	m_UpKeyPressed = IsKeyJustUp(VK_NUMPAD8) ||
		PAD::IS_CONTROL_JUST_PRESSED(m_ControlIndex, INPUT_GAME_MENU_UP);

	m_DownKeyPressed = IsKeyJustUp(VK_NUMPAD2) ||
		PAD::IS_CONTROL_JUST_PRESSED(m_ControlIndex, INPUT_GAME_MENU_DOWN);

	m_LeftKeyPressed = IsKeyJustUp(VK_NUMPAD4) ||
		PAD::IS_DISABLED_CONTROL_JUST_PRESSED(m_ControlIndex, INPUT_GAME_MENU_LEFT);

	m_RightKeyPressed = IsKeyJustUp(VK_NUMPAD6) ||
		PAD::IS_DISABLED_CONTROL_JUST_PRESSED(m_ControlIndex, INPUT_GAME_MENU_RIGHT);
}

int SettingsManager::GetVirtualKeyFromString(const std::string& key) {
	std::string lowerKey = key;
	std::transform(lowerKey.begin(), lowerKey.end(), lowerKey.begin(), ::tolower);

	// Handle common keys:
	if (lowerKey == "f1") return VK_F1;
	if (lowerKey == "f2") return VK_F2;
	if (lowerKey == "f3") return VK_F3;
	if (lowerKey == "f4") return VK_F4;
	if (lowerKey == "f5") return VK_F5;
	if (lowerKey == "f6") return VK_F6;
	if (lowerKey == "f7") return VK_F7;
	if (lowerKey == "f8") return VK_F8;
	if (lowerKey == "f9") return VK_F9;
	if (lowerKey == "f10") return VK_F10;
	if (lowerKey == "f11") return VK_F11;
	if (lowerKey == "f12") return VK_F12;
	if (lowerKey == "insert") return VK_INSERT;
	if (lowerKey == "home") return VK_HOME;
	if (lowerKey == "pageup") return VK_PRIOR;
	if (lowerKey == "pagedown") return VK_NEXT;
	if (lowerKey == "end") return VK_END;
	if (lowerKey == "delete") return VK_DELETE;

	// Handle numpad Keys:
	if (lowerKey == "/") return VK_DIVIDE;
	if (lowerKey == "*") return VK_MULTIPLY;
	if (lowerKey == "-") return VK_SUBTRACT;
	if (lowerKey == "+") return VK_ADD;
	if (lowerKey == ".") return VK_DECIMAL;

	// Handle PlayStation Controller keys:
	if (lowerKey == "r2+square") return INPUT_FRONTEND_X;
	if (lowerKey == "r2+x") return INPUT_FRONTEND_ACCEPT;

	// Handle Xbox Controller keys:
	if (lowerKey == "rb+x") return INPUT_FRONTEND_X;
	if (lowerKey == "rb+a") return INPUT_FRONTEND_ACCEPT;

	return 0; 
}


void CNativeMenu::HandleEnterPressed()
{
	Option* option = GetSelectedOption();
	if (option == nullptr) {
		std::cout << "No option selected for Enter!" << std::endl;
		return;
	}

	if (option->IsRegularOption) {
		option->Execute();
	}
	else if (option->IsBoolOption) {
		BoolOption* boolOption = option->As<BoolOption*>();
		if (boolOption->pBoolPointer != nullptr) {
			*boolOption->pBoolPointer ^= TRUE;
		}
		else {
			std::cerr << "Invalid boolean pointer for option index " << m_SelectionIndex << std::endl;
		}
		boolOption->Execute();
	}
	else if (option->IsVectorOption) {
		VectorOption* vecOption = option->As<VectorOption*>();
		vecOption->ExecuteVectorFunction(false, true);
	}
	else if (option->IsSubmenuOption) {
		SubmenuOption* submenuOption = option->As<SubmenuOption*>();
		if (DoesSubmenuExist(submenuOption->SubmenuID)) {
			m_PreviousSubmenus.push_back(m_CurrentSubmenu->ID);
			m_LastSubmenuSelections[m_CurrentSubmenu->ID] = m_SelectionIndex;
			m_CurrentSubmenu = &m_SubmenusMap[submenuOption->SubmenuID];
			m_SelectionIndex = 0;
		}
		else {
			std::cerr << "Submenu ID " << (int)submenuOption->SubmenuID << " doesn't exist!" << std::endl;
		}
	}

	playSoundFrontend("SELECT", "HUD_SHOP_SOUNDSET");
}

void CNativeMenu::HandleBackPressed()
{
	if (m_CurrentSubmenu->ID <= eSubmenuID::Submenu_main) {
		playSoundFrontend("BACK", "HUD_SHOP_SOUNDSET");
		SetEnabled(false);
		return;
	}

	if (!m_PreviousSubmenus.empty()) {
		m_CurrentSubmenu = &m_SubmenusMap[m_PreviousSubmenus.back()];
		m_PreviousSubmenus.pop_back();
		m_SelectionIndex = m_LastSubmenuSelections[m_CurrentSubmenu->ID];
	}
	else {
		m_CurrentSubmenu = &m_SubmenusMap[eSubmenuID::Submenu_main];
		m_SelectionIndex = m_LastSubmenuSelections[eSubmenuID::Submenu_main];
	}

	playSoundFrontend("BACK", "HUD_SHOP_SOUNDSET");
}

void CNativeMenu::HandleUpKeyPressed()
{
	if (GetSelectedOption() == nullptr) return;
	int numOptions = m_CurrentSubmenu->GetNumberOfOptions();

	if (IsKeyDownLong('X')) { 
		m_SelectionIndex -= 10;
		if (m_SelectionIndex < 0) {
			m_SelectionIndex = 0;
		}
	}
	else {
		m_SelectionIndex--;
	}

	if (m_SelectionIndex < 0) { m_SelectionIndex = numOptions - 1; }
	if (GetSelectedOption()->IsEmptyOption) { m_SelectionIndex--; }
	if (m_SelectionIndex < 0) { m_SelectionIndex = numOptions - 1; }

	playSoundFrontend("NAV_UP", "Ledger_Sounds");
}

void CNativeMenu::HandleDownKeyPressed()
{
	if (GetSelectedOption() == nullptr) return;
	int numOptions = m_CurrentSubmenu->GetNumberOfOptions();

	if (IsKeyDownLong('X')) {
		m_SelectionIndex += 10;
		if (m_SelectionIndex > numOptions - 1) {
			m_SelectionIndex = numOptions - 1;
		}
	}
	else {
		m_SelectionIndex++;
	}

	if (m_SelectionIndex > numOptions - 1) { m_SelectionIndex = 0; }
	if (GetSelectedOption()->IsEmptyOption) { m_SelectionIndex++; }
	if (m_SelectionIndex > numOptions - 1) { m_SelectionIndex = 0; }

	playSoundFrontend("NAV_DOWN", "Ledger_Sounds");
}



void CNativeMenu::HandleLeftKeyPressed()
{
	Option* option = GetSelectedOption();
	if (option == nullptr) return;

	if (option->IsVectorOption) {
		option->As<VectorOption*>()->ExecuteVectorFunction(true, false);
		playSoundFrontend("NAV_LEFT", "PAUSE_MENU_SOUNDSET");
	}
}

void CNativeMenu::HandleRightKeyPressed()
{
	Option* option = GetSelectedOption();
	if (option == nullptr) return;

	if (option->IsVectorOption) {
		option->As<VectorOption*>()->ExecuteVectorFunction(false, true);
		playSoundFrontend("NAV_RIGHT", "PAUSE_MENU_SOUNDSET");
	}
}

void CNativeMenu::HandleInput()
{
	static bool wasOpenButtonPressed = false;

	if (m_OpenKeyPressed) {
		if (!wasOpenButtonPressed) {
			m_IsOpen = !m_IsOpen;
			SetEnabled(m_IsOpen);
			wasOpenButtonPressed = true;
		}
	}
	else {
		wasOpenButtonPressed = false;
	}

	if (m_IsOpen) {
		if (m_EnterKeyPressed) {
			HandleEnterPressed();
		}
		if (m_BackKeyPressed) {
			HandleBackPressed();
		}
		if (m_UpKeyPressed) {
			HandleUpKeyPressed();
		}
		if (m_DownKeyPressed) {
			HandleDownKeyPressed();
		}
		if (m_LeftKeyPressed) {
			HandleLeftKeyPressed();
		}
		if (m_RightKeyPressed) {
			HandleRightKeyPressed();
		}
	}
}


void CNativeMenu::DisableCommonInputs()
{
	if (m_IsOpen) {
		if (disables_disable_horse_whistle_on_controller_bool && m_ControlIndex == INPUT_GROUP_GAMEPAD) {
			*getGlobalPtr(1900383 + 316) = 2; // Disables horse whistling this frame, seems to be safe and stable?
			PAD::DISABLE_CONTROL_ACTION(INPUT_GROUP_GAMEPAD, INPUT_WHISTLE, false);
			PAD::DISABLE_CONTROL_ACTION(INPUT_GROUP_GAMEPAD, INPUT_WHISTLE_HORSEBACK, false);
		}

		PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_SELECT_RADAR_MODE, false);
		//PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_REVEAL_HUD, false);
		PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_PLAYER_MENU, false);
		PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_OPEN_JOURNAL, false);
		//PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_OPEN_SATCHEL_MENU, false);
		//PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_OPEN_SATCHEL_HORSE_MENU, false);
		//PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_OPEN_CRAFTING_MENU, false);
		//PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_OPEN_EMOTE_WHEEL, false);
		//PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_OPEN_WHEEL_MENU, false);
		PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_EXPAND_RADAR, false);
		PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_INTERACTION_MENU, false);
		//PAD::DISABLE_CONTROL_ACTION(m_ControlIndex, INPUT_HUD_SPECIAL, false);
		
		
	}
}

void CNativeMenu::RegisterUIPrompts()
{
	auto reg = [](Prompt &_prompt, const char* text, Hash control) 
	{ 
		_prompt = HUD::_UI_PROMPT_REGISTER_BEGIN();
		HUD::_UI_PROMPT_SET_CONTROL_ACTION(_prompt, control);
		HUD::_UI_PROMPT_SET_PRIORITY(_prompt, 2); // PP_High
		HUD::_UI_PROMPT_SET_TEXT(_prompt, MISC::VAR_STRING(10, "LITERAL_STRING", text));
		HUD::_UI_PROMPT_SET_STANDARD_MODE(_prompt, true);
		// Allows multiple prompts of the same type to be shown (kPromptAttrib_ManualResolved) (?)
		HUD::_UI_PROMPT_SET_ATTRIBUTE(_prompt, 34, true);
		HUD::_UI_PROMPT_REGISTER_END(_prompt);

		HUD::_UI_PROMPT_SET_VISIBLE(_prompt, false);
		HUD::_UI_PROMPT_SET_ENABLED(_prompt, false);
	};

	if (m_SelectPrompt == NULL)
		reg(m_SelectPrompt, "Select", INPUT_GAME_MENU_ACCEPT);

	if (m_BackPrompt == NULL)
		reg(m_BackPrompt, "Back", INPUT_GAME_MENU_CANCEL);
}