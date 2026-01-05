#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char Girdi) {
    if (top >= MAX - 1) {
        printf("Stack Dolu\n");
    } else {
        stack[++top] = Girdi;
    }
}
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}
char peek() {
    if (top == -1) {
        return -1;
    }
    return stack[top];
}
int oncelik(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^') 
        return 3;
    return 0;
}
int OperatorMu(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
void infixPostfixeCevir(char* infix, char* postfix) {
    int i, j = 0;
    char _xValue;
    char x;
    for (i = 0; infix[i] != '\0'; i++) {
        _xValue = infix[i];       
        if (isalnum(_xValue)) {//Hocam isalnum ifadesi sayý mý karektermi harfmi ona bakýyor
            postfix[j++] = _xValue;
        }        
        else if (_xValue == '(') {
            push(_xValue);
        }     
        else if (_xValue == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }        
        else if (OperatorMu(_xValue)) {
            // Stack boþ deðilse ve stack'teki operatörün önceliði >= ise pop yap
            while (top != -1 && oncelik(peek()) >= oncelik(_xValue)) {
                postfix[j++] = pop();
            }
            push(_xValue);
        }
    }  
    postfix[j] = '\0'; 
}

int main() {
    
    char infix[MAX] = "A+b*(c^d-e)/(F+g*h)-i";
    char postfix[MAX];

    printf("Infix : %s\n", infix);

    infixPostfixeCevir(infix, postfix);

    printf("Postfix : %s\n", postfix);
    
    printf("2017110206002 Bilal GULDEN");

    return 0;
}
