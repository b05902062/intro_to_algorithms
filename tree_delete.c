#include<stdio.h>
#include<stdlib.h>
typedef int user_def;
typedef struct tree_node{
	  user_def data;
	  struct tree_node *left_child;
	  struct tree_node *right_child;
}Tree_node;
void delete_tree(user_def input,Tree_node *t){

	Tree_node* ptr=is_in_tree(input,t);
	if(ptr==0) return;
	else if(ptr->left_child==0&&ptr->right_child==0){
		  
		assert(ptr!=t);

		Tree_node*temp=t;
		if(input>(t->data)) ptr=t->right_child;
		else ptr=t->left_child;

		while((ptr->data)!=input){
		
			if(input>(ptr->data)){
				
				temp=ptr;
				ptr=t->right_child;
				
			}
			else{
				temp=ptr;
				ptr=t->left_child;
			}

		}
		if((temp->right_child)==ptr){
			temp->right_child=0;
			free(ptr);

		}
		else{
			temp->left_child=0;
			free(ptr);

		}
		return;
	}
	else if(ptr->left_child==0||ptr->right_child==0){
		Tree_node*temp;
		if(ptr->left_child==0){
			temp=ptr->right_child;
		}
		else temp=ptr->left_child;
		ptr->data=temp->data;
		ptr->right_child=temp->right_child;
		ptr->left_child=temp->left_child;
		free(temp);	  
		return;
	}
	else{
		Tree_node*temp;
		if(((ptr->left_child)->right_child)==0) temp=ptr->left_child;
		else{
			temp=((ptr->left_child)->right_child);	  
			while(temp->right_child!=0){
				temp=temp->right_child;

			}
		}
		ptr->data=temp->data;
		delete_tree(temp);
		return;
	}



}
Tree_node* is_in_tree(user_def input,Tree_node* t){

	while(t!=0){
		if(input>(t->data)) t=t->right_child;
		if(input<(t->data)) t=t->left_child;
		else return t;


	}
	return t;
}
