#!/bin/bash

DIR_TMP_BUILD=./tmp
mkdir $DIR_TMP_BUILD
FILENAME=FAT_documentation_FR
PDF_FILE_TO_GENERATE=FAT_documentation_FR.pdf

echo "**** Construction du PDF ****"
rm ./$PDF_FILE_TO_GENERATE
pdflatex -output-directory=$DIR_TMP_BUILD  $FILENAME.tex
pdflatex -output-directory=$DIR_TMP_BUILD  $FILENAME.tex
mv $DIR_TMP_BUILD/$FILENAME.pdf ./$PDF_FILE_TO_GENERATE
echo "**** Terminé ****"

echo "**** Construction document online ****"
iconv --from-code=UTF-8 --to-code=ISO-8859-1 $FILENAME.tex > $FILENAME.iso.tex
latex2html -iso_language 'FR' $FILENAME.iso.tex
rm $FILENAME.iso.tex
echo "**** Terminé ****"
