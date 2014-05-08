#!/bin/bash
#TestScript.sh

log='LOGIN=username*PASS:pass'
cred='CREDREQ'
mess='SENDMESSAGE=username*MESSAGE:test message'
off='LOGOFF=username'
./SampleClient2 localhost $1

echo "$log"
sleep 2s
echo "$cred"
sleep 2s
echo "$mess"
sleep 2s
echo "$off"
