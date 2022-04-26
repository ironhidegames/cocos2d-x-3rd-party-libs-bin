#pragma once

#ifndef XBOX_ONE_AUTH_SERVICE
#define XBOX_ONE_AUTH_SERVICE

#include "Base.h"
#include <ppltasks.h>
#include "xsapi/types.h"
#include "xsapi/services.h"
#ifdef USE_REQUEST_SERVICE
#include "RequestService.h"
#endif
namespace kalio {
	namespace xbox_bridge {
		namespace auth {

			class KRXB_DLL XBoxAuthService {
			private:
#ifdef USE_REQUEST_SERVICE
				std::shared_ptr<kalio::xbox_bridge::requests::RequestService> requestService = nullptr;
#endif // USE_REQUEST_SERVICE
				std::shared_ptr<xbox::services::system::xbox_live_user> player;
				std::shared_ptr<xbox::services::xbox_live_context> xboxLiveContext;
				bool signedIn;
			public:
#ifndef USE_REQUEST_SERVICE
				XBoxAuthService() {
					this->player = nullptr;
					this->xboxLiveContext = nullptr;
					this->signedIn = false;
				}
#endif
#ifdef USE_REQUEST_SERVICE
				XBoxAuthService(std::shared_ptr<kalio::xbox_bridge::requests::RequestService> requestService) {
					this->player = nullptr;
					this->xboxLiveContext = nullptr;
					this->signedIn = false;
					this->requestService = requestService;
					if (requestService == nullptr) {
						throw std::exception("Request service required");
					}
				}
#endif // USE_REQUEST_SERVICE
				int authenticate();
				int authenticate(int_callback_t callback);

				void logOffHandler();
				bool isSignedIn() const;

				std::shared_ptr<xbox::services::system::xbox_live_user> getPlayer() const;
				std::shared_ptr<xbox::services::xbox_live_context> getContext() const;

			};

			template class KRXB_DLL std::shared_ptr<XBoxAuthService>;
		}
	}
}

#endif // !XBOX_ONE_AUTH_SERVICE



