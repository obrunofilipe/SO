#!/usr/bin/env bash
for i in {1..1000000}
	do
		./pessoa -i "pessoa$i" $i
		echo "pessoa $i inserida"
	done
