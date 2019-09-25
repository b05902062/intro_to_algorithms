#include"subarray.h"
namespace introToAlgo{

	
	//optimalSubarray return -1 on invalid argument, 1 otherwise.
	//Optimal subarray with the smallest start index is returned in outMax.
	//optimalSubarray runs in Theta(itemNum).

	//optimalSubarray for interger value.
	int optimalSubarrayInt(void * itemList,int itemNum,int itemSize,int (*value)(const void* item),introToAlgo::subarrayInt *outMax){
		
		if(itemList==0||itemNum<=0||itemSize<=0) return -1;

		//Some buffer and initialization.
		introToAlgo::subarrayInt &max=*outMax;
		max.value=value(itemList);
		max.start=0;
		max.end=0;
		introToAlgo::subarrayInt maxTail;
		
		if(max.value>=0){
			maxTail.value=max.value;
			maxTail.start=0;
			maxTail.end=0;
		}
		else{
			maxTail.value=0;
			maxTail.start=1;
			maxTail.end=0;
		}

		//iterate 
		for(int i=1;i<itemNum;i++){
			maxTail.end+=1;
			maxTail.value+=value((char*)itemList+i*itemSize);

			if(maxTail.value>max.value){
				max.value=maxTail.value;
				max.start=maxTail.start;
				max.end=maxTail.end;
			}

			if(maxTail.value<0){
				maxTail.value=0;
				maxTail.start=i+1;
			}
		}
		return 1;
	}

	//optimalSubarray for double value.
	int optimalSubarrayDouble(void * itemList,int itemNum,int itemSize,double (*value)(const void* item),introToAlgo::subarrayDouble *outMax){
		
		if(itemList==0||itemNum<=0||itemSize<=0) return -1;

		//Some buffer and initialization.
		introToAlgo::subarrayDouble &max=*outMax;
		max.value=value(itemList);
		max.start=0;
		max.end=0;
		introToAlgo::subarrayDouble maxTail;
		
		if(max.value>=0){
			maxTail.value=max.value;
			maxTail.start=0;
			maxTail.end=0;
		}
		else{
			maxTail.value=0;
			maxTail.start=1;
			maxTail.end=0;
		}

		//iterate
		for(int i=1;i<itemNum;i++){
			maxTail.end+=1;
			maxTail.value+=value((char*)itemList+i*itemSize);

			if(maxTail.value>max.value){
				max.value=maxTail.value;
				max.start=maxTail.start;
				max.end=maxTail.end;
			}

			if(maxTail.value<0){
				maxTail.value=0;
				maxTail.start=i+1;
			}
		}
		return 1;
	}

	//next algo


}
