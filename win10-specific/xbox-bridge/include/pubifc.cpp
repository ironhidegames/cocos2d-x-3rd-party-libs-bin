#include "XBoxBridgeDI.h"
using namespace Windows::Security::ExchangeActiveSyncProvisioning;

KRXB_C_DLL int xbox_create_request_auth() {
	int reqId = Services::getAuthService()->authenticate();
	OutputDebugStringA(("Starting authentication with request: "+std::to_string(reqId)+ "\n").c_str());
	return reqId;
}

KRXB_C_DLL int xbox_get_status() {
	bool isAuth = Services::getAuthService()->isSignedIn();
	//OutputDebugStringA(("Signed in status: " + std::to_string(isAuth)+ "\n").c_str());
	if (isAuth)
		return 1;
	else
		return -1;
}

KRXB_C_DLL int xbox_get_gamertag(char* buf, int bufSize) {
	if (!Services::getAuthService()->isSignedIn()) { //If I'm not signed in length of the gamertag is 0
		return 0;
	}
	const string_t& gt = Services::getAuthService()->getPlayer()->gamertag();
	auto utf8 = utility::conversions::to_utf8string(gt);
	return utf8.copy(buf, bufSize);
}

KRXB_C_DLL int xbox_get_request_status(int reqId) {
	int status = Services::getRequestService()->get(reqId);
	OutputDebugStringA(("Request " + std::to_string(reqId) + " status: " + std::to_string(status) + "\n").c_str());
	return status;
}

KRXB_C_DLL void xbox_delete_request(int reqId) {
	OutputDebugStringA(("Deleting request: " + std::to_string(reqId)+"\n").c_str());
	Services::getRequestService()->del(reqId);
}

KRXB_C_DLL const char* xbox_get_cached_payload(int reqId) {
	auto payload = Services::getRequestService()->getPayload(reqId);
        if (payload != nullptr)
            OutputDebugStringA(("Obtained payload for request: " + std::to_string(reqId) + " is: " + utility::conversions::to_utf8string(payload) + "\n").c_str());
        else
            OutputDebugStringA(("Request payload not found for id: " + std::to_string(reqId) + "\n").c_str());
	return payload;
}

KRXB_C_DLL int xbox_create_request_ach_list() {
	int reqId = Services::getAchievementsService()->getAchievementsRequest(XBoxAchievementRequestFilter());
	OutputDebugStringA(("Getting achievements with request " + std::to_string(reqId) + "\n").c_str());
	return reqId;
}

KRXB_C_DLL int xbox_create_request_ach_get(char* achievementId) {
	int reqId = Services::getAchievementsService()->getAchievementRequest(achievementId);
	OutputDebugStringA(("Getting achievement: " + utility::conversions::to_utf8string(achievementId) + " with request " + std::to_string(reqId) + "\n").c_str());
	return reqId;
}

KRXB_C_DLL int xbox_create_request_ach_update(char* achievementId, int percentComplete) {
	int reqId = Services::getAchievementsService()->updateAchievement(achievementId, percentComplete);
	OutputDebugStringA(("Updating achievement: " + utility::conversions::to_utf8string(achievementId) +" with request " + std::to_string(reqId) + "\n").c_str());
	return reqId;
}

KRXB_C_DLL const char* xbox_get_locale() {
	LPWSTR loc = new TCHAR[LOCALE_NAME_MAX_LENGTH];
	if (GetUserDefaultLocaleName(loc, LOCALE_NAME_MAX_LENGTH)) {
		auto locale = utility::conversions::to_utf8string(loc);
		OutputDebugStringA(("Locale got: " + locale + "\n").c_str());
		return locale.c_str();
	}
	OutputDebugStringA("Failed getting locale\n");
	return NULL;
}

KRXB_C_DLL int xbox_create_request_cloud_sync(const char* names_list) {
	auto reqId = Services::getStorageService()->initializeAndSync(std::string(names_list));
	OutputDebugStringA(("Sync storage for slots: " + utility::conversions::to_utf8string(names_list) + " with request " + std::to_string(reqId) + "\n").c_str());
	return reqId;
}

KRXB_C_DLL int xbox_create_request_cloud_push(const char* name, const char* data) {
	auto reqId = Services::getStorageService()->setFile(name, data);
	OutputDebugStringA(("Save with request " + std::to_string(reqId) + "\n").c_str());
	return reqId;
}

KRXB_C_DLL int xbox_create_request_cloud_delete(const char* name) {
	auto reqId = Services::getStorageService()->delFile(name);
	OutputDebugStringA(("Delete with request " + std::to_string(reqId) + "\n").c_str());
	return reqId;
}

KRXB_C_DLL const char* xbox_cloud_get_cached(const char* name) {
	OutputDebugStringA(("Getting cached file: " + utility::conversions::to_utf8string(name) + "\n").c_str());
	return Services::getStorageService()->getFile(name);
}

KRXB_C_DLL double xbox_cloud_get_last_sync(void) {
	return Services::getStorageService()->getLastSync();
}

KRXB_C_DLL void xbox_focus_changed(bool active) {
	if (active) 
		Services::getStorageService()->resume();
	else
		Services::getStorageService()->suspend();
}
