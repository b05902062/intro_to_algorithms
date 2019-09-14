/*
This is a implementation of binary search tree with parent in c code.
By Wang Zihmin.

usage:

Tree_node* t=0;
//Write this line first.

add(input,&t);
//Add a node with the data being input into the tree.

prefix_print_tree(&t);
infix_print_tree(&t);
postfix_print_tree(&t);
//Three ways to print the tree.

is_in_tree(input,&t);
//Check whether input is in the tree or not.
//If it is in the tree, return address of the node that contains the data.
//If it is not in the tree, return 0.

get_max(&t);
//If there is no element in the tree, return 0.
//Otherwise return the address of the node with the maximum data.
get_min(&t);
//If there is no element in the tree, return 0.
//Otherwise return the address of the node with the minimum data.

delete_tree(input,&t);

//If the node doesn't exsist, this function will do nothing.

allocate_tree(&t);
//Please refer to the definition below.

*/

#include<stdio.h>
#include<stdlib.h>
typedef int user_def;
typedef struct tree_node{

	user_def data;
	struct tree_node* parent;
	struct tree_node* left_child;
	struct tree_node* right_child;


}Tree_node;

Tree_node* allocate_tree(Tree_node** t){

	(*t)=(Tree_node*)malloc(sizeof(Tree_node));
	(*t)->data=0;
	(*t)->parent=0;
	(*t)->left_child=0;
	(*t)->right_child=0;
	return (*t);
}
void add_tree(user_def input,Tree_node **t){

	if((*t)==0){
		  allocate_tree(t);
		  (*t)->data=input;
		  return;
	}
	else if(((*t)->data)==input) return;
	else if(((*t)->data)>input){
		
		add_tree(input,&((*t)->left_child));
		((*t)->left_child)->parent=(*t);
		return;
	}
	else if(((*t)->data)<input){
		
		add_tree(input,&((*t)->right_child));
		((*t)->right_child)->parent=(*t);
		return;
	}
}
void prefix_print_tree(Tree_node** t){

	if((*t)==0) return;
	else{
		  printf("%d\n",(*t)->data);
	}
	prefix_print_tree(&((*t)->left_child));
	prefix_print_tree(&((*t)->right_child));
	return;
}
void infix_print_tree(Tree_node**t){

	if((*t)==0) return;
	infix_print_tree(&((*t)->left_child));
	printf("%d\n",(*t)->data);
	infix_print_tree(&((*t)->right_child));
	return;

}
void postfix_print_tree(Tree_node**t){

	if((*t)==0) return;
	postfix_print_tree(&((*t)->left_child));
	postfix_print_tree(&((*t)->right_child));
	printf("%d\n",(*t)->data);
	return;
}
Tree_node* is_in_tree(user_def input,Tree_node**t){

	if((*t)==0) return *t;
	if(input==((*t)->data)) return (*t);
	if(input<((*t)->data)) return is_in_tree(input,&((*t)->left_child));
	if(input>((*t)->data)) return is_in_tree(input,&((*t)->right_child));
}
Tree_node* get_max(Tree_node**t){
	if((*t)==0) return *t;
	Tree_node* max=(*t);
	while(max->right_child!=0) max=max->right_child;
	return max;

}
Tree_node* get_min(Tree_node**t){
	if((*t)==0) return *t;
	Tree_node* min=(*t);
	while(min->left_child!=0) min=min->left_child;
	return min;
	
}
void delete_tree(user_def input,Tree_node**t){

	Tree_node*address=is_in_tree(input,t);
	if(!address) return;
	Tree_node*parent=address->parent;
	if(address->left_child==0&&address->right_child==0){
		if(parent==0){//There is only a node in the tree.
			free(address);
			*t=0;
			return;
		}

		if(address==parent->left_child) parent->left_child=0;
		else parent->right_child=0;
		free(address);
		return;

	}
	else if(address->left_child==0||address->right_child==0){
		if((address->left_child)!=0){
			Tree_node*temp=address->left_child;
			address->data=temp->data;
			address->left_child=temp->left_child;
			address->right_child=temp->right_child;
			free(temp);
			if(address->left_child!=0) 
			 (address->left_child)->parent=address;
			if(address->right_child!=0) 
			 (address->right_child)->parent=address;
			return;

		}
		else{
			Tree_node*temp=address->right_child;
			address->data=temp->data;
			address->left_child=temp->left_child;
			address->right_child=temp->right_child;
			free(temp);
			if(address->left_child!=0)
			 (address->left_child)->parent=address;
			if(address->right_child!=0) 
			 (address->right_child)->parent=address;
			return;
		}

	}
	else{
		Tree_node*max=get_max(&(address->left_child));
		address->data=max->data;
		if(max->parent==address){
			if(max->left_child==0){
				address->left_child=0;
				free(max);
				return;

			}
			else{
				address->left_child=max->left_child;
				(max->left_child)->parent=address;
				free(max);
				return;
			}
		}
		else{
			if(max->left_child==0){
				(max->parent)->right_child=0;
				free(max);
				return;
			}
			else{
				max->data=(max->left_child)->data;
				free(max->left_child);
				max->left_child=0;
				return;
			}
		}
	}




}
/*
int main(){
	  
Tree_node* t=0;
add_tree(77,&t);
add_tree(5,&t);
add_tree(90,&t);
add_tree(1,&t);
add_tree(80,&t);
add_tree(95,&t);
delete_tree(95,&t);
printf("%d\n",(is_in_tree(80,&t)->parent)->data);
return 0;	  
}
*/
