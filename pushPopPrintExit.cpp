#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int arr[MAX];
int top = -1;

//prototype
int isFull();
int isEmpty();
void push(int);
int pop();
int peek();

int peek(){
	if(isEmpty()){
		printf("Stack is underflow.\n");
		exit(1);
	}
	return arr[top];
}
void push(int data){
	if(isFull()){
		printf("Stack Overflow.\n");
		return;
	}
	arr[++top] = data;
}

int pop(){
	if(isEmpty()){
		printf("Stack underflow.\n");
		exit(1);
	//	return -1;
	}
	return arr[top--];
}

int isFull(){
	if(top == MAX - 1)
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}

void print(){
	if(isEmpty()){
		printf("Stack is underflow.\n");
		return;
	}
	int i;
	for(i = top; i >= 0; i--){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

int main(){
	int data;
	int choice;
	while(1){
		printf("Enter your choice:\n");
		printf("1.Push\n2.Pop\n3. Print the top element\n4.Print all element\n5. Exit\n");
	
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter data to be pushed:\n");
					scanf("%d",&data);
					push(data);
					break;
				
			case 2: //nt value = pop();
					printf("Popped item %d.\n",pop());
					break;
					
			case 3: //int topEle = peek();
					printf("Top Element is %d.\n",peek());
					break;
					
			case 4: print();
					break;
				
			case 5: exit(1);
			
			default: printf("Invalid choice.\n");
					break;
		}
	}
}
