#include<stdio.h>
#include<stdlib.h>
//Wersja zachłanna
int compare(const void* a, const void* b){
	return(*(int*)a - *(int*)b);
}
int main(int argc, char* argv[])
{
	FILE* file;
	file = fopen("monety.txt", "r"); //otwieram plik
	int give = 0, amounttogive = 0, arsize = 0, counter = 0;
	int topick;
	fscanf(file, "%d", &arsize);
	if(arsize <=0){ printf("zla dana"); return 0;}
	//printf("%d ", arsize);
	int monety[arsize]; //monety trzymam w tablicy
	while(counter != arsize){ //uzupelniam tablicę
		fscanf(file, "%d", &monety[counter]);
		if(monety[counter] < 0){
		printf("zla dana");
		return 0;
		}
	//	printf("%d ", monety[counter]);
		++counter;
	}
	fscanf(file, "%d", &amounttogive);
	//printf("%d\n", amounttogive);
	qsort(monety, arsize, sizeof(int), compare);
	topick = arsize - 1;
	while(1){
		if(topick < 0 && give!=amounttogive){
			printf("\nCan't be done, result is: %d", give); 
			break;
		}
		if((monety[topick] + give) <= amounttogive){
				give = give + monety[topick];
				printf("%d ", monety[topick]);
		}
		else{
			topick = topick - 1;
		}
		if(give == amounttogive){
			printf("\ndone");
			break;
		}
}
return 0;
}