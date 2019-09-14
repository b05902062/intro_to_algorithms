/*


usage:

Stack s;
set_size_and_initialize(&s,size)
//the size you want, it can't be zero.
//remember to change the user_define type, eg int, char,char by default.
push(&s,item);
//push an item into the stack.
pop(&s);
//pop the stack.
is_empty(&s);
//return 1 if empty,0 if not empty.
peak(&s);
//pop(&s) without deleting the element.
free_Stack(&s);
//after using the stack use free_stack(&s) to free the memory being used.
//if you want to use it again use set_size_and_initialize(&s,size) directly,
//dont need to declare a new Stack.


//it is a stack that would reallocate memory if it is needed.
by Wang Zihmin
*/
#include<stdlib.h>
#include<assert.h>
typedef char user_define;
typedef struct stack{

	user_define *pointer;
	int index;
	int size;
}Stack;

void set_size_and_initialize(Stack* s,int size){

	s->pointer=(user_define*)malloc(sizeof(user_define)*size);
	assert(s->pointer!=0);
	s->index=0;	
	s->size=size;
}
void free_Stack(Stack*s){

	if(s->pointer!=0){
		free(s->pointer);
		s->pointer=0;
		s->index=0;		
	}
return;
}
void push(Stack*s,user_define item){
	
	if(s->index==s->size){
		s->pointer=realloc(s->pointer,s->size*2);
		assert(s->pointer!=0);
		s->size*=2;
	}
	s->pointer[s->index]=item;
	s->index+=1;
}
user_define pop(Stack*s){

	assert(s->index!=0);
	s->index-=1;
	return s->pointer[s->index];



}
user_define peak(Stack*s){

	if(s->index!=0){
		return s->pointer[(s->index)-1];
	}
	else assert(s->index!=0);
}

int is_empty(Stack*s){

	return !(s->index);
}
