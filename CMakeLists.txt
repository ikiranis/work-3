cmake_minimum_required(VERSION 3.13)
project(Work_3 C)

set(CMAKE_C_STANDARD 99)

add_executable(kyranis_1A kyranis_1A.c)
add_executable(kyranis_1B kyranis_1B.c)
add_executable(kyranis_1D kyranis_1D.c)
add_executable(kyranis_1C kyranis_1C.c)
add_executable(kyranis_1E kyranis_1E.c)
add_executable(kyranis_2A kyranis_2A.c)
add_executable(kyranis_2C kyranis_2C.c)
add_executable(kyranis_3 kyranis_3.c)
add_executable(kyranis_4 kyranis_4.c)
add_executable(test_sqrt test_sqrt.c)

target_link_libraries(kyranis_4 m)