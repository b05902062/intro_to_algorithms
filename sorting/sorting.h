#ifndef SORTING_H
#define SORTING_H 

namespace introToAlgo{


	void bubbleSort(void*itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*));

	void insertionSort(void *itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*));

	void mergeSort(void*itemList,int itemNum,int itemSize,int (*compare)(const void*,const void*));

	static void __mergeSort(void*itemList,int strIndex,int endIndex,int itemSize,int (*compare)(const void*,const void*),void*temp);
	static void __merge(void*itemList,int strIndex,int endIndex,int itemSize,int (*compare)(const void*,const void*),void* temp);

}

#endif
