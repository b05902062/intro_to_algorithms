#ifndef SORTING_H
#define SORTING_H 

namespace introToAlgo{

	//return -1 on error, 1 otherwise.
	int bubbleSort(void*itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*));

	int insertionSort(void *itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*));

	int mergeSort(void*itemList,int itemNum,int itemSize,int (*compare)(const void*,const void*));

	static void __mergeSort(void*itemList,int strIndex,int endIndex,int itemSize,int (*compare)(const void*,const void*),void*temp);
	static void __merge(void*itemList,int strIndex,int endIndex,int itemSize,int (*compare)(const void*,const void*),void* temp);

}

#endif
