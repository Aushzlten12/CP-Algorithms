cmake_minimum_required(VERSION 3.22)
project(CP_Algorithms)


set(TEST_FILES tests/test_main.cpp)

add_executable(tests ${TEST_FILES})

find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)  # Utiliza las variables de GTest para enlazar

enable_testing()
add_test(NAME main_project_test COMMAND main_project)  # Utiliza NAME y COMMAND para agregar la prueba
add_test(NAME tests COMMAND tests)
