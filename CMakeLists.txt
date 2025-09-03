cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(Kunden VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#### External packages
find_package(GTest CONFIG REQUIRED)

#### Assessment center evalution 
set(UNIT_TEST_FOLDER "test")
set(NAME_KUNDEN_LIB "KundenDaten")
set(NAME_KUNEDEN_LIB_EXT )
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/includes")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/customer-cli")
set(RUNWORK 1)

function (aufgabeOne_CodeRefactor)
    set(AUFGABE_CODE_REFACTOR_DIR "${UNIT_TEST_FOLDER}/aufgabeOneHeaderRefactor")
    set(UNIT_TEST_NAMES unittestAlteHeaderLegacyC unittestAlteHeaderLegacyCpp unittestHeaderRefactoredCxx) 
    set(UNIT_TEST_FILE_NAMES unittestAlteHeaderLegacyC.cc unittestAlteHeaderLegacyCpp.cpp unittestHeaderRefactoredCxx.cpp)
    runUnitTests("${UNIT_TEST_NAMES}" "${UNIT_TEST_FILE_NAMES}" "${AUFGABE_CODE_REFACTOR_DIR}")
endfunction()

function (aufgabeTwo_ImplBibliothek)
    set(AUFGABE_LIB_IMPL "${UNIT_TEST_FOLDER}/aufgabeTwoImplLib")
    set(UNIT_TEST_NAMES unittestsKundenArchiv unittestKundenDataFormatter)    
    set(UNIT_TEST_FILE_NAMES unittestsKundenArchiv.cpp unittestKundenDataFormatter.cpp)
    add_library(
        ${NAME_KUNDEN_LIB} 
        STATIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/includes/KundenArchiv.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/src/KundenArchiv.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/includes/KundenDataFormatter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/src/KundenDataFormatter.cpp
    )
    target_compile_options("${NAME_KUNDEN_LIB}" PRIVATE -DCXX_MODERN -Wall -Wextra -Wpedantic)
    runUnitTests("${UNIT_TEST_NAMES}" "${UNIT_TEST_FILE_NAMES}" "${AUFGABE_LIB_IMPL}")
endfunction()

function (aufgabeTwo_libExtension)
    set(AUFGABE_LIB_EXTENSION "${UNIT_TEST_FOLDER}/aufgabeTwoImplLib")
    set(UNIT_TEST_NAMES unittestLibraryExtension)    
    set(UNIT_TEST_FILE_NAMES unittestLibraryExtension.cpp)
    target_sources(
        "${NAME_KUNDEN_LIB}" 
        PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/includes/KundenSpeichern.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/src/KundenSpeichern.cpp
    )
    runUnitTests("${UNIT_TEST_NAMES}" "${UNIT_TEST_FILE_NAMES}" "${AUFGABE_LIB_EXTENSION}")
endfunction()

function (aufgabe_KonsoleAnwendung)
    set(AUFGABE_CLI "${UNIT_TEST_FOLDER}/aufgabeThreeKundenCli")
    set(UNIT_TEST_NAMES unittestKundenCli unittestUserInputField)    
    set(UNIT_TEST_FILE_NAMES unittestKundenCli.cpp unittestUserInputField.cpp)
    add_executable(
        ${PROJECT_NAME}_cli 
        ${CMAKE_CURRENT_SOURCE_DIR}/customer-cli/customer-cli-main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/customer-cli/KundenDaten.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/customer-cli/ErrorHandling.cpp
    )
    target_compile_options("${PROJECT_NAME}_cli" PRIVATE -DCXX_MODERN -Wall -Wextra -Wpedantic)
    target_link_libraries(${PROJECT_NAME}_cli PUBLIC ${NAME_KUNDEN_LIB})
    runUnitTests("${UNIT_TEST_NAMES}" "${UNIT_TEST_FILE_NAMES}" "${AUFGABE_CLI}" )
endfunction()

function(runUnitTests unitTestNames unitTestFileNames unitTestFolder)
    set(COUNTER 0)
    foreach(unitTestName IN LISTS unitTestNames)
        LIST(GET unitTestFileNames "${COUNTER}" unitTestFileName)
        set(TARGET_NAME "${unitTestName}")
        set(SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/${unitTestFolder}/${unitTestFileName}")
        if( "${unitTestFolder}" MATCHES "Three" )
            set(SOURCE  "${CMAKE_CURRENT_SOURCE_DIR}/${unitTestFolder}/${unitTestFileName}" 
                        "${CMAKE_CURRENT_SOURCE_DIR}/customer-cli/KundenDaten.cpp" 
                        "${CMAKE_CURRENT_SOURCE_DIR}/customer-cli/ErrorHandling.cpp")    
        endif()        
        add_executable( "${TARGET_NAME}" "${SOURCE}" )
        target_compile_options("${TARGET_NAME}" PRIVATE -Wall -Wextra -Wpedantic)

        if(NOT "${TARGET_NAME}" MATCHES "Alte")
            target_compile_options("${TARGET_NAME}" PRIVATE -DCXX_MODERN)
        endif()
        target_link_libraries(${TARGET_NAME} PRIVATE GTest::gtest GTest::gmock gtest_main ${NAME_KUNDEN_LIB})
        math(EXPR COUNTER "${COUNTER} + 1")
    endforeach()
endfunction()

if(RUNWORK)
    aufgabeOne_CodeRefactor()

    aufgabeTwo_ImplBibliothek()

    aufgabeTwo_libExtension()

    aufgabe_KonsoleAnwendung()
endif()
