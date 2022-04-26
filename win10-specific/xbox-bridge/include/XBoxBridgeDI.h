#pragma once

#ifndef XBOX_DI_MANAGEMENT
#define XBOX_DI_MANAGEMENT

#include "Base.h"
#include "XBoxAuthService.h"
#include "XBoxAchievementsService.h"
#include "XBoxLeaderboardsService.h"
#include "XBoxStorageService.h"
#include <memory>

#ifdef USE_REQUEST_SERVICE
#include "RequestService.h"
using namespace kalio::xbox_bridge::requests;
#endif
using namespace kalio::xbox_bridge::auth;
using namespace kalio::xbox_bridge::achievements;
using namespace kalio::xbox_bridge::leaderboards;
using namespace kalio::xbox_bridge::storage;

class KRXB_DLL Services {

public:
	static std::shared_ptr<XBoxAuthService> getAuthService();
	static std::shared_ptr<XBoxAchievementsService> getAchievementsService();
	static std::shared_ptr<XBoxLeaderboardsService> getLeaderboardsService();
	static std::shared_ptr<XBoxStorageService> getStorageService();

#ifdef USE_REQUEST_SERVICE
public:
	static std::shared_ptr<RequestService> getRequestService();
#endif // USE_REQUEST_SERVICE
};

#endif // !XBOX_DI_MANAGEMENT


