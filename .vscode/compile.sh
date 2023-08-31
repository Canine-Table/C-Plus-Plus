#/bin/bash

# echo -e "\nthe project folder is: ${BASENAMES[file]}";
# echo -e "\nthe project folder is: ${BASENAMES[workspaceFolder]}";
# echo -e "\nthe project folder is: ${BASENAMES[fileDirname]}";
# echo -e "\nthe project folder is: ${BASENAMES[projectFolder]}";

function 07_functions(){
    declare -ga compile_file_args=(
        "${LINKER_FILES[commonOutputUtils]}"
    );

    case "${BASENAMES[fileDirname]}" in
        "07-functions")
            compile_file_args+=("${LINKER_FILES[person]}");;
        "03-linker")
            compile_file_args+=("${LINKER_FILES[compare]}");;
    esac

    return 0;
}

function 08_function_templates(){
    declare -gar compile_file_args=(
        "${LINKER_FILES[commonOutputUtils]}"
        "${LINKER_FILES[commonTemplateUtils]}"
    );

    return 0;
}

function 10_classes(){
    declare -gar compile_file_args=(
        "${LINKER_FILES[commonTemplateUtils]}"
        "${LINKER_FILES[dog]}"
        "${LINKER_FILES[cylinder]}"
    );

    return 0;
}


function get_basename(){
    echo "$(awk -F'/' '{print $NF}' <<< $1)";
    return 0;
}

function choose_files_to_compile(){

    local -Ar BASENAMES=(
        ["file"]="$(get_basename ${FILE_PATHS[file]})"
        ["workspaceFolder"]="$(get_basename ${FILE_PATHS[workspaceFolder]})"
        ["fileDirname"]="$(get_basename ${FILE_PATHS[fileDirname]})"
        ["projectFolder"]="$(sed "s|${FILE_PATHS[workspaceFolder]}/project/||g" <<< ${FILE_PATHS[fileDirname]} | awk -F'/' '{print $1}')"
    );

    local -Ar LINKER_FILES=(
        ["commonOutputUtils"]=$(echo "${FILE_PATHS[workspaceFolder]}/headers/common-output-utils.cpp")
        ["commonTemplateUtils"]=$(echo "${FILE_PATHS[workspaceFolder]}/headers/common-template-utils.cpp")
        ["person"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/07-functions/person.cpp")
        ["compare"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/07-functions/03-linker/compare.cpp")
        ["dog"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/10-classes/03-modular/cylinder.cpp")
        ["cylinder"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/10-classes/03-modular/cylinder.cpp")
    );

    case "${BASENAMES[projectFolder]}" in

        "07-functions")
            07_functions;;
        "08-function-templates")
            08_function_templates;;
        "10-classes")
            10_classes;;
        *)
            declare -gar compile_file_args=(
                "${LINKER_FILES[commonTemplateUtils]}"
            );;
    esac

    return 0;
}


function main(){
    local -Ar FILE_PATHS=(
        ["file"]="$1"
        ["workspaceFolder"]="$2"
        ["fileDirname"]="$3"
        ["buildPath"]="$4"
    );

    choose_files_to_compile "${FILE_PATHS[@]}";
    /usr/bin/g++ -fdiagnostics-color=always -g -std=c++23 "${FILE_PATHS[file]}" "${compile_file_args[@]}" -o "${FILE_PATHS[buildPath]}";
    exit 0;
}

main "$@";
