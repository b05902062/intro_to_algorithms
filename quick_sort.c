/*
This is a implementation of quick sort in c code.
By Wang Zihmin.

usage:
//This sorting algorithm only takes an array of intergers as its input.
//Given an array of intergers array[size].
quick_sort(array,size,'m');
//After calling quick_sort(array,size,'m'), array[size] will be sorted in an increasing order.
quick_sort(array,size,'M');
//After calling quick_sort(array,size,'M'), array[size] will be sorted in an decreasing order.

*/

#include<stdio.h>
void quick_sort(int *head,int size,char version){

if(version=='M'){

	if((size==0)||(size==1)) return;

	int pivot=head[0];
	int front=1;
	int end=size;
	int flag=0;
	
	while(1){
		flag=0;
		while(front<end){
			if(head[front]>=pivot){
				front+=1;
			}
			else{
				flag=1;
				break;
			}
		};
		if(flag==0) break;
		while(end>(front+1)){
			end-=1;
			if(head[end]>pivot){
				int temp=head[end];
				head[end]=head[front];
				head[front]=temp;
				front+=1;
				flag=2;
				break;
			}
		}
		if(flag==1) break;
	}
	for(int iii=0;iii<(front-1);iii++){
		head[iii]=head[iii+1];
	}
	head[front-1]=pivot;
	quick_sort(head,front-1,version);
	quick_sort(head+front,size-front,version);
}
if(version=='m'){

	if((size==0)||(size==1)) return;

	int pivot=head[0];
	int front=1;
	int end=size;
	int flag=0;
	
	while(1){
		flag=0;
		while(front<end){
			if(head[front]<=pivot){
				front+=1;
			}
			else{
				flag=1;
				break;
			}
		};
		if(flag==0) break;
		while(end>(front+1)){
			end-=1;
			if(head[end]<pivot){
				int temp=head[end];
				head[end]=head[front];
				head[front]=temp;
				front+=1;
				flag=2;
				break;
			}
		}
		if(flag==1) break;
	}
	for(int iii=0;iii<(front-1);iii++){
		head[iii]=head[iii+1];
	}
	head[front-1]=pivot;
	quick_sort(head,front-1,version);
	quick_sort(head+front,size-front,version);
}


return;
}
