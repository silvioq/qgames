#!/bin/bash

if [ $1x == x ]; then
    echo "Debe especificar el juego"
    exit 1
fi

juego=$1
tjuego=$2
if [ "$tjuego" == "" ]; then
    tjuego="Ajedrez"
fi

file=/tmp/$$.tmp

curl -sf http://www.opengames.com.ar/{$juego}.pgn > $file
if [ $? != 0 ]; then
    echo "Juego $juego erroneo"
    exit 1
fi

# cat $file

echo "# Juego obtenido de  http://www.opengames.com.ar/${juego}.pgn"
echo "# Entre " `cat $file | grep White | sed "s/White //g"` "y" `cat $file | grep Black | sed "s/Black //g"`
echo "nuevo-juego $tjuego"
cat $file | grep -v "^\\["
# cat $file | grep "Result" | sed s/[^-012\\*\\/]//g

rm $file

curl -sf http://www.opengames.com.ar/es/{$juego} > $file
for linea in `cat $file | grep "\".*-.*-.*\"" | grep -v \< | grep -v captured | grep -v pozo`; do
    pieza=`echo $linea | sed "s/-/ /g" | sed s/\"//g | sed s/,//g`
    echo  "check-piezas $pieza 1"
done

rm $file
