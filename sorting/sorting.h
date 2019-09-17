#ifndef SORTING_H
#define SORTING_H 

namespace introToAlgo{


	void bubbleSort(void*itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*));

	void insertionSort(void *itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*));



}

#endif
