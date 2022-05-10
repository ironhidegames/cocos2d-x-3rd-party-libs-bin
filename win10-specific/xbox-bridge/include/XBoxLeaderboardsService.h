#pragma once

#ifndef XBOX_ONE_LEADERBOARD_SERVICE
#define XBOX_ONE_LEADERBOARD_SERVICE

#include "Base.h"
#include "xsapi/services.h"
#ifdef USE_REQUEST_SERVICE
#include "RequestService.h"
#endif
#include "XBoxAuthService.h"

namespace kalio {
	namespace xbox_bridge {
		namespace leaderboards {

			typedef KRXB_DLL void (*leaderboards_callback_t)(std::vector<xbox::services::leaderboard::leaderboard_row>);

			class KRXB_DLL XBoxLeaderboardsService {
			private:
				std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService = nullptr;

				std::shared_ptr<xbox::services::stats::manager::stats_manager> statManager = nullptr;
				bool initialized = false;
				int getReqId = -1;
				int setReqId = -1;

#ifdef USE_REQUEST_SERVICE
				std::shared_ptr<kalio::xbox_bridge::requests::RequestService> requestService = nullptr;
#endif // USE_REQUEST_SERVICE
				int_callback_t initCallback = nullptr;
				leaderboards_callback_t getCallback = nullptr;
				int_callback_t setCallback = nullptr;

				utility::string_t protectBoardId(const char* boardId, bool forGet) const;
				void consolidateObtained(xbox::services::stats::manager::leaderboard_result_event_args* args);
			public:
#ifndef USE_REQUEST_SERVICE
				XBoxLeaderboardsService(std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService) {
					if (authService == nullptr) {
						throw std::exception("Auth service required");
					}
					this->authService = authService;
				}
#endif
#ifdef USE_REQUEST_SERVICE
				XBoxLeaderboardsService(std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService, 
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
				void setup();
				void setup(int_callback_t initCallback, leaderboards_callback_t getCallback, int_callback_t setCallback);
				void tick();
				bool isInitialized() const;
				int submitScore(const char* boardId, int score);
				int getScore(const char* boardId);
			};

			template class KRXB_DLL std::shared_ptr<XBoxLeaderboardsService>;
		}
	}
}

#endif // !XBOX_ONE_LEADERBOARD_SERVICE

