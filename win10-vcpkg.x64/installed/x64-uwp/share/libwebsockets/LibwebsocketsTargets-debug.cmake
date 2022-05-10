#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "websockets_shared" for configuration "Debug"
set_property(TARGET websockets_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(websockets_shared PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/websockets.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "C:/cocos2d-x-xbox/contrib/install-win10/vcpkg-cocos2d-x/installed/x64-uwp/debug/lib/zlibd.lib;C:/cocos2d-x-xbox/contrib/install-win10/vcpkg-cocos2d-x/installed/x64-uwp/debug/lib/ssleay32.lib;C:/cocos2d-x-xbox/contrib/install-win10/vcpkg-cocos2d-x/installed/x64-uwp/debug/lib/libeay32.lib;ws2_32.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/websockets.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS websockets_shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_websockets_shared "${_IMPORT_PREFIX}/lib/websockets.lib" "${_IMPORT_PREFIX}/bin/websockets.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
