#!/bin/bash

function 11_inheritance(){
    source "${FILE_PATHS[workspaceFolder]}/compile/utils.sh";
    declare -gar compile_file_args=(
        "${LINKER_FILES[commonTemplateUtils]}"
        "${LINKER_FILES[people]}"
        "${LINKER_FILES[player]}"
    );
    pretty_printing "${compile_file_args[@]}";
    return 0;
}
