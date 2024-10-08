#pragma once

#include "Window.h"

enum LoginState {
	lsNone,
	lsStart,
	lsConnectAccount,
	lsLogin,
	lsLoginResponse,
	lsLoginFail,
	lsLoginSuccess,
	lsConnectGame,
	lsGameResponse,
	lsGameFail,
	lsGameSuccess,
	lsLoggedIn
};

class pLoginResponse;
class CMessageForm;
class CField;

class CLoginForm : public CWindow {
public:
	CLoginForm();
	~CLoginForm();

	void handleEvent(SDL_Event &e);
	void step();

private: //Login Handling
	void handleLogin();
	void closeMessage();
	void promptError(std::string errorText);
public: void loginSuccess();

private:
	LoginState loginState = LoginState::lsNone;
	bool loginResponseReceived{false};
	int loginAccount{0}, loginSeed{0};
	std::string loginMessage;
	CMessageForm* messageForm{nullptr};

private: //Event handlers
	void lblNewAccount_Click(SDL_Event& e);
	void fldAccount_Submit(SDL_Event &e);
	void fldAccount_OnTab(SDL_Event &e);
	void fldPassword_Submit(SDL_Event &e);
	void btnOk_Click(SDL_Event& e);
	void btnCancel_Click(SDL_Event& e);

	CField* fldAccount;
	CField* fldPassword;
};