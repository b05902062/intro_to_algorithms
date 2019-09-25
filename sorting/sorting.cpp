/*
Implementation of some simple algorithms.
By Wang zihmin@National Taiwan university 2019.

*/


#include"sorting.h"
#include<string.h>
#include<stdlib.h>
namespace introToAlgo{

	//bubble sort.
	int bubbleSort(void *itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*)){
		
		if(itemList==0||itemNum<=0||itemSize<=0) return -1;
		char *temp=(char*)malloc(itemSize);
		if(temp==0) return -1;
		
		for(int i=itemNum;i>1;i--){
				
			for(int o=0;o<i-1;o++){
				if(comparator((char*)itemList+o*itemSize,(char*)itemList+(o+1)*itemSize)>0){
					
					memcpy(temp,(char*)itemList+o*itemSize,itemSize);
					memcpy((char*)itemList+o*itemSize,(char*)itemList+(o+1)*itemSize,itemSize);
					memcpy((char*)itemList+(o+1)*itemSize,temp,itemSize);

				}
			}
		}
		free(temp);
		temp=0;
		return 1;
	}


	//Insertion sort
	int insertionSort(void *itemList,int itemNum,int itemSize,int (*comparator)(const void*,const void*)){
		if(itemList==0||itemNum<=0||itemSize<=0) return 1;
		void* key=(void*)malloc(itemSize);
		if(key==0) return -1;
		
		for(int i=1;i<itemNum;i++){
			memcpy(key,(char*)itemList+i*itemSize,itemSize);

			for(int o=i-1;o>=-1;o--){
				if(o==-1|| (comparator(key,(char*)itemList+o*itemSize)>0)){
					memcpy((char*)itemList+(o+1)*itemSize,key,itemSize);
					break;

				}
				else{
					memcpy((char*)itemList+(o+1)*itemSize,(char*)itemList+o*itemSize,itemSize);
						
				}
			}
		}
		free(key);
		key=0;
		return 1;
	}

	//merge sort.
	int mergeSort(void*itemList,int itemNum,int itemSize,int (*compare)(const void*,const void*)){
		if(itemList==0||itemNum<=0||itemSize<=0) return 1;
		void* temp=(void*)malloc(itemNum*itemSize);
		if(temp==0) return -1;
		
		__mergeSort(itemList,0,itemNum-1,itemSize,compare,temp);
		free(temp);
		temp=0;
		return 1;
	}

	static void __mergeSort(void*itemList,int strIndex,int endIndex,int itemSize,int (*compare)(const void*,const void*),void*temp){
		
		const int itemNum=endIndex-strIndex+1;
		//termination condition.
		if(itemNum==1) return;

		//first half is from index strIndex to fstEndIndex(both included)
		const int fstEndIndex=strIndex+(itemNum/2)-1;
		//first half is from index sndStrIndex to endIndex(both included)
		const int sndStrIndex=strIndex+(itemNum/2);

		__mergeSort(itemList,strIndex,fstEndIndex,itemSize,compare,temp);
		__mergeSort(itemList,sndStrIndex,endIndex,itemSize,compare,temp);

		__merge(itemList,strIndex,endIndex,itemSize,compare,temp);
		return;
	}

	static void __merge(void*itemList,int strIndex,int endIndex,int itemSize,int (*compare)(const void*,const void*),void*temp){
			
		const int itemNum=endIndex-strIndex+1;
		
		//first half is from index strIndex to fstEndIndex(both included)
		const int fstEndIndex=strIndex+(itemNum/2)-1;
		//first half is from index sndStrIndex to endIndex(both included)
		const int sndStrIndex=strIndex+(itemNum/2);
		
		
		int fstCurIndex=strIndex;
		int sndCurIndex=sndStrIndex;
		int alreadyCopy=0;

		while(alreadyCopy<itemNum){
			
			if( (sndCurIndex>endIndex) || ( fstCurIndex<=fstEndIndex && compare((char*)itemList+fstCurIndex*itemSize,(char*)itemList+sndCurIndex*itemSize)<0 ) ){

				memcpy((char*)temp+alreadyCopy*itemSize,(char*)itemList+fstCurIndex*itemSize,itemSize);
				fstCurIndex++;
				alreadyCopy++;

			}
			else{

				memcpy((char*)temp+alreadyCopy*itemSize,(char*)itemList+sndCurIndex*itemSize,itemSize);
				sndCurIndex++;
				alreadyCopy++;

			}
			
		}
		memcpy((char*)itemList+strIndex*itemSize,temp,itemSize*itemNum);			
		return;
	}


}
