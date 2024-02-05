// postfix expression evalution

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAX 100

char postfix[MAX], symbol;
int top = -1, op1, op2 , stack[MAX];

void push(int data){
	stack[++top] = data;
}

int pop(){
	return stack[top--];
}

int main(){
	printf("Enter a valid postfix expression: \n");
	scanf("%s",postfix);
	
	int i;
	for(i = 0; postfix[i] != '\0'; i++){
		symbol = postfix[i];
		if(isdigit(symbol))
			push(symbol - '0');
		else{
			op2 = pop();
			op1 = pop();
			
			switch(symbol){
				case '+': push(op1 + op2);
				break;
				
				case '-': push(op1 - op2);
				break;
				
				case '*': push(op1 * op2);
				break;
				
				case '%': push(op1 % op2);
				break;
				
				case '^': push(pow(op1, op2));
				break;
				
				case '/': if(op2 == 0){
						     printf("ZeroDivisionError.\n");
						     exit(1);
						     }else{
						     	push(op1 / op2);
						     	break;
							 }
			}
			
		}
	}
	int res = pop();
	printf("Postfix Evaluated value %d.",res);
	
	return 0;
}
