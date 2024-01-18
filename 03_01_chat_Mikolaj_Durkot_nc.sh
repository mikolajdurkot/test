#!/bin/bash

gnome-terminal -- ./03_01_chat_Mikolaj_Durkot_nc_recieve.sh


clear
printf '\e[8;5;10t'
while true; do
        read -p "$1: " message
        echo "$1: $message" | nc "$2" 12345 | kill -l 9 >> /dev/null # Ustaw p>
        echo "$1: $message" | nc "$3" 12345 | kill -l 9 >> /dev/null
	clear
done
