#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 #define SIZE 10
//implementation of queue in arrays

void insert_element_queue(int* front,int* rear,int array[],int data){
    if(*rear ==-1&&*front ==-1){
        *rear=*rear+1;
        *front=*front+1;
        array[*front]=data;
    }
    else{
        *rear=*rear+1;
        array[*rear]=data;
    }
}

void delete_element_queue(int *front,int *rear,int array[],int data){
    if(*front > *rear){
        printf("the queue is empty\n");
    }
    else{
        if(array[*front]==data){
            int temp=array[*front];
            printf("\nElement %d is deleted and rear position :%d\n",temp,*rear);
            *front=*front+1;
        }
        else{
             int ptr=*front;
             while(array[ptr]!=data){
                ptr++;
                if(ptr>*rear){
                    printf("\nElement %d is not in the Queue\n",data);
                    return;            
                }
            }
                int temp=array[ptr];
                for(int i=ptr;i<*rear;i++){
                    array[i]=array[i+1];
                }
                *rear=*rear-1;
                printf("\nElement %d is deleted and rear position :%d\n",temp,*rear);
          
        }
    }

}
void print_array(int* front,int* rear,int array[]){
    printf("\nElemenets in the queue :");
    for(int i=*front;i<=*rear;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}


int main(){

    int front =-1;
    int rear=-1;
    int array[SIZE];
    insert_element_queue(&front,&rear,array,10);
    insert_element_queue(&front,&rear,array,20);
    insert_element_queue(&front,&rear,array,30);
    insert_element_queue(&front,&rear,array,40);
    insert_element_queue(&front,&rear,array,50);
    insert_element_queue(&front,&rear,array,60);
    insert_element_queue(&front,&rear,array,70);
    insert_element_queue(&front,&rear,array,80);
 
    print_array(&front,&rear,array);
    delete_element_queue(&front,&rear,array,30);
    print_array(&front,&rear,array);
    delete_element_queue(&front,&rear,array,70);
    print_array(&front,&rear,array);
    delete_element_queue(&front,&rear,array,100);//100 is not in the queue
}