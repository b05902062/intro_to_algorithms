/*
This is a implementation of queue in c code.

usage:

Queue q;
//create a queue.

void initialize_queue(size,&q);
//initialize the queue with the number of the elements you want to put into it.

int is_full(&q);
//return 1 if full;0 otherwise.

int is_empty(&q);
//return 1 if empty;0 otherwise.

void enqueue(input,&q);
//put input into the queue.

userdef dequeue(&q);
//pop the queue.


//
int main(){
Queue q;
initialize_queue(5,&q);

printf("%d\n",is_empty(&q));
enqueue(10,&q);
enqueue(10,&q);
enqueue(10,&q);
enqueue(10,&q);
enqueue(10,&q);
enqueue(10,&q);
printf("%d\n",is_full(&q));

dequeue(&q);
return 0;
}
//

By Wang Zihmin.
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int userdef;
typedef struct queue{
	int size;
	int head;
	int tail;
	userdef *root;
}Queue;
void initialize_queue(int size,Queue*q){
	q->root=(userdef*)malloc(sizeof(userdef)*(size+1));
	q->size=size+1;
//allocate memory that is one size bigger than what the user demands,for boundary checking.
	q->head=0;
	q->tail=0;	
	return;
}
int is_empty(Queue*q){
	if(q->head==q->tail) return 1;
	else return 0;

}
int is_full(Queue*q){
	if(((q->tail)+1)%(q->size)==q->head) return 1;
	else return 0;
}
void enqueue(userdef input,Queue*q){
	assert((((q->tail)+1)%(q->size))!=q->head);
	*((q->root)+(q->tail))=input;
	q->tail+=1;
	q->tail%=(q->size);
	return;
}
userdef dequeue(Queue*q){
	assert((q->head)!=q->tail);
	int temp=q->head;	
	q->head+=1;
	q->head%=q->size;
	return *((q->root)+temp);
	
}

