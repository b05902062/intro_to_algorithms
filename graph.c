/*
This is a implementation of graph in c code.

usage:

Path**root=initialize_graph(number);
//number is the number of vertices. 

add_directed_path(a,b,cost,root);
//Use this function to creat a graph that allows atmost two paths between two vertices one from a to b,and the other from b to a.
//root is the Path** created above.
//a and b is the index of the vertices which are both in the range of 0to number-1.
//This function creats a directed path from a to b.
//You can specify the cost of this path, if you don't need it simply specify 1. 
//If path has other name, you can implement a function that changes names into numbers.

By Wang Zihmin.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct path{
	int destination;
	int cost;
	struct path* next;
}Path;
Path** initialize_graph(int number);
Path* initialize_path(int destination,int cost);
void add_directed_path(int a,int b,int cost,Path**root);

int main(){

Path**root=initialize_graph(5);

add_directed_path(0,4,20,root);
add_directed_path(0,3,50,root);
add_directed_path(4,3,50,root);
Path*pointer=*(root+4);
//pointer=pointer->next;
printf("%d %d\n",(pointer)->destination,(pointer)->cost);

return 0;
	
}
Path** initialize_graph(int number){
#ifdef debug1
printf("1");
#endif

	Path**root=(Path**)malloc(sizeof(Path*)*number);
	for(int iii=0;iii<number;iii++){
		*(root+iii)=0;
	}
#ifdef debug1
printf("1");
#endif

	return root;
}
Path* initialize_path(int destination,int cost){
	Path* current=(Path*)malloc(sizeof(Path));
	current->next=0;
	current->cost=cost;
	current->destination=destination;
	return current;
}

void add_directed_path(int a,int b,int cost,Path**root){
	Path*current=*(root+a);
	if(current==0){
		*(root+a)=initialize_path(b,cost);
		return;	 		 
	}
	else{
		while((current->destination)!=b&&(current->next)!=0){
			current=current->next;
		}
		if((current->destination)==b){
			current->cost=cost;
			return;
		}
		else{
			current->next=initialize_path(b,cost);
			return;
		}
	}
}
