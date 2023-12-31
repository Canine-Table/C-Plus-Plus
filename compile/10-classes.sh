#!/bin/bash

function 10_classes(){
    source "${FILE_PATHS[workspaceFolder]}/compile/utils.sh";
    declare -gar compile_file_args=(
        "${LINKER_FILES[commonTemplateUtils]}"
        "${LINKER_FILES[dog]}"
        "${LINKER_FILES[cylinder]}"
        "${LINKER_FILES[wrapper]}"
        "${LINKER_FILES[point]}"
    );
    pretty_printing "${compile_file_args[@]}";
    return 0;
}
