/*
This is a implementation of b tree in c code.

usage:

Node*root=0;
//Creat a pointer.

add_b_tree(input,&root);
//Add an input into the b tree.
//input can be defined as anytype below.
//input can be the same.

delete_b_tree_root(input,&root);
//Delete input from the b tree.
//If not exist,do nothing.

max_in_b_tree(root);
//Return maximum in b tree.
//Return 0 if there is no item in the b tree.
min_in_b_tree(root);
//Return minimum in b tree.
//Return 0 if there is no item in the b tree.

is_in_b_tree(input,root);
//return 1 if input is in b tree.
//return 0 if input is not in b tree.

is_empty(root);
//Return 1 if b tree is empty.
//Return 0 if b tree is not empty.

print_b_tree(root);
//Print the b tree in a ascending order.

void combine_node(Node*current,int index);
int rotate_b_tree(Node*pivot,int index,char version[6]);
void split_node(Node* current,int index);
void initialize_b_tree(new_address);
void add_b_tree_root(input,&root);
void add_b_tree_else(input,root);
void delete_b_tree_root(input,&root);
void delete_b_tree_else(input,root);
//Refer to the code below.

By Wang Zihmin.

example:
int main(){

Node* root=0;
int input=23;
for(int iii=0;iii<10;iii++){
	input+=iii*7-iii/3;
	input=input<<1;
	input=(input%123);
	add_b_tree(input,&root);
	input+=iii-iii/7;
	input=~input;
	input=(input%123);
	add_b_tree(input,&root);
	input-=iii/7;
	input=~input;
	input=(input%123);
	delete_b_tree(input,&root);
}
print_b_tree(root);
printf("%d\n",is_in_b_tree(93,root));
printf("%d\n",is_in_b_tree(94,root));
printf("%d\n",is_in_b_tree(95,root));

printf("result\n");
printf("max %d min %d\n",max_in_b_tree(root),min_in_b_tree(root));
if(is_empty(root)) printf("it is empty\n");
else printf("it is not empty\n");

return 0;
}

*/


#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define minimum 2
typedef int userdef;
typedef struct node{
	int number;
	int is_leaf;
	userdef key[2*minimum-1];
	struct node *child[2*minimum];	

}Node;
int is_in_b_tree(userdef input,Node*root);
int is_empty(Node*current);
int max_in_b_tree(Node*current);
int min_in_b_tree(Node*current);
void combine_node(Node*current,int index);
int rotate_b_tree(Node*pivot,int index,char version[6]);
void delete_b_tree_root(userdef input,Node**current);
void split_node(Node* current,int index);
void initialize_b_tree(Node*tree);
void add_b_tree_root(userdef input,Node**current);
void add_b_tree_else(userdef input,Node*current);
void add_b_tree(userdef input,Node**root);
void print_b_tree(Node*root);

void initialize_b_tree(Node*tree){
	tree->number=0;
	tree->is_leaf=0;
	for(int iii=0;iii<2*minimum;iii++){
		tree->child[iii]=0;

	}


}
int is_in_b_tree(userdef input,Node*root){
	if(root==0) return 0;
	else{
		int flag=0;
		for(int iii=0;iii<root->number;iii++){
			if(input==root->key[iii]){
				flag=1;
				break;			
			}
		}
		if(flag==1) return 1;
		else if(root->is_leaf==1) return 0;
		else{
			int index=root->number;
			for(int iii=0;iii<root->number;iii++){
				if(input<root->key[iii]){
					index=iii;
					break;
				}
			}
			return is_in_b_tree(input,root->child[index]);

		}
	}
}

void add_b_tree_root(userdef input,Node**current){
	if(*current==0){
		*current=(Node*)malloc(sizeof(Node));	 
		initialize_b_tree(*current);
		(*current)->is_leaf=1;
	}
	else if((*current)->number==(2*minimum-1)){
		Node*new_root=(Node*)malloc(sizeof(Node));
		initialize_b_tree(new_root);	
		new_root->child[0]=*current;
		*current=new_root;
		split_node(*current,0);		
	}
	add_b_tree_else(input,*current);
	return;
}

void add_b_tree_else(userdef input,Node*current){
	if(current->is_leaf==1){
		int index=(current->number);
		for(int iii=0;iii<(current->number);iii++){
			if(input<(current->key[iii])){
				index=iii;
				break;	
			}
		}
		for(int iii=(current->number);iii>index;iii--){
			current->key[iii]=current->key[iii-1];	
		}
		current->key[index]=input;
		current->number+=1;
		return;		 
	}
	else if(current->is_leaf==0){
		int index=current->number;
		for(int iii=0;iii<(current->number);iii++){
			if(input<(current->key[iii])){
				index=iii;
				break;
			}
		}
		if((current->child[index])->number==2*minimum-1){
			split_node(current,index);
			if(input<current->key[index])
				 add_b_tree_else(input,current->child[index]);
			else add_b_tree_else(input,current->child[index+1]);
			return;
		}
		else add_b_tree_else(input,current->child[index]);
		return;
	}
}

void split_node(Node* current,int index){
	int number=current->number;
	for(int iii=number;iii>index;iii--){
		current->key[iii]=current->key[iii-1];
		current->child[iii+1]=current->child[iii];	 
	}
	current->key[index]=(current->child[index])->key[minimum-1];
	current->number+=1;
	current->child[index+1]=(Node*)malloc(sizeof(Node));
	initialize_b_tree(current->child[index+1]);
	(current->child[index+1])->is_leaf=(current->child[index])->is_leaf;
	(current->child[index])->number=minimum-1;
	(current->child[index+1])->number=minimum-1;
	for(int iii=0;iii<minimum-1;iii++){
		(current->child[index+1])->key[iii]=(current->child[index])->key[iii+minimum];
	}
	if((current->child[index])->is_leaf==0){
		for(int iii=0;iii<minimum;iii++){
			(current->child[index+1])->child[iii]=(current->child[index])->child[minimum+iii];
		}
	}
	return;
}

void add_b_tree(userdef input,Node**root){
	add_b_tree_root(input,root);
	return;
}

void print_b_tree(Node*root){
	if(root==0) return;
	
	if(root->is_leaf==0){
		for(int iii=0;iii<(root->number);iii++){
			print_b_tree(root->child[iii]);
			printf("%d\n",root->key[iii]);
		}
		print_b_tree(root->child[root->number]);
		return;
	}
	else if(root->is_leaf==1){
		for(int iii=0;iii<(root->number);iii++)
		printf("%d\n",root->key[iii]);
		return;
	}
}
int is_empty(Node*current){
	if(current==0) return 1;
	else return 0;
}

userdef max_in_b_tree(Node*current){
	if(current==0) return 0;
	if(current->is_leaf==1) return current->key[current->number-1];
	else return max_in_b_tree(current->child[current->number]);
}
userdef min_in_b_tree(Node*current){
	if(current==0) return 0;
	if(current->is_leaf==1) return current->key[0];
	else return min_in_b_tree(current->child[0]);
}

void delete_b_tree_else(userdef input,Node*current){
	//preparing information
	//flag for whether or not input is in the node
	//index indicates the position of the input if exist
	int number=current->number;
	int index=number;
	for(int iii=0;iii<number;iii++){
		if(input<=(current->key[iii])){
			index=iii;
			break;
		}
	}
	int flag=0;
	if((!(index==number))&&(input==(current->key[index]))) flag=1;
	//
#ifdef debug
printf("current->is_leaf %d\nindex %d\nflag %d\n",current->is_leaf,index,flag);
#endif	
	
	
	if(current->is_leaf==1){
		if(flag==0) return;
		else{
			for(int iii=index;iii<(number-1);iii++){
				current->key[iii]=current->key[iii+1];
			}	 
			current->number-=1;
			return;
		}		 
	}
	else if(current->is_leaf==0){
		if(flag==0){
			if(((current->child[index])->number)>(minimum-1)){
				delete_b_tree_else(input,current->child[index]);
				return;
			}
			else{
				if(index==number){//input in the last child
					if(rotate_b_tree(current,index,"right")){
						delete_b_tree_else(input,current->child[index]);
						return;;
					}
					else{
						index-=1;
						combine_node(current,index);
						delete_b_tree_else(input,current->child[index]);
						return;
					}
				}
				else if(index==0){
					if(rotate_b_tree(current,index,"left")){

						delete_b_tree_else(input,current->child[index]);
						return;
					}
					
					else{
						combine_node(current,index);
						delete_b_tree_else(input,current->child[index]);
						return;
					}	
				}
				else{		
					if(rotate_b_tree(current,index,"right")){
						delete_b_tree_else(input,current->child[index]);
						return;;
					}
					else if(rotate_b_tree(current,index,"left")){

						delete_b_tree_else(input,current->child[index]);
						return;
					}
					else{
						index-=1;
						combine_node(current,index);
						delete_b_tree_else(input,current->child[index]);
						return;
					}
				}
			}		
		}
		else if(flag==1){
			if((current->child[index])->number>(minimum-1)){
#ifdef debug
printf("in1\n");
#endif		
				int max=max_in_b_tree(current->child[index]);
				current->key[index]=max;
				delete_b_tree_else(max,current->child[index]);
				return;							 	 
			}
			else if((current->child[index+1])->number>(minimum-1)){
#ifdef debug
printf("in2\n");
#endif		
				int min=min_in_b_tree(current->child[index+1]);
#ifdef debug
printf("min %d\n",min);
#endif
				current->key[index]=min;
				delete_b_tree_else(min,current->child[index+1]);
				return;
			}
			else{
#ifdef debug
printf("in3\n");
#endif		
				combine_node(current,index);
				delete_b_tree_else(input,current->child[index]);
				return;
			}
		}
	}
}

void combine_node(Node*current,int index){
	(current->child[index])->key[minimum-1]=current->key[index];
	for(int iii=0;iii<minimum-1;iii++){
		(current->child[index])->key[minimum+iii]=(current->child[index+1])->key[iii];
	}
	if((current->child[index])->is_leaf==0){
		for(int iii=0;iii<minimum;iii++){
			(current->child[index])->child[minimum+iii]=(current->child[index+1])->child[iii];
		}
	}
	(current->child[index])->number=2*minimum-1;
	free(current->child[index+1]);
	for(int iii=index;iii<((current->number)-1);iii++){
		current->key[iii]=current->key[iii+1];
		current->child[iii+1]=current->child[iii+2];
	}
	current->child[current->number]=0;
	current->number-=1;
	return;
}

int rotate_b_tree(Node*pivot,int index,char version[6]){

	if(strcmp(version,"right")==0){
		int sibling_number=((pivot->child[index-1])->number);
		if(sibling_number>(minimum-1)){
			for(int iii=(minimum-1);iii>0;iii--){
				(pivot->child[index])->key[iii]=(pivot->child[index])->key[iii-1];
			}
			(pivot->child[index])->key[0]=pivot->key[index-1];
			pivot->key[index-1]=(pivot->child[index-1])->key[sibling_number-1];
			(pivot->child[index])->number+=1;
			(pivot->child[index-1])->number-=1;
			if((pivot->child[index])->is_leaf==0){
				for(int iii=minimum;iii>0;iii--){
					(pivot->child[index])->child[iii]=(pivot->child[index])->child[iii-1];
				}
				(pivot->child[index])->child[0]=(pivot->child[index-1])->child[sibling_number];
			}
			return 1;
		}
		else return 0;
	}
	else if(strcmp(version,"left")==0){
		int sibling_number=(pivot->child[index+1])->number;
		if(sibling_number>minimum-1){
			(pivot->child[index])->key[minimum-1]=pivot->key[index];
			pivot->key[index]=(pivot->child[index+1])->key[0];
			for(int iii=0;iii<sibling_number-1;iii++){
				(pivot->child[index+1])->key[iii]=(pivot->child[index+1])->key[iii+1];	 	 
			}
			(pivot->child[index])->number+=1;
			(pivot->child[index+1])->number-=1;
			if((pivot->child[index])->is_leaf==0){
				(pivot->child[index])->child[minimum]=(pivot->child[index+1])->child[0];
				for(int iii=0;iii<sibling_number;iii++){
					(pivot->child[index+1])->child[iii]=(pivot->child[index+1])->child[iii+1];
				}		
			}
			return 1;	
		}
		else return 0;
	}
	else return 0;
}

void delete_b_tree_root(userdef input,Node**current){
	if(*current==0) return;
	else if((*current)->number==1&&(*current)->is_leaf==0){
#ifdef debug2
printf("in\n");
#endif
		if(((*current)->child[0])->number==(minimum-1)&&((*current)->child[1])->number==(minimum-1)){

			combine_node(*current,0);

#ifdef debug2
printf("root number %d child number %d\n",(*current)->number,((*current)->child[0])->number);
#endif

			Node*temp=*current;

			*current=(temp->child[0]);
			free(temp);
			delete_b_tree_else(input,*current);
			return;
		}
		else{
#ifdef debug2
printf("strange\n");
#endif
			delete_b_tree_else(input,*current);
			return;
		}
	}
	else if((*current)->number==1&&(*current)->is_leaf==1){
		free(*current);
		*current=0;
		return;
	}
	else{
#ifdef debug
printf("root\n");
#endif

		delete_b_tree_else(input,*current);
		return;
	}
}

void delete_b_tree(userdef input,Node**root){
	delete_b_tree_root(input,root);
	return;
}
