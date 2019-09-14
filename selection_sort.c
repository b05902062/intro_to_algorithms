/*
this is a implementation of selection sort in c code.
By Wang Zihmin

usage:
//it only take a interger array as input.
//given a interger array a[size].
selection_sort(a,size,'m');
//after calling selection_sort(a,size,'m'), array a[size] will be sorted in an increasing order.
selection_sort(a,size,'M');
//after calling selection_sort(a,size,'M'), array a[size] will be sorted in an decreasing order.



*/
#include<stdio.h>
void selection_sort(int *head,int size,char version){

	if(version=='M'){
		for(int iii=0;iii<size;iii++){
			int max=head[iii];
			int index=iii;
			for(int ooo=iii+1;ooo<size;ooo++){
				if(head[ooo]>max) max=head[ooo],index=ooo;
				  
			}
			head[index]=head[iii];
			head[iii]=max;


		}
	}
	if(version=='m'){
		for(int iii=0;iii<size;iii++){
			int min=head[iii];
			int index=iii;
			for(int ooo=iii+1;ooo<size;ooo++){
				if(head[ooo]<min) min=head[ooo],index=ooo;
				  
			}
			head[index]=head[iii];
			head[iii]=min;


		}
	}
return;
}
