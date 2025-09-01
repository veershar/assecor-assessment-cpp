cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(Customerdata VERSION 0.0.0 LANGUAGES C CXX)

#### External packages
find_package(GTest CONFIG REQUIRED)

#### Build Parameters 
set(UNIT_TEST_FOLDER "test")
set(UNIT_TEST_AUFGABE_REFACTOR "customer_refactor")
set(UNIT_TEST_ONE_OLD_FILES legacy_c_code.cc legacy_cpp_code.cpp)
set(UNIT_TEST_ONE_REFACTOR_FILE modern_cpp_code.cpp)
set(UNIT_TEST_AUFGABE_CREATE_LIBRARY "customer_create_library")
set(UNIT_TEST_AUFGABE_CLI "customer_cli")
set(REQUIRED_BUILD_LEGACY_CODE ${LEGACY_CODE})
set(REQUIRED_UNIT_TESTS ${UNIT_TESTS})
set(HEADER_TYPE Old)

#### All the checks are done in this section 
if(LANG_C)
    set(TARGET_LANGUAGE C)
elseif(LANG_CXX)
    set(TARGET_LANGUAGE CPP)
else()
    message("Default language is C++")
    set(TARGET_LANGUAGE CPP)
endif()

if(NOT REQUIRED_BUILD_LEGACY_CODE)
    set(HEADER_TYPE Refracted)
    set(COMPILER_FLAG -DCXX_MODERN)
endif()

if(NOT LEGACY_CODE)
    set(HEADER_TYPE Refactored)
endif()


#### Include files and directories 
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/includes")

#### Display Build Information
message("###############################################################################")
message("Build Information:")
message("Legacy code:               ${REQUIRED_BUILD_LEGACY_CODE}")
message("Unit tests:                ${REQUIRED_UNIT_TESTS}")
message("Language:                  ${TARGET_LANGUAGE}")
message("Header:                    ${HEADER_TYPE}")
message("Compiler Options:          ${COMPILER_FLAG}")
message("Task 1:                    ${UNIT_TEST_AUFGABE_REFACTOR}")
message("Task 1[Unit test files]:   ${UNIT_TEST_ONE_OLD_FILES};${UNIT_TEST_ONE_REFACTOR_FILE}")
message("Task 2:                    ${UNIT_TEST_AUFGABE_CREATE_LIBRARY}")
message("Task 2[Unit test files]:   ${UNIT_TEST_AUFGABE_REFACTOR}")
message("Task 3:                    ${UNIT_TEST_AUFGABE_CLI}")
message("Task 3[Unit test files]:   ${UNIT_TEST_AUFGABE_REFACTOR}")
message("###############################################################################")


#### Building Library: Can be static or shared


#### Building console application


#### Build Unit tests for different tasks required 
if(REQUIRED_UNIT_TESTS)
    message("Generating Unit test binariers ")
    set(i 0)
    if(HEADER_TYPE STREQUAL "Old")
        message("Unit test for Old customer header file")
        foreach(file IN LISTS UNIT_TEST_ONE_OLD_FILES)
            set(TARGET_NAME "${PROJECT_NAME}_OldHeader_${i}")
            set(SOURCE "${UNIT_TEST_FOLDER}/${UNIT_TEST_AUFGABE_REFACTOR}/${file}")
            add_executable(${TARGET_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE}")
            target_link_libraries(${TARGET_NAME} PRIVATE GTest::gtest gtest_main)
            math(EXPR i "${i} + 1")
        endforeach()
    elseif(HEADER_TYPE STREQUAL "Refactored")
        message("Unit test for Refactored customer header file")
        set(TARGET_NAME "${PROJECT_NAME}_refactor_cpp")
        set(SOURCE "${UNIT_TEST_FOLDER}/${UNIT_TEST_AUFGABE_REFACTOR}/${UNIT_TEST_ONE_REFACTOR_FILE}")
        add_executable( "${TARGET_NAME}" "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE}")
        target_link_libraries(${TARGET_NAME} PRIVATE GTest::gtest gtest_main)
        target_compile_options("${TARGET_NAME}" PRIVATE ${COMPILER_FLAG})
    endif()
endif()