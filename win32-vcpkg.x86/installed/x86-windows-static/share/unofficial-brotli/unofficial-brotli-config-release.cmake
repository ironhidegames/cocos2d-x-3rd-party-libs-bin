#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "unofficial::brotli::brotlienc-static" for configuration "Release"
set_property(TARGET unofficial::brotli::brotlienc-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(unofficial::brotli::brotlienc-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "unofficial::brotli::brotlicommon-static"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/brotlienc-static.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS unofficial::brotli::brotlienc-static )
list(APPEND _IMPORT_CHECK_FILES_FOR_unofficial::brotli::brotlienc-static "${_IMPORT_PREFIX}/lib/brotlienc-static.lib" )

# Import target "unofficial::brotli::brotlidec-static" for configuration "Release"
set_property(TARGET unofficial::brotli::brotlidec-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(unofficial::brotli::brotlidec-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "unofficial::brotli::brotlicommon-static"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/brotlidec-static.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS unofficial::brotli::brotlidec-static )
list(APPEND _IMPORT_CHECK_FILES_FOR_unofficial::brotli::brotlidec-static "${_IMPORT_PREFIX}/lib/brotlidec-static.lib" )

# Import target "unofficial::brotli::brotlicommon-static" for configuration "Release"
set_property(TARGET unofficial::brotli::brotlicommon-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(unofficial::brotli::brotlicommon-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/brotlicommon-static.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS unofficial::brotli::brotlicommon-static )
list(APPEND _IMPORT_CHECK_FILES_FOR_unofficial::brotli::brotlicommon-static "${_IMPORT_PREFIX}/lib/brotlicommon-static.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
