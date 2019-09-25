#include<iostream>
#include"subarray.h"

//if your want your value to be interger please use introToAlgo::subarrayInt and introToAlgo::optimalSubarrayInt().
int exampleValue(const void* item){
	//if you pass an interger array pointer to optimalSubarray,i you can think of the item as being a interger pointer. We acquire its value and return it.
	int value=*(int*)item;
	return value;

}
int main(){

	int array[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	
	introToAlgo::subarrayInt max;
	introToAlgo::optimalSubarrayInt(array,16,sizeof(int),exampleValue,&max);
	//optimal array is from array[max.start] to array[max.end] inclusive of both ends.
	std::cout<<"value"<<max.value<<"start"<<max.start<<"end"<<max.end<<'\n';

}




