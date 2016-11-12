#!/bin/bash
echo "" >> salida.dat
i=10
while [ $i -lt 100000 ]; do
./DVposicion $i >> salida.dat;
i=$(( $i + 1000 ));
done


