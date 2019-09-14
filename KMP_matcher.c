/*
This is a implementation of KMP string matching algorithm in c code.
By Wang Zihmin.

usage:

prefix_function(template,size,pi);
//Template is the address of the template array.
//Size is the size of the template array.
//Pi is an array declared outside of this function.
//And pi is used to store the result of this function.
//Pi should have the same size as the template.
//Size doesn't include terminator.

KMP_matcher(string,s_size,template,t_size);
//This function will return the number of valid shifts,
//For example, there are 5 valid shifts, it would return 5.
//The number of valid shifts is equal to the number of times template occurs in the string.
//S_size and t_size refer to the size of string and template repectively.
//S_size and t_size doesn't include terminator.


*/

#include<stdio.h>
#include<stdlib.h>
void prefix_function(char *template,int size,int *pi){

	int index=0;
	pi[0]=0;
	for(int iii=1;iii<size;iii++){
		
		while(1){
		
			if(template[iii]==template[index]){
				index+=1;
				break;
			}
			if(index==0) break;
			index=pi[index-1];
		}
		pi[iii]=index;
	}
	return;
}
int KMP_matcher(char* string,int s_size,char*template,int t_size){

	int *pi=(int*)malloc(sizeof(int)*t_size);
	prefix_function(template,t_size,pi);

	int number=0;
	int index=0;
	for(int iii=0;iii<s_size;iii++){
		
		while(1){
			if(string[iii]==template[index]){
				index+=1;
				break;
			}
			if(index==0) break;
			index=pi[index-1];

		}
		if(index==t_size){
			number+=1;
			index=pi[t_size-1];
		
		}
	}
	return number;



}
int main(){
/*

//for debuging prefix_function;
char template[12]={1,2,1,2,1,3,1,2,1,2,1,2};
int pi[12];
prefix_function(template,12,pi);
for(int iii=0;iii<12;iii++){
	printf("%d ",pi[iii]);

}
*/

int number1=KMP_matcher("aaabcabaa",9,"ab",2);
printf("%d",number1);

}




