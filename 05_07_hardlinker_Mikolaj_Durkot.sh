#!/bin/bash

if [ "$#" -ne 1 ]; then
    	echo "Uzyj dwoch argumentow - nazwy skryptu i nazwy katalogu."
    	exit 1
fi

katalog=$1
cd "$katalog" || exit 1


find . -type f -links +1 -print | while read -r plik; do
	liczba_dowiazan=$(stat -c %h "$plik")

	if [ "$liczba_dowiazan" -gt 1 ]; then
		echo "Znaleziono hardlink: $plik (Liczba dowiązań: $liczba_dowiazan)"
	fi
done

