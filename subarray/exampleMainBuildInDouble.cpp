#include<iostream>
#include"subarray.h"

//if your want your value to be floating point number please use introToAlgo::subarrayDouble and introToAlgo::optimalSubarrayDouble().
double exampleValue(const void* item){
	double value=*(double*)item;
	return value;

}

int main(){

	double array[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	
	introToAlgo::subarrayDouble max;
	introToAlgo::optimalSubarrayDouble(array,16,sizeof(double),exampleValue,&max);
	//optimal array is from array[max.start] to array[max.end] inclusive of both ends.
	std::cout<<"value"<<max.value<<"start"<<max.start<<"end"<<max.end<<'\n';

}




