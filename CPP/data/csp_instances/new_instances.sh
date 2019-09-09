count=0
for i in 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90
do
	for ((j = $((72 + count)); j >= $i; j--))
	do
		insNumber1=`printf "%03d" $j`
		insNumber2=`printf "%03d" $((j+1))`

		mv ins$insNumber1.txt ins$insNumber2.txt

	done
	count=$((count + 1)) # let count++
done
