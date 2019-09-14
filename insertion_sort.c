/*
this is a implementation of insertion sort in c code.
By Wang Zihmin

//this insertion sort only take an interger array as input.
//given a interger array a[size].
insertion_sort(a,size,'m');
//after calling insertion_sort(a,size,'m'),a will be sorted in an increasingorder.

insertion_sort(a,size,'M');
//after calling insertion_sort(a,size,'M'),a will be sorted in an decreasingorder.
*/

#include<stdio.h>
void insertion_sort(int *head,int size,char version){
	
	if(version=='M'){
		for(int iii=1;iii<size;iii++){
			int flag=0;
			for(int ooo=iii-1;ooo>=0;ooo--){
				if(head[iii]<head[ooo]){
					int temp=head[iii];
					for(int zzz=iii;zzz>ooo+1;zzz--){
						head[zzz]=head[zzz-1];

					}
					head[ooo+1]=temp;
					flag=1;		
					break;
				}


			}
			if(flag==0){
				int temp=head[iii];
				for(int ooo=iii;ooo>=1;ooo--){
					head[ooo]=head[ooo-1];

				}
				head[0]=temp;

			}

		}



	return;
	}

	if(version=='m'){
		for(int iii=1;iii<size;iii++){
			int flag=0;
			for(int ooo=iii-1;ooo>=0;ooo--){
				if(head[iii]>head[ooo]){
					int temp=head[iii];
					for(int zzz=iii;zzz>ooo+1;zzz--){
						head[zzz]=head[zzz-1];

					}
					head[ooo+1]=temp;
					flag=1;		
					break;
				}


			}
			if(flag==0){
				int temp=head[iii];
				for(int ooo=iii;ooo>=1;ooo--){
					head[ooo]=head[ooo-1];

				}
				head[0]=temp;

			}

		}



	return;
	}


}
