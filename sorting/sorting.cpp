/*
Implementation of some simple algorithms.
By Wang zihmin@National Taiwan university 2019.

*/


#include"sorting.h"
#include<string.h>
#include<stdlib.h>
namespace introToAlgo{

	//bubble sort.
	void bubbleSort(void *itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*)){

		char *temp=(char*)malloc(itemSize);
		for(int i=itemNum;i>1;i--){
				
			for(int o=0;o<i-1;o++){
				if(comparator((char*)itemList+o*itemSize,(char*)itemList+(o+1)*itemSize)>0){
					
					memcpy(temp,(char*)itemList+o*itemSize,itemSize);
					memcpy((char*)itemList+o*itemSize,(char*)itemList+(o+1)*itemSize,itemSize);
					memcpy((char*)itemList+(o+1)*itemSize,temp,itemSize);

				}
			}
		}
		return;
	}


	//






}
