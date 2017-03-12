#!/bin/bash

cd "$(dirname "$0")"
DIR_TMP_BUILD=./tmp
mkdir -p $DIR_TMP_BUILD
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
sed -i '/\\medskip/ /g' $FILENAME.iso.tex
latex2html -html_version 4.0,unicode -split 5 $FILENAME.iso.tex
rm $FILENAME.iso.tex
cp FAT_documentation_FR.iso.css FAT_documentation_FR.iso/
echo "**** Terminé ****"

FILENAME=FAT_documentation_EN
PDF_FILE_TO_GENERATE=FAT_documentation_EN.pdf

echo "**** Construction du PDF ****"
rm ./$PDF_FILE_TO_GENERATE
pdflatex -output-directory=$DIR_TMP_BUILD  $FILENAME.tex
pdflatex -output-directory=$DIR_TMP_BUILD  $FILENAME.tex
mv $DIR_TMP_BUILD/$FILENAME.pdf ./$PDF_FILE_TO_GENERATE
echo "**** Terminé ****"
