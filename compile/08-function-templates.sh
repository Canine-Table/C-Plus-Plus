#!/bin/bash

function 08_function_templates(){
    source "${FILE_PATHS[workspaceFolder]}/compile/utils.sh";
    declare -gar compile_file_args=(
        "${LINKER_FILES[commonOutputUtils]}"
        "${LINKER_FILES[commonTemplateUtils]}"
    );
    pretty_printing "${compile_file_args[@]}";
    return 0;
}
