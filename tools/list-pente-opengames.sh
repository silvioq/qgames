#!/bin/bash
function  list_page(){
    curl -sf "http://www.opengames.com.ar/es/room/Pente/history?page=$1" | \
    awk "/http:\\/\\/www.opengames.com.ar\\/es\\/[0-9]+/ { match( \$0, \"[0-9]+\" ); print substr(\$0, RSTART, RLENGTH)  }" 
}

function   list_tournament(){
    curl  -sf "http://www.opengames.com.ar/es/tournaments/2010/April%20Open%20Pente%20Tournament?round=$1" | \
    awk "/http:\\/\\/www.opengames.com.ar\\/es\\/[0-9]+/ { match( \$0, \"[0-9]+\" ); print substr(\$0, RSTART, RLENGTH)  }" 
}

i=1
while true; do
    salida=`list_page $i`
    if [ "$salida" == "" ]; then
        break
    fi
    echo pagina: $i ">" $salida
    for partida in $salida; do
        file="../test/qgtest/opengames-$partida.qgtest"
        if [ -f $file ]; then
            echo "$file existente"
        else
            printf "generando $file"
            ./download-opengames.sh $partida Pente > $file
            echo " ... generado"
            sleep 4
        fi
    done
    i=$[$i + 1]
done

i=1
while true; do
    salida=`list_tournament $i`
    if [ "$salida" == "" ]; then
        break
    fi
    echo pagina: $i ">" $salida
    for partida in $salida; do
        file="../test/qgtest/opengames-$partida.qgtest"
        if [ -f $file ]; then
            echo "$file existente"
        else
            printf "generando $file"
            ./download-opengames.sh $partida Pente > $file
            echo " ... generado"
            sleep 4
        fi
    done
    i=$[$i + 1]
done

