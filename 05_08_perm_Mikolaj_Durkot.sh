#!/bin/bash

if [ "$#" -ne 1 ]; then
    	echo "Uzyj dwoch argumentow - nazwy skryptu i nazwy katalogu."
    	exit 1
fi

katalog=$1
cd "$katalog" || exit 1

ls -lr | cut -d' ' -f1 | tail -n +2 | sort | uniq -c
