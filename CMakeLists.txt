cmake_minimum_required(VERSION 3.10)
project(TDs_Prog_Algo)

# Activer la recherche récursive
file(GLOB_RECURSE cpp_files RELATIVE ${CMAKE_SOURCE_DIR} TD*/ex*.cpp)

foreach(file ${cpp_files})
    # Extraire le nom du répertoire et le nom du fichier
    get_filename_component(dir ${file} DIRECTORY)
    get_filename_component(name_we ${file} NAME_WE)
    
    # Construire le nom de l'exécutable en combinant le dossier et le fichier
    string(REPLACE "/" "_" exe_name ${dir}_${name_we})
    
    # Ajouter l'exécutable
    add_executable(${exe_name} ${file})
endforeach()
