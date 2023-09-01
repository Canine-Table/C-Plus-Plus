#!/bin/bash

function 07_functions(){
    source "${FILE_PATHS[workspaceFolder]}/compile/utils.sh";
    declare -ga compile_file_args=(
        "${LINKER_FILES[commonOutputUtils]}"
    );
    case "${BASENAMES[fileDirname]}" in
        "07-functions")
            compile_file_args+=("${LINKER_FILES[person]}");;
        "03-linker")
            compile_file_args+=("${LINKER_FILES[compare]}");;
    esac
    pretty_printing "${compile_file_args[@]}";
    return 0;
}
