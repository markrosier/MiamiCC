
#!/bin/bash

while true; do
./miamicc --device=/dev/ttyUSB0 --getSpaceHeaterErrorCode
./miamicc --device=/dev/ttyUSB0 --getWaterHeaterErrorCode
./miamicc --device=/dev/ttyUSB0 --getSpaceHeaterBurnerStatus
./miamicc --device=/dev/ttyUSB0 --getWaterHeaterBurnerStatus
sleep 1
done
