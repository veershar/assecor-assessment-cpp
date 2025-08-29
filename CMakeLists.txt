cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(Customerdata VERSION 0.0.0 LANGUAGES C CXX)

#### External packages
find_package(GTest CONFIG REQUIRED)

#### Assessment center evalution 
set(UNIT_TEST_FOLDER "test")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/includes")


function (aufgabeOne_CodeRefactor)
    message("Code should work with old c and c++ files")
    set(AUFGABE_CODE_REFACTOR_DIR "${UNIT_TEST_FOLDER}/aufgabeOneHeaderRefactor")
    set(UNIT_TEST_NAMES unittestAlteHeaderLegacyC unittestAlteHeaderLegacyCpp unittestHeaderRefactoredCxx) 
    set(UNIT_TEST_FILE_NAMES unittestAlteHeaderLegacyC.cc unittestAlteHeaderLegacyCpp.cpp unittestHeaderRefactoredCxx.cpp)
    set(COUNTER 0)
    foreach(unitTestName IN LISTS UNIT_TEST_NAMES)
        LIST(GET UNIT_TEST_FILE_NAMES "${COUNTER}" UNIT_TEST_FILE)
        set(TARGET_NAME "${unitTestName}")
        set(SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/${AUFGABE_CODE_REFACTOR_DIR}/${UNIT_TEST_FILE}")
        add_executable( "${TARGET_NAME}" "${SOURCE}" )
        target_compile_options("${TARGET_NAME}" PRIVATE -Wall -Wextra -Wpedantic)
        if("${COUNTER}" STREQUAL "2")
            target_compile_options("${TARGET_NAME}" PRIVATE -DCXX_MODERN)
        endif()
        target_link_libraries(${TARGET_NAME} PRIVATE GTest::gtest gtest_main)
        math(EXPR COUNTER "${COUNTER} + 1")
    endforeach()

endfunction()


aufgabeOne_CodeRefactor()