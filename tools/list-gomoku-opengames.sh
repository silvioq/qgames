#!/bin/bash
function  list_page(){
    curl -sf "http://www.opengames.com.ar/es/room/Gomoku-Social/history?page=$1" | \
    awk "/http:\\/\\/www.opengames.com.ar\\/es\\/[0-9]+/ { match( \$0, \"[0-9]+\" ); print substr(\$0, RSTART, RLENGTH)  }" 
}

function  list_torneo(){
    curl -sf "http://www.opengames.com.ar/es/tournaments/2010/April%20Open%20Gomoku%20Tournament" | \
    awk "/http:\\/\\/www.opengames.com.ar\\/es\\/[0-9]+/ { match( \$0, \"[0-9]+\" ); print substr(\$0, RSTART, RLENGTH)  }" 
}

function  procesar_salida(){
    for partida in $1; do
        file="../test/qgtest/opengames-$partida.qgtest"
        if [ -f $file ]; then
            echo "$file existente"
        else
            printf "generando $file"
            ./download-opengames.sh $partida Gomoku > $file
            echo " ... generado"
            sleep 4
        fi
    done
  
}

salida=`list_torneo`
echo torneo ">" $salida
procesar_salida $salida

i=1
while true; do
    salida=`list_page $i`
    if [ "$salida" == "" ]; then
        break
    fi
    echo pagina: $i ">" $salida
    procesar_salida "$salida"
    i=$[$i + 1]
done


