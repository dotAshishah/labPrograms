// infix to postfix conversion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char infix[MAX], stack[MAX];
int top = -1;

void push(char symbol){
	if(top == MAX - 1){
		printf("Stack is overflow.\n");
	}else
		stack[++top] = symbol;
}

char pop(){
	if(top == -1){
		printf("Stack is underflow.\n");
		exit(1);
	}
	return stack[top--];
}


int priority(char symbol){
	if(symbol == '(')
		return 0;
	else if(symbol == '+' || symbol == '-')
			return 1;
	else if(symbol == '*' || symbol == '/')
			return 2;
	else if(symbol == '^' || symbol == '$')
			return 3;
	else
		return 0;
}

void inToPost(){
	int i;
	char symbol, x;
	for(i = 0; infix[i] != '\0'; i++){
		symbol = infix[i];
		if(isalnum(symbol))
			printf("%c",symbol);
		else if(symbol == '(')
				push(symbol);
		else if(symbol == ')'){
				while((x = pop()) != '(')
					printf("%c",x);
		}
		else {
			while(priority(stack[top]) >= priority(symbol))
				printf("%c",pop());
			push(symbol);
		}
	}
}

int main(){
	printf("Assumption: Enter infix expression contains single variable or single digit only: \n");
	scanf("%s",infix);
	push('(');
	strcat(infix, ")");
	inToPost();
}
