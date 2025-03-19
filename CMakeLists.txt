cmake_minimum_required(VERSION 3.10)
project(TDs_Prog_Algo)

file(GLOB_RECURSE cpp_files RELATIVE ${CMAKE_SOURCE_DIR} TD*/ex*.cpp)

foreach(file ${cpp_files})
    get_filename_component(dir ${file} DIRECTORY)
    get_filename_component(name_we ${file} NAME_WE)
    string(REPLACE "/" "_" exe_name ${dir}_${name_we})
    
    add_executable(${exe_name} ${file})
endforeach()
