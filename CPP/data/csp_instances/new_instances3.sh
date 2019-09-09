for i in 5 7 9 11 13 15
do
	for j in 2 3 4
	do
		for k in $(seq 5)
		do
			n=`printf "%02d" $i`
			tmax=$((i*j))

			echo ins_$i'_'$tmax'_'$k.txt

			mv ins_$i'_'$tmax'_'$k.txt ins_$n'_'$tmax'_'$k.txt
		done
	done
done

echo Feito.
