#include<iostream>
#include"subarray.h"

//define value to be the sum of the first two element.
struct exampleStruct{
	int a;
	int b;
	int c;

};
int exampleValue(const void* item){
	//item is a pointer to your structure. So, first we get the sum of the first two elements. Then we return it.
	int value=((struct exampleStruct*)item)->a+((struct exampleStruct*)item)->b;
	return value;

}

int main(){

	struct exampleStruct array[5]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4};
	
	introToAlgo::subarrayInt max;
	introToAlgo::optimalSubarrayInt(array,5,sizeof(struct exampleStruct),exampleValue,&max);
	//optimal array is from array[max.start] to array[max.end] inclusive of both ends.
	std::cout<<"value"<<max.value<<"start"<<max.start<<"end"<<max.end<<'\n';

}


