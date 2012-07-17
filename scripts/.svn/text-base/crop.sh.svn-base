#!/bin/bash

filename=${1%.*}
extension=${1##*.}
#echo $filename
#echo $extension

pdfcrop $1
rm $1
mv $filename-crop.$extension $1