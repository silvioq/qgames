#!/bin/bash
# "http://brainking.com/es/Profile?u=18826&eg=76&dy=2007&p=1"
# "http://brainking.com/es/Profile?u=18826&eg=76&dy=2008&p=1"


function  list_page(){
    user=$1
    eg=$2
    year=$3   
    curl -sf "http://brainking.com/es/Profile?u=$user&eg=$eg&dy=$year&p=$page" | \
    awk "/ArchivedGame\?g=[0-9]/ { match( \$0, \"[0-9]+\" ); print substr(\$0, RSTART, RLENGTH)  }" 
}

function  download(){
    for partida in $@; do
        file="../test/qgtest/brainking-$partida.qgtest"
        if [ -f $file ]; then
            echo  "$file existente"
        else
            printf "generando $file"
            ./download-brainking.sh $partida AjedrezLosAlamos > $file
            echo " ... generado"
            sleep 2
        fi
            
    done
}

user=18826
eg=76
year=2010

i=2002
while true; do
    page=1
    printf "$i ->> "
    while true; do
        salida=`list_page $user $eg $i $page`
        if [ "$salida" == "" ]; then
            break
        fi
        download $salida
        page=$[$page + 1]
    done
    echo
    if [ "$i" == "$year" ]; then
        break
    fi  
    i=$[$i + 1]

done

# i=1
# while true; do
#     salida=`list_page $i`
#     if [ "$salida" == "" ]; then
#         break
#     fi
#     echo pagina: $i ">" $salida
#     for partida in $salida; do
#         file="../test/qgtest/opengames-$partida.qgtest"
#         if [ -f $file ]; then
#             echo "$file existente"
#         else
#             printf "generando $file"
#             ./download-opengames.sh $partida > $file
#             echo " ... generado"
#             sleep 4
#         fi
#     done
#     i=$[$i + 1]
# done

