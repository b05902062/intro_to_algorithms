/*
This is a implementation of merge sort in c code.
By Wang Zihmin.

usage:
//This algorithm take a array of interger as input.
//Given an interger array a[size].
merge_sort(a,size,'m');
//After calling merge_sort(a,size,'m'), interger array a[size] will be sorted in an increasing order.
merge_sort(a,size,'M');
//After calling merge_sort(a,size,'m'), interger array a[size] will be sorted in an decreasing order.

*/

#include<stdio.h>
#include<stdlib.h>
void merge_sort_component(int *head1,int size1,char version,int *head2,int size2){

if(version=='M'){
	if(size2>1){
		int size2_half=(size2/2);
		merge_sort_component(head2,size2_half,version,
		 head2+size2_half,size2-size2_half);
		
	}
	if(size1>1){
		int size1_half=(size1/2);
		merge_sort_component(head1,size1_half,version,
		 head1+size1_half,size1-size1_half);
		
	}
	int *temp=(int*)malloc(sizeof(int)*(size1+size2));
	for(int iii=0,h1=0,h2=0;iii<(size1+size2);iii++){
		if(head1[h1]>head2[h2]){
			temp[iii]=head1[h1];
			h1+=1;
		
		}
		else{
			temp[iii]=head2[h2];
			h2+=1;
		}
		if(h1>=size1){
			for(int ooo=0;ooo+h2<size2;ooo++){
				temp[iii+ooo+1]=head2[ooo+h2];

			}
			break;
		}
		if(h2>=size2){
			for(int ooo=0;ooo+h1<size1;ooo++){
				temp[iii+ooo+1]=head1[ooo+h1];

			}
			break;
		}
	}

	for(int iii=0;iii<(size1+size2);iii++){
		head1[iii]=temp[iii];	
	}
	free(temp);
	temp=0;





}
if(version=='m'){
	if(size2>1){
		int size2_half=(size2/2);
		merge_sort_component(head2,size2_half,version,
		 head2+size2_half,size2-size2_half);
		
	}
	if(size1>1){
		int size1_half=(size1/2);
		merge_sort_component(head1,size1_half,version,
		 head1+size1_half,size1-size1_half);
		
	}
	int *temp=(int*)malloc(sizeof(int)*(size1+size2));
	for(int iii=0,h1=0,h2=0;iii<(size1+size2);iii++){
		if(head1[h1]<head2[h2]){
			temp[iii]=head1[h1];
			h1+=1;
		
		}
		else{
			temp[iii]=head2[h2];
			h2+=1;
		}
		if(h1>=size1){
			for(int ooo=0;ooo+h2<size2;ooo++){
				temp[iii+ooo+1]=head2[ooo+h2];

			}
			break;
		}
		if(h2>=size2){
			for(int ooo=0;ooo+h1<size1;ooo++){
				temp[iii+ooo+1]=head1[ooo+h1];

			}
			break;
		}
	}

	for(int iii=0;iii<(size1+size2);iii++){
		head1[iii]=temp[iii];	
	}
	free(temp);
	temp=0;





}

return;
}

void merge_sort(int* head,int size,char version){

	merge_sort_component(head,size-1,version,head+size-1,1);
	return;

}
