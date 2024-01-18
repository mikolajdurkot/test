#!/bin/bash

if [ "$#" -ne 1 ]; then
    	echo "Uzyj dwoch argumentow - nazwy skryptu i nazwy katalogu."
    	exit 1
fi

katalog=$1
cd "$katalog" || exit 1

znalezione_zapetlenia=0

for plik in *; do
	if [ -h "$plik" ]; then
        	odwolanie=$(readlink "$plik")
        	sciezka=$plik

        	# Sprawdzanie, czy istnieje cykl w linkowaniu
        	while [ -h "$odwolanie" ]; do
            		odwolanie=$(readlink "$odwolanie")

            		# Cykl zostaje znaleziony
            		if [ "$odwolanie" = "$sciezka" ]; then
                		znalezione_zapetlenia=$((znalezione_zapetlenia + 1))
                		break
            		fi
        	done
    	fi
done

if [ "$znalezione_zapetlenia" -eq 0 ]; then
    	echo "Brak zapetlen softlinkow."
else
	znalezione_zapetlenia=$((znalezione_zapetlenia / 2))
	echo "Znaleziono $znalezione_zapetlenia softlinkow."
fi
