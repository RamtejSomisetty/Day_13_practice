#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}node;

node* create_new_node(int data){
    node* new_node = malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void insert_element_circular_linked_list(node** front,node** rear,int data){
    node* new_node=create_new_node(data);
    if(*front==NULL && *rear == NULL){
        *front=new_node;
        *rear=new_node;
        new_node->next=*front;
    }
    else{
        (*rear)->next=new_node;
        *rear=new_node;
        (*rear)->next=*front;
    }
}


int main(){
    node* front=NULL;
    node* rear=NULL;
    insert_element_circular_linked_list(&front,&rear,10);
    insert_element_circular_linked_list(&front,&rear,20);
    insert_element_circular_linked_list(&front,&rear,30);
    insert_element_circular_linked_list(&front,&rear,40);
    insert_element_circular_linked_list(&front,&rear,50);
    insert_element_circular_linked_list(&front,&rear,60);
    
}