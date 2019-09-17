#include<stdio.h>
#include<stdlib.h>
#include"sorting.h"

//The same as the comparator for qsort in <stdlib.h>. Return 1 means p1 will appear after p2 after sorted. whereas return -1 means p1 will appear before p2 after sorted.
int exampleDoubleComparator(const void*p1,const void*p2){

	/*
	//acending order
	if(*(double*)p1>*(double*)p2) return 1;
	else return -1;
	*/
	

	//decending order
	if(*(double*)p1>*(double*)p2) return -1;
	else return 1;

	
}
	
int main(){

	//acquire input.
	printf("How many items?\n");
	int itemNum;
	scanf("%d",&itemNum);

	double *itemList=(double*)malloc(sizeof(double)*itemNum);
	printf("Enter the itmes.\n");
	for(int i=0;i<itemNum;i++){
		scanf("%lf",&itemList[i]);
	}

	//have to check invalid input.(omitted)

	//run sorting here.
	introToAlgo::insertionSort(itemList,itemNum,sizeof(double),exampleDoubleComparator);


	//print result.
	for(int i=0;i<itemNum;i++){
		printf("%lf ",itemList[i]);

	}
	printf("\n");

	free(itemList);
	itemList=0;
	return 0;
}
