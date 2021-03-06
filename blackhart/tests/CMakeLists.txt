cmake_minimum_required(VERSION 3.7)

# ~~~~~ Blackhart tests ~~~~~

set(BLACKHART_TEST_PROJECT_NAME "blackhart.test")

message("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
message("${BLACKHART_TEST_PROJECT_NAME}: BUILD ENABLE")

project(${BLACKHART_TEST_PROJECT_NAME} C)

# Sets Blackhart test's sources directory
set(BLACKHART_TEST_PATH "${${BLACKHART_TEST_PROJECT_NAME}_SOURCE_DIR}")

# Gets all the source code (both .c and .h files)
file(GLOB_RECURSE CFiles sources/*.c)
file(GLOB_RECURSE HFiles includes/*.h)

# Compiles Blackhart-test
add_executable(${BLACKHART_TEST_PROJECT_NAME} ${CFiles} ${HFiles})

# Links Blackhart's include directory
target_include_directories(${BLACKHART_TEST_PROJECT_NAME} PUBLIC "${BLACKHART_PATH}/includes")

# Links Blackhart-Test's include directory
target_include_directories(${BLACKHART_TEST_PROJECT_NAME} PUBLIC "${BLACKHART_TEST_PATH}/includes")

# Links Blackhart library
target_link_libraries(${BLACKHART_TEST_PROJECT_NAME} ${BLACKHART_PROJECT_NAME})


# ~~~~~ Unity ~~~~~

message("")

# Sets unity's library directory
set(UNITY_LIBRARY_PATH "" CACHE PATH "Unity's library directory")

# Finds unity library
find_library(UNITY_DEBUG_LIBRARY NAMES unityd PATHS "${UNITY_LIBRARY_PATH}" PATH_SUFFIXES "Debug" "debug" NO_DEFAULT_PATH)
find_library(UNITY_RELEASE_LIBRARY NAMES unity PATHS "${UNITY_LIBRARY_PATH}" PATH_SUFFIXES "Release" "release" NO_DEFAULT_PATH)

if (NOT UNITY_DEBUG_LIBRARY OR NOT UNITY_RELEASE_LIBRARY)
	message("unity: Library not found!")
else ()
	message("unity: Library found!")
	message("unity: Debug/library_path:(${UNITY_DEBUG_LIBRARY}) | Release/library_path:(${UNITY_RELEASE_LIBRARY})")
	# Links unity library to Blackhart-test
	target_link_libraries(${BLACKHART_TEST_PROJECT_NAME} debug "${UNITY_DEBUG_LIBRARY}" optimized "${UNITY_RELEASE_LIBRARY}")
endif ()

# Sets unity's include directory
set(UNITY_INCLUDE_PATH "" CACHE PATH "unity's include directory")

# Links unity's include directory
target_include_directories(${BLACKHART_TEST_PROJECT_NAME} PUBLIC "${UNITY_INCLUDE_PATH}")

message("unity: include_path:(${UNITY_INCLUDE_PATH})")