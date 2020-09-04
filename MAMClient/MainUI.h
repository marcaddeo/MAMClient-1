#pragma once

#include "Widget.h"

class CWindow;
class CGauge;
class CLabel;
class CButton;
class CMainUI : public CWidget {
public:
	CMainUI(CWindow* w);
	~CMainUI();

	void CreateWidgets();
	void Load();
	void Reload() { Load(); }
	void ReloadAssets();
	void Render();
	void HandleEvent(SDL_Event& e);
	void Step();

private:
	std::string getPetElementType();
	CGauge* addGauge(std::string name, int x, int y, int w, int h, std::string foreground, std::string background, bool verticle);

	bool IsAssetPixel(Asset asset, Uint32 *pixels, SDL_Point point);	

private:
	Asset PlayerFrame;
	Asset PetFrame;
	//const int PetFrameWidth = 150;
	//const int PetFrameHeight = 60;
	//Uint32 *playerPixels = nullptr, *petPixels = nullptr;

public: //Gauges
	void setPlayerHealthGauge(int val);
	void setPlayerHealthGauge(int val, int max);
	void shiftPlayerHealthGauge(int val);
	void adjustPlayerHealthGauge(int val);
	void setPlayerManaGauge(int val);
	void setPlayerManaGauge(int val, int max);
	void shiftPlayerManaGauge(int val);
	void adjustPlayerManaGauge(int val);
	void setPlayerExpGauge(int val);
	void setPlayerExpGauge(int val, int max);
	void shiftPlayerExpGauge(int val);
	void adjustPlayerExpGauge(int val);
	void setPetHealthGauge(int val);
	void setPetHealthGauge(int val, int max);
	void shiftPetHealthGauge(int val);
	void adjustPetHealthGauge(int val);
	void setPetExpGauge(int val);
	void setPetExpGauge(int val, int max);
	void shiftPetExpGauge(int val);
	void adjustPetExpGauge(int val);

public: //Labels
	void updatePlayerLevel();
	void updatePetLevel();

private:
	CWindow* window;
	CGauge *gaugePlayerHealth, *gaugePlayerMana, *gaugePlayerExp;
	CGauge *gaugePetHealth, *gaugePetExp;
	CButton *btnBattle, *btnBattleRepeat, *btnBattleConfig;
	CButton *btnPlayer, *btnPet, *btnInventory, *btnWuxing;
	CLabel *lblPlayerLevel, *lblPetLevel;

private:
	void btnBattle_Click(SDL_Event& e);
	void btnBattleRepeat_Toggle(SDL_Event& e);
	void btnBattleConfig_Click(SDL_Event& e);

	void btnPlayer_Click(SDL_Event& e);
	void btnPet_Click(SDL_Event& e);
	void btnInventory_Click(SDL_Event& e);
	void btnWuxing_Click(SDL_Event& e);

	bool MouseOverPlayer, MouseOverPet;
	bool btnPlayer_Down = false;
	bool btnPet_Down = false;
};