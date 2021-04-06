#!/bin/bash

declare -i count=$(($1));
declare -i total=0; 
declare -i tmp=0;
declare -i min=1000000;
declare -i max=0;

bite()
{
	./a.out `ruby -e "puts (0..100).to_a.shuffle.join(' ')"` | wc -l
}

for i in $( eval echo {1..$count} )
	do 
		tmp=$(bite)
		if [ $tmp -gt $max ];
		then
			max=$tmp
		elif [ $tmp -lt $min ];
		then
			min=$tmp
		fi
		echo "$i / $count: $tmp"
		total+=$tmp
	done

if [ $min -eq 1000000 ];
then
	min=0
fi

echo "min: $min"
echo "max: $max"

echo "scale=2; $total / $count" | bc
