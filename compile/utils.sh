#!/bin/bash

function pretty_printing(){
    local -r div=$(divider '*');
    margin "$div" 1 0;

    for linking in "$@"; do
        printf "\nLinking: %s\nLocation: %s\n" "$(basename "$linking")" "$linking";
    done

    margin "$div" 1 3;
    return 0;
}


function divider(){
    local -r SYMBOLS=${1:-'-'};
    local divider='';
    local -i columns=$(tput cols);

    while ((columns--)); do
        divider+="$SYMBOLS";
    done

    echo "$divider";
    return 0;
}


function margin(){
    local -A count=(
        ["top"]=${2:-1}
        ["bottom"]=${3:-1}
    );

    local -A margin=(
        ["top"]=""
        ["bottom"]=""
    );

    if [[ ${count[top]} > 0 ]]; then
        while ((count[top]--)); do
            margin[top]+="\n";
        done
    fi

    if [[ ${count[bottom]} > 0 ]]; then
        while ((count[bottom]--)); do
            margin[bottom]+="\n";
        done
    fi

    echo -e "${margin[top]}${1}${margin[bottom]}";

    return 0;
}
