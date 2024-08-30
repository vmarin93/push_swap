#!/usr/bin/env zsh

set -euo pipefail
THISDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

function help(){
cat <<EOT
       Helper script for push_swap

       Run commands for "$THISDIR"
           build:        build
           run:          build and run
           test:         build and run using input from input.txt file
           save:         save a random input to input.txt
EOT
}

function run_cmd(){
    local cmd="$1"
    shift || true
    (
        "cmd_$cmd" "$@"
    )
}

function main(){
    local cmd=${1-none}
    shift || true
    case "$cmd" in
        none)
            help "$cmd"
            exit 1
            ;;
        help)
            help "$cmd"
            ;;
        build|run|test|save)
            run_cmd "$cmd" "$@"
            ;;
        *)
            echo "Unknown command $cmd"
            exit 1
            ;;
    esac
}


function cmd_run() {
    (
        make all
        $THISDIR/push_swap $(seq 1 100 | shuf)
    )
}

function cmd_test(){
    (
        make all
        # This only works on zsh
        $THISDIR/push_swap ${(f)"$(<input.txt)"}
    )
}

function cmd_build() {
    (
        make re
    )
}

function cmd_save(){
    seq 1 100 | shuf &> input.txt
}
main "$@"