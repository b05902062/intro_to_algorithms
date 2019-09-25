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


	double itemList[5]={3,2,6,100,-1};
	//have to check invalid input.(omitted)

	//run sorting here.
	introToAlgo::mergeSort(itemList,5,sizeof(double),exampleDoubleComparator);
	//introToAlgo::bubbleSort(itemList,5,sizeof(double),exampleDoubleComparator);
	//introToAlgo::insertionSort(itemList,5,sizeof(double),exampleDoubleComparator);


	//print result.
	for(int i=0;i<5;i++){
		printf("%lf ",itemList[i]);

	}
	printf("\n");

	return 0;
}
