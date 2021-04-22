#!/bin/bash

# make re
declare -i count=$(($1));
declare -i total=0; 
declare -i tmp=0;
declare -i min=1000000;
declare -i max=0;

coucou()
{
	./push_swap $arg | ./checker $arg;
}
bite()
{
	./push_swap $arg | wc -l
}

for i in $( eval echo {1..$count} )
	do 
		arg=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`;
		tmp=$(bite)
		if [ $tmp -gt $max ];
		then
			max=$tmp
		elif [ $tmp -lt $min ];
		then
			min=$tmp
		fi
		arg2=$(coucou)
		echo "$i / $count: $tmp | $arg2"
		total+=$tmp
	done

if [ $min -eq 1000000 ];
then
	min=0
fi

echo "min: $min"
echo "max: $max"

echo "scale=2; $total / $count" | bc
