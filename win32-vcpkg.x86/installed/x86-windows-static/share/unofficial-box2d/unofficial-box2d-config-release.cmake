#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "unofficial::box2d::box2d" for configuration "Release"
set_property(TARGET unofficial::box2d::box2d APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(unofficial::box2d::box2d PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/box2d.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS unofficial::box2d::box2d )
list(APPEND _IMPORT_CHECK_FILES_FOR_unofficial::box2d::box2d "${_IMPORT_PREFIX}/lib/box2d.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
