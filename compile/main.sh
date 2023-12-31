#/bin/bash

function choose_files_to_compile(){

    local -Ar BASENAMES=(
        ["file"]="$(basename ${FILE_PATHS[file]})"
        ["workspaceFolder"]="$(basename ${FILE_PATHS[workspaceFolder]})"
        ["fileDirname"]="$(basename ${FILE_PATHS[fileDirname]})"
        ["projectFolder"]="$(sed "s|${FILE_PATHS[workspaceFolder]}/project/||g" <<< ${FILE_PATHS[fileDirname]} | awk -F'/' '{print $1}')"
    );

    local -Ar LINKER_FILES=(
        ["commonOutputUtils"]=$(echo "${FILE_PATHS[workspaceFolder]}/headers/common-output-utils.cpp")
        ["commonTemplateUtils"]=$(echo "${FILE_PATHS[workspaceFolder]}/headers/common-template-utils.cpp")
        ["person"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/07-functions/person.cpp")
        ["compare"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/07-functions/03-linker/compare.cpp")
        ["dog"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/10-classes/03-modular/dog.cpp")
        ["wrapper"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/10-classes/03-modular/wrapper.cpp")
        ["point"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/10-classes/03-modular/point.cpp")
        ["cylinder"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/10-classes/03-modular/cylinder.cpp")
        ["player"]=$(echo "${FILE_PATHS[workspaceFolder]}/project/11-inheritance/objects-and-definitions/player.cpp")
    );

    case "${BASENAMES[projectFolder]}" in
        "07-functions")
            source "${FILE_PATHS[workspaceFolder]}/compile/07-functions.sh"
            07_functions;;
        "08-templates")
            source "${FILE_PATHS[workspaceFolder]}/compile/08-templates.sh"
            08_templates;;
        "10-classes")
            source "${FILE_PATHS[workspaceFolder]}/compile/10-classes.sh"
            10_classes;;
        "11-inheritance")
            source "${FILE_PATHS[workspaceFolder]}/compile/11-inheritance.sh"
            11_inheritance;;
        *)
            source "${FILE_PATHS[workspaceFolder]}/compile/utils.sh";
            declare -gar compile_file_args=(
                "${LINKER_FILES[commonTemplateUtils]}"
            );
            pretty_printing "${compile_file_args[@]}";;
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
    /usr/bin/g++ -fdiagnostics-color=always -fconcepts-diagnostics-depth=2 -g -std=c++23 "${FILE_PATHS[file]}" "${compile_file_args[@]}" -o "${FILE_PATHS[buildPath]}";

    if [[ $? == 0 ]]; then
        source "${FILE_PATHS[workspaceFolder]}/compile/utils.sh"
        confirmation ${FILE_PATHS[buildPath]} "Would you like the run the binary? (Y)es or (N)o";
        exit 0;
    fi
    exit 1;
}

main "$@";
