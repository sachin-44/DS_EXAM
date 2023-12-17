#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}




1. Push left parenthesis onto STACK and add right parenthesis at the end of Q.
 
2. Scan Q from left to right and repeat step 3 to 6 for each element of Q until the STACK is empty.
 
3. If an operand is encountered add it to P.
 
4. If a left parenthesis is encountered push it onto the STACK.
 
5. If an operator is encountered, then
Repeatedly pop from STACK and add to P each operator
which has same precedence as or higher precedence than the operator
encountered.
Push the encountered operator onto the STACK.
6. If a right parenthesis is encountered, then
Repeatedly pop from the STACK and add to P each operator
until a left parenthesis is encountered.
Remove the left parenthesis; do not add it to P.

