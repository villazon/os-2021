all:
	echo "options: get-pid father-son gets-sample strtok-sample fork-wait" 

gets-sample: gets-sample.c
	gcc gets-sample.c -o gets-sample

strtok-sample: strtok-sample.c
	gcc strtok-sample.c -o strtok-sample

get-pid: get-pid.c
	gcc get-pid.c -o get-pid

father-son: father-son.c
	gcc father-son.c -o father-son

for-wait: fork-wait
	gcc fork-wait.c -o fork-wait

clean:
	rm -rf *~ a.out father-son get-pid strtok-sample  gets-sample fork-wait
