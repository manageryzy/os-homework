#!/bin/sh

c=1
i=1

while [ $c -le 5 ]
do 
    while [ $i -le 30 ]
    do

        if [ $i -le 9 ] 
        then
            USERNAME=class${c}_stu0${i}
        else
            USERNAME=class${c}_stu${i}
        fi
	useradd $USERNAME
    done

done
