/*
This is a implementation of counting sort in c code.
By Wang Zihmin

usage:

//given an integer array a[size] with elements being from 0 to b-1.
counting_sort(a,size,b,'m');
//after calling counting_sort(a,size,b,'m'),array a will be sorted in an increasing order.

counting_sort(a,size,b,'M');
//after calling counting_sort(a,size,b,'M'),array a will be sorted in an decreasing order.

example:

int main(){

	int array[15]={3,5,7,6,7,2,4,5,6,7,1,1,2,0,1};
	counting_sort(array,15,8,'M');
	for(int iii=0;iii<15;iii++){
		printf("%d ",array[iii]);

	}

	return 0;
}


*/
#include<stdio.h>
#include<stdlib.h>
void counting_sort(int *head,int size,int possibility,char version){
	
if(version=='m'){	
	int *count_table=(int*)malloc(sizeof(int)*possibility);
	for(int iii=0;iii<possibility;iii++){
		count_table[iii]=0;

	}
	for(int iii=0;iii<size;iii++){
		count_table[head[iii]]+=1;

	}
	for(int iii=1;iii<possibility;iii++){
		count_table[iii]+=count_table[iii-1];

	}
	int *sorted=(int*)malloc(sizeof(int)*size);
	for(int iii=0;iii<size;iii++){
		sorted[iii]=0;
	}
	for(int iii=size-1;iii>=0;iii--){
		sorted[count_table[head[iii]]-1]=head[iii];
		count_table[head[iii]]-=1;

	}
	for(int iii=0;iii<size;iii++){
		head[iii]=sorted[iii];
	}
	free(count_table),free(sorted);


}
else if(version=='M'){	
	int *count_table=(int*)malloc(sizeof(int)*possibility);
	for(int iii=0;iii<possibility;iii++){
		count_table[iii]=0;

	}
	for(int iii=0;iii<size;iii++){
		count_table[head[iii]]+=1;

	}
	for(int iii=possibility-2;iii>=0;iii--){
		count_table[iii]+=count_table[iii+1];

	}
	int *sorted=(int*)malloc(sizeof(int)*size);
	for(int iii=0;iii<size;iii++){
		sorted[iii]=0;
	}
	for(int iii=size-1;iii>=0;iii--){
		sorted[count_table[head[iii]]-1]=head[iii];
		count_table[head[iii]]-=1;

	}
	for(int iii=0;iii<size;iii++){
		head[iii]=sorted[iii];
	}
	free(count_table),free(sorted);
}


return;
}
