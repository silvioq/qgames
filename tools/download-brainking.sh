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
url="http://brainking.com/es/GetPGN/$juego.pgn?g=$juego"

curl -sf "$url" > $file
if [ $? != 0 ]; then
    echo "Juego $juego erroneo"
    exit 1
fi

# cat $file

echo "# Juego obtenido de  $url"
echo "# Entre " `cat $file | grep White | sed "s/White //g"` "y" `cat $file | grep Black | sed "s/Black //g"`
echo "nuevo-juego $tjuego"
cat $file | grep -v "^\\["
# cat $file | grep "Result" | sed s/[^-012\\*\\/]//g

rm $file

