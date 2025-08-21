#!/bin/bash
#Write a shell program to check whether a character is VOWEL or CONSONANT using switch.

echo "Please Enter a Alphabet: "
read Alpha

case $Alpha in
    [Aa])
        echo "found A/a"
        ;;
    [Ee])
    echo "found E/e"
        ;;
    [Ii])
        echo "found I/i"
        ;;

    [Oo])
        echo "found O/o"
        ;;
    [Uu])
        echo "found U/u"
        ;;
    [BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxYyZz])
        echo "found Consonant"
        ;;
    *)
    echo "Not a Alphabet!"
    ;;

esac