/*
this is a implementation of bubble sort in c code.
By Wang Zihmin

usage:
//this bubble sort only take a interger array as input.
//given a interger array a[size].
bubble_sort(a,size,'m');
//after calling bubble_sort(a,size,'m'),array a[size] will be sorted in an increasing order.

bubble_sort(a,size,'M');
//after calling bubble_sort(a,size,'M'),array a[size] will be sorted in an decreasing order.




*/
#include<stdio.h>
void bubble_sort(int *head,int size,char version){
	
	if(version=='M'){
		for(int iii=0;iii<size-1;iii++){
			for(int ooo=0;ooo<(size-1-iii);ooo++){
				if(head[ooo]<head[ooo+1]){
					int temp=head[ooo];
					head[ooo]=head[ooo+1];
					head[ooo+1]=temp;
				}


			}


		}



	}
	else if(version=='m'){
		for(int iii=0;iii<size-1;iii++){
			for(int ooo=0;ooo<(size-1-iii);ooo++){
				if(head[ooo]>head[ooo+1]){
					int temp=head[ooo];
					head[ooo]=head[ooo+1];
					head[ooo+1]=temp;
				}


			}


		}



	}



return;
}
