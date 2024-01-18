#!/bin/bash

if [ $# -ne 4 ]; then
  echo "Uzyj argumentow: <dokument.pdf> <podpis.png> <x> <y>"
  exit 1
fi

document_pdf="$1"
signature_png="$2"
x="$3"
y="$4"

if [ ! -f "$document_pdf" ]; then
  echo "Plik $document_pdf nie istnieje."
  exit 1
fi

if [ ! -f "$signature_png" ]; then
  echo "Plik $signature_png nie istnieje."
  exit 1
fi

output_pdf="dokument_z_podpisem.pdf"

convert "$signature_png" -background none -flatten tmp_signature.png

composite -geometry +$x+$y tmp_signature.png "$document_pdf" "$output_pdf"

rm tmp_signature.png

echo "Podpis został nałożony na dokument i zapisany jako $output_pdf."
