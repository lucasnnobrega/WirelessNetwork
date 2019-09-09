count=0
for ((i = 0; i < 90; i++))
do
	num1=$(( i / 15 ))
	num2=$(( (i/5) % 3 ))	

	case $num1 in 
		0) n=5;;	
		1) n=7;;	
		2) n=9;;	
		3) n=11;;	
		4) n=13;;	
		5) n=15;;	
	esac

	case $num2 in 
		0) tmax=$((n*2));;	
		1) tmax=$((n*3));;	
		2) tmax=$((n*4));;	
	esac

	insNumber1=`printf "%03d" $((i+1))`
	insNumber2=$((i%5 + 1))
#	n=`printf "%02d" $n`

	echo ins_$n'_'$tmax'_'$insNumber2.txt

	mv ins$insNumber1.txt ins_$n'_'$tmax'_'$insNumber2.txt
done
echo Feito.
