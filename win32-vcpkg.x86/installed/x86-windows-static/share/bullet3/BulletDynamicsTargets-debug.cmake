#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "BulletDynamics" for configuration "Debug"
set_property(TARGET BulletDynamics APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(BulletDynamics PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/BulletDynamics_Debug.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS BulletDynamics )
list(APPEND _IMPORT_CHECK_FILES_FOR_BulletDynamics "${_IMPORT_PREFIX}/debug/lib/BulletDynamics_Debug.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
