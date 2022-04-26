#pragma once

#ifndef XBOX_ONE_REQUEST_SERVICE
#define XBOX_ONE_REQUEST_SERVICE

#include "Base.h"
#include <mutex>
#include <set>
#include <shared_mutex>
#include <unordered_map>

namespace kalio {
	namespace xbox_bridge {
		namespace requests {

			typedef enum {
				KREQ_STATUS_PENDING = -2,
				KREQ_STATUS_FAILED = -1,
				KREQ_STATUS_OK = 0,
				KREQ_STATUS_WORKING = 1
			} KRXB_DLL KRequestStatus;

			// Request Types
			typedef enum {
				KREQ_TYPE_ACH_LOAD = 101,   // achievements
				KREQ_TYPE_ACH_REPORT,
				KREQ_TYPE_ACH_RESET,
				KREQ_TYPE_HTTPS_REQUEST = 201,    // https requests
				KREQ_TYPE_CLOUD_SYNC_SLOTS = 301,    // cloud save
				KREQ_TYPE_CLOUD_PUSH_SLOT = 302,
				KREQ_TYPE_RC_SYNC = 401,    // remote config
				KREQ_TYPE_YODO1_REWARDED_SHOW = 501,    // yodo ads
				KREQ_TYPE_YODO1_INTERSTITIAL_SHOW,
				KRequestTypeSize
			} KRXB_DLL KRequestType;

			// Request Errors
			typedef enum {
				KREQ_ERR_SIGNIN = 9010, //sign in
				KREQ_ERR_NO_AVAILABLE_LOCAL_USER,
				KREQ_ERR_ACH_LOAD = 9101,   // achievements
				KREQ_ERR_ACH_REPORT,
				KREQ_ERR_ACH_RESET,
				KREQ_ERR_HTTPS_REQUEST = 9201,   // https requests
				KREQ_ERR_CLOUD_NO_DEFAULT_STORE = 9301,   // cloud save
				KREQ_ERR_CLOUD_NOT_INITIALIZED,
				KREQ_ERR_CLOUD_LOAD_GENERAL,
				KREQ_ERR_CLOUD_SAVE_GENERAL,
				KREQ_ERR_RC_SYNC = 9401,   // remote config
				KREQ_ERR_YODO1_REWARDED_FAIL = 9501,   // yodo ads
				KREQ_ERR_YODO1_REWARDED_EARLY_CLOSE,
				KREQ_ERR_YODO1_INTERSTITIAL_FAIL,
				KREQ_ERR_LEADERBOARDS = 9601, //leaderboards

				KRequestErrorTypeSize
			} KRXB_DLL KRequestErrorType;

			class KRXB_DLL RequestService {
			private:
				
				mutable std::shared_mutex mutex;
				std::unordered_map<int, int> requestMap;
				std::unordered_map<int, std::string> payloadMap;
			public:
				RequestService() {};

				int set(int status);
				void upd(int id, int status);
				int get(int id);
				void del(int id);
				void clr(int id);

				const char* getPayload(int id);
				void setPayload(int id, const char* payload);
				void addToPayload(int id, const char* payload);
			};

			template class KRXB_DLL std::shared_ptr<RequestService>;
		}
	}
}

#endif // !XBOX_ONE_REQUEST_SERVICE
