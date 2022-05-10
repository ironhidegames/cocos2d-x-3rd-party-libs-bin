#pragma once

#ifndef XBOX_ONE_ACHIEVEMENTS_SERVICE
#define XBOX_ONE_ACHIEVEMENTS_SERVICE

#include "Base.h"
#include "xsapi/services.h"
#ifdef USE_REQUEST_SERVICE
#include "RequestService.h"
#endif
#include "XBoxAuthService.h"

namespace kalio {
	namespace xbox_bridge {
		namespace achievements {

			typedef KRXB_DLL void (*achievement_callback_t)(xbox::services::achievements::achievement);
			typedef KRXB_DLL void (*achievements_callback_t)(std::vector<xbox::services::achievements::achievement>);

			typedef struct KRXB_DLL XBoxAchievementRequestFilter {
				// achievement_type filter: All mean to get Persistent and Challenge achievements
				xbox::services::achievements::achievement_type achievementType = xbox::services::achievements::achievement_type::all;
				// false for all possible achievements (locked & unlocked).
				bool unlockedOnly = false;
				// achievement_order_by filter: Default means no particular order
				xbox::services::achievements::achievement_order_by orderBy = xbox::services::achievements::achievement_order_by::default_order;
				// The number of achievement items to skip
				int offset = 0;
				// maximum amount of achievements to get per request
				int limit = 9999;												
			};

			class KRXB_DLL XBoxAchievementsService {
			private:
				std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService = nullptr;
#ifdef USE_REQUEST_SERVICE
				std::shared_ptr<kalio::xbox_bridge::requests::RequestService> requestService = nullptr;
#endif // USE_REQUEST_SERVICE
				utility::string_t protectAchievementId(const char* achievementId, const int reqId) const;
				void call(achievement_callback_t callback, xbox::services::achievements::achievement achievement);
				void call(achievements_callback_t callback, std::vector<xbox::services::achievements::achievement> achievements);
				xbox::services::achievements::achievement getAchievement(const char* achievementId, int reqId, achievement_callback_t callback);
				std::vector<xbox::services::achievements::achievement> getAchievements(const XBoxAchievementRequestFilter filter, int reqId, achievements_callback_t callback);
				int updateAchievement(const char* achievementId, int percentComplete, int_callback_t callback);
			public:
#ifndef USE_REQUEST_SERVICE
				XBoxAchievementsService(std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService) {
					if (authService == nullptr) {
						throw std::exception("Auth service required");
					}
					this->authService = authService;
				}
#endif
#ifdef USE_REQUEST_SERVICE
				XBoxAchievementsService(std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService, 
						std::shared_ptr<kalio::xbox_bridge::requests::RequestService> requestService) {
					this->authService = authService;
					if (authService == nullptr) {
						throw std::exception("Auth service required");
					}
					this->requestService = requestService;
					if (requestService == nullptr) {
						throw std::exception("Request service required");
					}
				}
#endif // USE_REQUEST_SERVICE
				xbox::services::achievements::achievement getAchievement(const char* achievementId);
				void getAchievement(const char* achievementId, achievement_callback_t callback);
				int getAchievementRequest(const char* achievementId);
				std::vector<xbox::services::achievements::achievement> getAchievements(const XBoxAchievementRequestFilter filter);
				void getAchievements(const XBoxAchievementRequestFilter filter, achievements_callback_t callback);
				int getAchievementsRequest(const XBoxAchievementRequestFilter filter);
				int updateAchievement(const char* achievementId, int percentComplete);
			};

			template class KRXB_DLL std::shared_ptr<XBoxAchievementsService>;
		}
	}
}

#endif // !XBOX_ONE_ACHIEVEMENTS_SERVICE