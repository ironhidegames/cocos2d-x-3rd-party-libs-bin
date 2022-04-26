#pragma once

#ifndef XBOX_ONE_STORAGE_SERVICE
#define XBOX_ONE_STORAGE_SERVICE

#include "Base.h"

#include "xsapi/services.h"
#include "XBoxAuthService.h"
#include <shared_mutex>
#ifdef USE_REQUEST_SERVICE
#include "RequestService.h"
#endif

namespace kalio {
	namespace xbox_bridge {
		namespace storage {

			using namespace Windows::Gaming::XboxLive::Storage;
			using namespace Windows::Storage::Streams;
			
			class KRXB_DLL XBoxStorageService {
			private:
				const std::string CONTAINER_NAME = "SavedGames";
				const int SAVEFILE_SIZE = 256*1024;  // 256kB
				mutable std::shared_mutex mutex;
				GameSaveProvider^ provider;
				volatile bool initialized = false;
								volatile bool wasInitialized = false;
				volatile double lastSync = 0.0;
				std::map<Platform::String^, IBuffer^> saveFiles;
				std::map<Platform::String^, std::string> saveCache;

				std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService = nullptr;
				Platform::String^ getSCID();
				Platform::String^ convertToPlatform(std::string str);
				std::string convertFromPlatform(Platform::String^ str);
				std::vector<std::string> split(const char* str, char sep);
				IBuffer^ makeDataBuffer(int size) const;
				Platform::String^ bufferToString(IBuffer^ buffer);
				IBuffer^ stringToBuffer(Platform::String^ str);
								std::string lastNamesList;
				void loadContainers(int reqId, std::string names_list);
				void saveContainers(int reqId);
#ifdef USE_REQUEST_SERVICE
				std::shared_ptr<kalio::xbox_bridge::requests::RequestService> requestService = nullptr;
#endif // USE_REQUEST_SERVICE
			public:
#ifdef USE_REQUEST_SERVICE
				XBoxStorageService(std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService, 
									std::shared_ptr<kalio::xbox_bridge::requests::RequestService> requestService) {
					this->authService = authService;
					this->requestService = requestService;
					if (requestService == nullptr) {
						throw std::exception("Request service required");
					}
				}
#else
				XBoxStorageService(std::shared_ptr<kalio::xbox_bridge::auth::XBoxAuthService> authService) {
					this->authService = authService;
				}
#endif // USE_REQUEST_SERVICE

			public: 
				double getLastSync() { return this->lastSync; }
				void resume();
				void suspend();
				int initializeAndSync(std::string names_list);
				const char* getFile(const char* name);
				int setFile(const char* name, const char* content);
				int delFile(const char* name);
				// Resume the previously loaded user context, reloading game save data in memory if needed
				//Concurrency::task<HRESULT> ResumeForUser(std::shared_ptr<xbox::services::system::xbox_live_user> xboxLiveUser);
				
			};

			template class KRXB_DLL std::shared_ptr<XBoxStorageService>;
		}
	}
}

#endif
