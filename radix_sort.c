/*
This is a implementation of radix sort in c code.
By Wang Zihmin

usage:
//It only take a positive interger array as input.
//Given a positive interger array a[size].
radix_sort(a,size,'m');
//after calling radix_sort(a,size,'m'),
//positive interger array a[size] will be sorted in an increasing order.
radix_sort(a,size,'M');
//after calling radix_sort(a,size,'M'),
//positive interger array a[size] will be sorted in an decreasing order.



*/
#include<stdio.h>
#include<stdlib.h>
void radix_sort(int *head,int size,char version){

		
	if(version=='M'){	

		int flag=1;
		for(int ooo=0;flag!=0;ooo++){  

			
			int count_table[10]={0};
			int *current_position=(int*)malloc(sizeof(int)*size);

			int division=1;
			int ooo_copy=ooo;
			while(ooo_copy>0){
				division*=10;
				ooo_copy-=1;

			}
			flag=0;
			for(int iii=0;iii<size;iii++){
				current_position[iii]=(head[iii]/division)%10;
				flag+=current_position[iii];
			}

			for(int iii=0;iii<size;iii++){
				count_table[current_position[iii]]+=1;

			}
			for(int iii=8;iii>=0;iii--){
				count_table[iii]+=count_table[iii+1];

			}
			int *sorted=(int*)malloc(sizeof(int)*size);
			for(int iii=0;iii<size;iii++){
				sorted[iii]=0;
			}
			for(int iii=size-1;iii>=0;iii--){
				sorted[count_table[current_position[iii]]-1]=head[iii];
				count_table[current_position[iii]]-=1;

			}
			for(int iii=0;iii<size;iii++){
				head[iii]=sorted[iii];
			}
			free(sorted),free(current_position);
		}
	}
	else if(version=='m'){	

		int flag=1;
		for(int ooo=0;flag!=0;ooo++){  

			
			int count_table[10]={0};
			int *current_position=(int*)malloc(sizeof(int)*size);

			int division=1;
			int ooo_copy=ooo;
			while(ooo_copy>0){
				division*=10;
				ooo_copy-=1;

			}
			flag=0;
			for(int iii=0;iii<size;iii++){
				current_position[iii]=(head[iii]/division)%10;
				flag+=current_position[iii];
			}

			for(int iii=0;iii<size;iii++){
				count_table[current_position[iii]]+=1;

			}
			for(int iii=1;iii<10;iii++){
				count_table[iii]+=count_table[iii-1];

			}
			int *sorted=(int*)malloc(sizeof(int)*size);
			for(int iii=0;iii<size;iii++){
				sorted[iii]=0;
			}
			for(int iii=size-1;iii>=0;iii--){
				sorted[count_table[current_position[iii]]-1]=head[iii];
				count_table[current_position[iii]]-=1;

			}
			for(int iii=0;iii<size;iii++){
				head[iii]=sorted[iii];
			}
			free(sorted),free(current_position);
		}
	}



	return;
}
