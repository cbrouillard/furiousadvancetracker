#!/bin/bash

DIR_TMP_BUILD=./tmp
FILENAME=FAT_documentation_FR
PDF_FILE_TO_GENERATE=FAT_documentation_FR.pdf

echo "**** Construction du PDF ****"
rm ./$PDF_FILE_TO_GENERATE
pdflatex -output-directory=$DIR_TMP_BUILD  $FILENAME.tex
pdflatex -output-directory=$DIR_TMP_BUILD  $FILENAME.tex
pdflatex -output-directory=$DIR_TMP_BUILD  $FILENAME.tex
mv $DIR_TMP_BUILD/$FILENAME.pdf ./$PDF_FILE_TO_GENERATE
echo "**** Terminé ****"
