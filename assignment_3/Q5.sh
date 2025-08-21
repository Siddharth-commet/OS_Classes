#Write a shell program to display the total number of words and and total number of lines in a file.
#!/bin/bash

echo "Enter the file name: "
read filename

if [[ -f "$filename" ]]; then
    lines=$(wc -l < "$filename")
    words=$(wc -w < "$filename")

    echo "Total number of lines = $lines"
    echo "Total number of words = $words"
else
    echo "File does not exist!"
fi

git config --global user.name "Siddharth-commet"
git config --global user.email "ssiddharth_be24@thapar.edu"
