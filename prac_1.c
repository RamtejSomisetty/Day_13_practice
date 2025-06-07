#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

node* create_new_node(int data){
    node* new_node = malloc(sizeof(node));
    new_node->data =data;
    new_node->next=NULL;
    return new_node;
}

void insert_element_queue(node** front,node** rear,int data){
     
    node* new_node = create_new_node(data);
    if(*front == NULL && *rear == NULL){
        *front=new_node;
        *rear=new_node;
    }
    else{
        (*rear)->next=new_node;
        *rear= (*rear)->next;
    }
}

void print_elements(node* front){
    node* temp=front;
    while((temp) != NULL){
        printf("%d->",(temp)->data);
        temp=(temp)->next;
    }
    printf("NULL\n");
}
int main(){
    node* front=NULL;
    node* rear =NULL;
    insert_element_queue(&front,&rear,10);
    insert_element_queue(&front,&rear,20);
    insert_element_queue(&front,&rear,30);
    insert_element_queue(&front,&rear,40);
    insert_element_queue(&front,&rear,50);
    insert_element_queue(&front,&rear,60);
    print_elements(front);
}