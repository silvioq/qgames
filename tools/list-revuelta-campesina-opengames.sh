#!/bin/bash
function  list_page(){
    curl -sf "http://www.opengames.com.ar/es/room/Peasant's-Revolt-Social-Room/history?page=$1" | \
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
            ./download-opengames.sh $partida RevueltaCampesina > $file
            echo " ... generado"
            sleep 4
        fi
    done
    i=$[$i + 1]
done

