/*
This is a implementation of binary_serch_tree in c code.
By Wang Zinmin.

usage:


//initialize_tree(input,&root);
//See definition below.
//Don't need this one,if you just want to use binary search tree.

//You can change the typedef keyword.
//If it is int then input input as number,for example 5.
//If it is char then input input a as 'a'.
//Remember to change parameters in all print_tree functions as you like below.

Tree_node*root=0;

insert_tree(input,&root);
//Add a node into the tree.

delete_tree(input,&root);
//Delete the node from the tree.
//Don't need to worry about there is no more node in the tree.
//It is well taken care of.

prefix_print_tree(root);
infix_print_tree(root);
postfix_print_tree(root);
//Print the tree.If there is no node,it will print nothing.

get_max(root);
//If no node in the tree,return 0.
//Otherwise,return maximum.

get_min(root);
//If no node in the tree,return 0.
//Otherwise,return minimum.


is_in_tree(input,root);
//Return address(non zero) of the node, if the input is in the tree.
//Return 0, if the input is not in the tree.


By Wang Zihmin

*/
#include<stdio.h>
#include<stdlib.h>
typedef int user_def;
typedef struct tree_node{
	  user_def data;
	  struct tree_node *left_child;
	  struct tree_node *right_child;
}Tree_node;
void initialize_tree(user_def input,Tree_node*n){
	n->data=input;
	n->left_child=0;
	n->right_child=0;

}
Tree_node* is_in_tree(user_def input,Tree_node* t){

	while(t!=0){
		if(input>(t->data)) t=t->right_child;
		else if(input<(t->data)) t=t->left_child;
		else return t;


	}
	return t;
}
void insert_tree(user_def input,Tree_node**n){
	if(*n==0){
		*n=(Tree_node*)malloc(sizeof(Tree_node));
		initialize_tree(input,*n);
	}
	if(input==((*n)->data)) return;
	if(input>((*n)->data)){
		if(((*n)->right_child)==0){
			(*n)->right_child=(Tree_node*)malloc(sizeof(Tree_node));
			initialize_tree(input,(*n)->right_child);
			return;

		}
		else insert_tree(input,&((*n)->right_child));
		
		return;
	}
	if(input<((*n)->data)){
		if(((*n)->left_child)==0){
			(*n)->left_child=(Tree_node*)malloc(sizeof(Tree_node));
			initialize_tree(input,(*n)->left_child);
			return;

		}
		else insert_tree(input,&((*n)->left_child));
		
		return;
	}


}
void prefix_print_tree(Tree_node*n){
	if(n==0) return;
	printf("%d\n",n->data);
	if(n->left_child!=0){
		prefix_print_tree(n->left_child);
	}
	if(n->right_child!=0){
		prefix_print_tree(n->right_child);	  
		  
	}


	return;
}
void infix_print_tree(Tree_node*n){
	if(n==0) return;
	if(n->left_child!=0){
		infix_print_tree(n->left_child);
	}
	printf("%d\n",n->data);
	if(n->right_child!=0){
		infix_print_tree(n->right_child);	  
		  
	}


	return;
}
void postfix_print_tree(Tree_node*n){
	if(n==0) return;
	if(n->left_child!=0){
		postfix_print_tree(n->left_child);
	}
	if(n->right_child!=0){
		postfix_print_tree(n->right_child);	  
		  
	}
	printf("%d\n",n->data);


	return;
}
void delete_tree(user_def input,Tree_node **t){

	Tree_node* ptr=is_in_tree(input,*t);
	if(ptr==0) return;
	else if(ptr==(*t)&&ptr->left_child==0&&ptr->right_child==0){
		free(*t);
		*t=0;
		return;
	}
	else if(ptr->left_child==0&&ptr->right_child==0){
		  
		Tree_node*temp=*t;
		if(input>((*t)->data)) ptr=(*t)->right_child;
		else ptr=(*t)->left_child;

		while((ptr->data)!=input){
		
			if(input>(ptr->data)){
				
				temp=ptr;
				ptr=(ptr)->right_child;
				
			}
			else{
				temp=ptr;
				ptr=(ptr)->left_child;
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
	else if(ptr->left_child!=0&&ptr->right_child!=0){
		Tree_node*temp;
		Tree_node*previous=ptr;
		temp=ptr->left_child;
		int flag=0;
		while(temp->right_child!=0){
			previous=temp;
			temp=temp->right_child;
			flag=1;
		}
		ptr->data=temp->data;
		
		if(flag==1){
			if(temp->left_child!=0){
				previous->right_child=temp->left_child;
				free(temp);

			}
			else{
				previous->right_child=0;
				free(temp);

			}
		}
		else{
			previous->left_child=temp->left_child;
			free(temp);

		}



		return;
	}



}
/*int delete_tree_node(user_def input,Tree_node*n,int version){
	
	Tree_node*temp=0;
	if((n->left_child)==0&&(n->right_child)==0&&version==0){
		printf("only one item in the tree, please use initialize_tree()\n");
		return 0;
	}
	else if(input==(n->data)){
		
		if((n->left_child)==0&&(n->right_child)==0&&version==1){
			
				  free(n);
				  return 1;
		}
			
		else if((n->left_child)==0){
			temp=n->right_child;
			n->data=temp->data;
			n->left_child=temp->left_child;
			n->right_child=temp->right_child;
			free(temp);
			return 0;
		}
		else if((n->right_child)==0){
			temp=n->left_child;
			n->data=temp->data;
			n->left_child=temp->left_child;
			n->right_child=temp->right_child;
			free(temp);
			return 0;
		}
		else{
			Tree_node*previous=n;
			temp=n->left_child;
			while(temp->right_child!=0){
				previous=temp;
				temp=temp->right_child;	  
				
			}
			n->data=temp->data;
			if(delete_tree_node(temp->data,temp,1)){
				if(previous==n) previous->left_child=0;
				else previous->right_child=0;
			}
			return 0;
		}
	}
	else if(input>(n->data)){
		if(n->right_child==0) return 0;
		if(delete_tree_node(input,n->right_child,1)){
			n->right_child=0;	  
			  
		}

	}
	else{
		if(n->left_child==0) return 0;
		if(delete_tree_node(input,n->left_child,1)){
			n->left_child=0;	  
			  
		}


	}
	return 0;
}*/
user_def get_max(Tree_node*n){
	if(n==0) return 0;
	user_def max=n->data;
	if(n->right_child!=0){
		max=get_max(n->right_child);
	
	}

	return max;
}
user_def get_min(Tree_node*n){
	if(n==0) return 0;
	user_def min=n->data;
	if(n->left_child!=0){
		min=get_min(n->left_child);
	
	}

	return min;
}
/*
int main(){

	Tree_node*head=0;
	insert_tree(5,&head);
	insert_tree(16,&head);
	insert_tree(5,&head);
	insert_tree(8,&head);
	insert_tree(3,&head);
	insert_tree(4,&head);
	insert_tree(1,&head);
	delete_tree(5,&head);
	prefix_print_tree(head);



return 0;



}
*/

