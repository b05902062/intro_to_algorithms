/*
This is a implementation of red black tree with parent in c code.
By Wang Zihmin.

usage:

Tree_node* t=0;
//Write this line first.

add_red_black_tree(input,&t);
//Add a node with the data being input into the rb-tree.

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

delete_red_black_tree(input,&t);
//If there is a node whose data is equal to the input, delete the node.
//If the node doesn't exsist, this function will do nothing.

rotate_tree(address,&t);
//The address is the address of the node you want to rotate.
//Don't need to specify whether to right- or left-rotate.
//Return value is the address itself.

adjust_after_addition(address,&t);
//The address is the address of the node being added.
//Return void.

adjust_after_deletion(address,&t);
//The address is the address of the sibling of the node being deleted.
//Return void.

allocate_tree(&t);
add_tree(input,&t);
delete_tree(input,&t);
//Please refer to the definition below.

*/

#include<stdio.h>
#include<stdlib.h>
typedef int user_def;
typedef struct tree_node{

	user_def data;
	char color;
	struct tree_node* parent;
	struct tree_node* left_child;
	struct tree_node* right_child;


}Tree_node;

Tree_node* allocate_tree(Tree_node** t){

	(*t)=(Tree_node*)malloc(sizeof(Tree_node));
	(*t)->data=0;
	(*t)->color=2;
	(*t)->parent=0;
	(*t)->left_child=0;
	(*t)->right_child=0;
	return (*t);
}
Tree_node* add_tree(user_def input,Tree_node **t){

	
	Tree_node*return_value=0;
	if((*t)==0){
		  allocate_tree(t);
		  (*t)->data=input;
		  return *t;
	}
	else if(((*t)->data)==input) return 0;
	else if(((*t)->data)>input){
		
		return_value=add_tree(input,&((*t)->left_child));
		((*t)->left_child)->parent=(*t);
		return return_value;
	}
	else if(((*t)->data)<input){
		
		return_value=add_tree(input,&((*t)->right_child));
		((*t)->right_child)->parent=(*t);
		return return_value;
	}
}
Tree_node* rotate_tree(Tree_node* t,Tree_node**root){
	Tree_node*parent=((t)->parent);
	if((t)==0||parent==0) return 0;
	if((t)== (parent->right_child) ){
		if( (parent->parent) !=0){

			if(parent==(((parent->parent)->left_child))){
				((parent->parent)->left_child)=(t);
				(t)->parent=(parent->parent);

			}
			else{
				((parent->parent)->right_child)=(t);
				(t)->parent=(parent->parent);


			}

		}
		else{
			(t)->parent=0;
			(*root)=(t);

		}
		(parent->parent)=(t);
		(parent->right_child)= ( (t)->left_child );
		if(parent->right_child!=0) (parent->right_child)->parent=parent;
		(t)->left_child=parent;
		return (t);
	}
	else if((t)== (parent->left_child) ){
		if( (parent->parent) !=0){

			if(parent==(((parent->parent)->left_child))){
				((parent->parent)->left_child)=(t);
				(t)->parent=(parent->parent);

			}
			else{
				((parent->parent)->right_child)=(t);
				(t)->parent=(parent->parent);
			}

		}
		else{
			(t)->parent=0;
			(*root)=(t);

		}
		(parent->parent)=(t);
		(parent->left_child)= ( (t)->right_child );
		if(parent->left_child!=0) (parent->left_child)->parent=parent;
		(t)->right_child=parent;
		return (t);
	}


}
void adjust_after_addition(Tree_node*t,Tree_node**root){
	if(t==0) return;
	if(t->parent==0){
		t->color=1;
		return;
	}
	if((t->parent)->color==1) return;
	
	if((t->parent)==((t->parent)->parent)->right_child){
		if(t==(t->parent)->left_child){
			rotate_tree(t,root);
			t=t->right_child;
		}

		if(((t->parent)->parent)->left_child==0||
			  (((t->parent)->parent)->left_child)->color==1){
			rotate_tree(t->parent,root);
			(t->parent)->color=1;
			((t->parent)->left_child)->color=2;
			return;
		}
		else{
			((t->parent)->parent)->color=2;
			((t->parent)->color)=1;
			(((t->parent)->parent)->left_child)->color=1;
			adjust_after_addition((t->parent)->parent,root);
			return;
		}



	}
	if((t->parent)==((t->parent)->parent)->left_child){
		if(t==(t->parent)->right_child){
			rotate_tree(t,root);
			t=t->left_child;
		}

		if(((t->parent)->parent)->right_child==0||
			  (((t->parent)->parent)->right_child)->color==1){
			rotate_tree(t->parent,root);
			(t->parent)->color=1;
			((t->parent)->right_child)->color=2;
			return;
		}
		else{
			((t->parent)->parent)->color=2;
			((t->parent)->color)=1;
			(((t->parent)->parent)->right_child)->color=1;
			adjust_after_addition((t->parent)->parent,root);
			return;
		}
	}
}
void add_red_black_tree(user_def input,Tree_node**t){

	adjust_after_addition(add_tree(input,t),t);

}

void prefix_print_tree(Tree_node** t){

	if((*t)==0) return;
	else{
		  printf("%d %d\n",(*t)->data,(*t)->color);
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
Tree_node* delete_tree(user_def input,Tree_node**t){

	Tree_node*address=is_in_tree(input,t);
	if(!address) return 0;
	Tree_node*parent=address->parent;
	int color=address->color;
	if(address->left_child==0&&address->right_child==0){
		if(parent==0){//There is only a node in the tree.
			free(address);
			*t=0;
			return 0;
		}

		if(address==parent->left_child){
			parent->left_child=0;
			free(address);
			if(color==1) return parent->right_child;
			else return 0;
		}
		else{
			parent->right_child=0;
			free(address);
			if(color==1) return parent->left_child;
			else return 0;
		}
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
			return 0;

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
			return 0;
		}

	}
	else{
		Tree_node*max=get_max(&(address->left_child));
		address->data=max->data;
		if(max->parent==address){
			if(max->left_child==0){
				address->left_child=0;
				free(max);
				if(color==1) return address->right_child;
				else return 0;
			}
			else{
				address->left_child=max->left_child;
				(max->left_child)->parent=address;
				free(max);
				(address->left_child)->color=1;
				return 0;
			}
		}
		else{
			if(max->left_child==0){
				(max->parent)->right_child=0;
				color=max->color;
				Tree_node*temp=(max->parent)->left_child;
				free(max);
				if(color==1) return temp;
				else return 0;
			}
			else{
				max->data=(max->left_child)->data;
				free(max->left_child);
				max->left_child=0;
				return 0;
			}
		}
	}
}
void adjust_after_deletion(Tree_node*address,Tree_node**root){

	if(address==0) return;
	int my_color=address->color;
	int parent_color=(address->parent)->color;
	int left_child_color,right_child_color;

	if(address->left_child!=0)
	 left_child_color=(address->left_child)->color;
	else left_child_color=0;
	if(address->right_child!=0)
	 right_child_color=(address->right_child)->color;
	else right_child_color=0;

	if(my_color==1&&parent_color==1){
		
		if(left_child_color!=2&&right_child_color!=2){
			address->color=2;
			if(((address->parent)->parent==0)) return;
			if(address->parent==(((address->parent)->parent)->left_child))
				  adjust_after_deletion(((address->parent)->parent)->right_child,root);
			else adjust_after_deletion(((address->parent)->parent)->left_child,root);		
			return;

		}
		else{
			if(address==(address->parent)->left_child){
				if(left_child_color!=2){
					rotate_tree(address->right_child,root);
					address->color=2;
					(address->parent)->color=1;
					address=address->parent;
				}
				rotate_tree(address,root);
				(address->left_child)->color=1;
				return;
			}
			if(address==(address->parent)->right_child){
				if(right_child_color!=2){
					rotate_tree(address->left_child,root);
					address->color=2;
					(address->parent)->color=1;
					address=address->parent;
				}
				rotate_tree(address,root);
				(address->right_child)->color=1;
				return;
			}
		}
	}
	else if(my_color==1&&parent_color==2){
		if(address==(address->parent)->right_child){
			rotate_tree(address,root);
			if(left_child_color==2){
				address=(address->left_child)->right_child;
				adjust_after_addition(address,root);
			}
			return;
		}
		if(address==(address->parent)->left_child){
			rotate_tree(address,root);
			if(right_child_color==2){
				address=(address->right_child)->left_child;
				adjust_after_addition(address,root);
			}
			return;
		}
	}
	else if(my_color==2&&parent_color==1){
		if(address==(address->parent)->right_child){
			rotate_tree(address,root);
			address->color=1;
			(address->left_child)->color=2;
			address=(address->left_child)->right_child;
			adjust_after_deletion(address,root);
			return;
		}
		if(address==(address->parent)->left_child){
			rotate_tree(address,root);
			address->color=1;
			(address->right_child)->color=2;
			address=(address->right_child)->left_child;
			adjust_after_deletion(address,root);
			return;
		}
	}
}
void delete_red_black_tree(user_def input,Tree_node**root){

	adjust_after_deletion(delete_tree(input,root),root);
	return;
}
/*
int main(){
	  
Tree_node* t=0;
add_red_black_tree(60,&t);
add_red_black_tree(70,&t);
add_red_black_tree(50,&t);
add_red_black_tree(0,&t);
add_red_black_tree(55,&t);
add_red_black_tree(-5,&t);
add_red_black_tree(5,&t);
add_red_black_tree(-10,&t);
add_red_black_tree(-3,&t);
add_red_black_tree(-20,&t);
//add_tree(100,&t);
//rotate_tree(is_in_tree(50,&t),&t);
//rotate_tree(delete_tree(70,&t),&t);

delete_red_black_tree(5,&t);
//delete_red_black_tree(50,&t);
prefix_print_tree(&t);
printf("\n");
infix_print_tree(&t);
return 0;	  
}
*/
