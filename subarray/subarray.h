#ifndef SUBARRAY_H
#define SUBARRAY_H
namespace introToAlgo{

	
	//optimalSubarray return -1 on invalid argument, 1 otherwise.
	//Optimal subarray with the smallest start index is returned in outMax.
	//optimalSubarray runs in Theta(itemNum).

	//optimalSubarray for interger value.
	struct subarrayInt{
		int value;
		int start;
		int end;
	};
	int optimalSubarrayInt(void * itemList,int itemNum,int itemSize,int (*value)(const void* item),introToAlgo::subarrayInt *outMax);

	//optimalSubarray for double value.
	struct subarrayDouble{
		double value;
		int start;
		int end;
	};
	int optimalSubarrayDouble(void * itemList,int itemNum,int itemSize,double (*value)(const void* item),introToAlgo::subarrayDouble *outMax);
		

	//next algo


}

#endif
