cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

project(barcode_scnanner)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/formulas.h
        ${INC_DIR}/encode_funcs.h
        ${INC_DIR}/scan_data_funcs.h
           
        ${SRC_DIR}/main.c
        ${SRC_DIR}/encode_funcs.c
        ${SRC_DIR}/formulas.c
        ${SRC_DIR}/scan_data_funcs.c

)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
