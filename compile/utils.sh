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
    local -r message="$1";
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

    echo -e "${margin[top]}${message}${margin[bottom]}";

    return 0;
}


function check_permission(){
    local -i default="${2:-1}";
    if [[ "$2" == "true" ]]; then
        default=0;
    fi
    local -ur RUN="$1"
    case "$RUN" in
        'YES'|'Y'|'ALLOW'|'CONFIRM')
            echo 0;;
        'NO'|'N'|'DENY')
            echo 1;;
        *)
            echo $default;;
    esac
    return 0;
}


function confirmation(){
    local -r command_path="$1";
    local -r message="${@:2}";
    margin "" 5;
    tput cup $(($(tput lines)-5))
    read -p " ${message}: " RUN;
    if [[ $(check_permission "$RUN") == 0 ]]; then
        "$command_path";
    fi
    margin "" 3;
    return 0;
}
