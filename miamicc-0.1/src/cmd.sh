
#!/bin/bash

./miamicc --device=/dev/ttyUSB1 --setHexnode2Enable=1

#while true; do
./miamicc --device=/dev/ttyUSB1 --getCodeVersion
./miamicc --device=/dev/ttyUSB1 --initCommandTable
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=80,0,2000,0,100,0,255,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=81,0,2000,0,10,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=82,0,2000,0,20,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=83,0,2000,0,30,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=84,0,2000,0,40,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=85,0,2000,0,50,0,255,0

#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=80,0,100,0,1,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=81,0,200,0,1,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=82,0,330,0,1,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=83,0,274,0,1,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=84,0,117,0,1,0,255,0
#./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=85,0,119,0,1,0,255,0


./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=92,0,500,1,0,1,500,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=91,0,600,1,0,1,500,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=90,0,700,1,0,1,1,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=89,0,800,1,0,1,1,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=88,0,900,1,0,1,1,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=87,0,1000,1,0,1,1,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=92,0,500,1,0,2,500,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=91,0,600,1,0,2,500,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=90,0,700,1,0,2,1,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=89,0,800,1,0,2,1,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=88,0,900,1,0,2,1,0
./miamicc --device=/dev/ttyUSB1 --addCommandTableEntry=87,0,1000,1,0,2,1,0

while true; do
./miamicc --device=/dev/ttyUSB1 --getCodeVersion

./miamicc --device=/dev/ttyUSB1 --enableCommandHandler
#./miamicc --device=/dev/ttyUSB1 --setHexnode2Output2=0
sleep 1
#./miamicc --device=/dev/ttyUSB1 --setHexnode2Output2=255
sleep 1
./miamicc --device=/dev/ttyUSB1 --disableCommandHandler
sleep 1
done
