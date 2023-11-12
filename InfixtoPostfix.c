#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char operatorStack[100];
int top = -1;
void OperatorStack_push(char ch)
{
    operatorStack[++top] = ch;
}

char OperatorStack_pop()
{
    return operatorStack[top--];
}

char OperatorStack_peek()
{
    return operatorStack[top];
}

bool OperatorStack_isEmpty()
{
    return top == -1;
}

int getPrecedence(char c)
{
    switch (c)
    {
    case '$':
        return 4;
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

bool hasHigherPrecedence(char c1, char c2)
{
    return getPrecedence(c1) >= getPrecedence(c2);
}

bool isOperand(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

bool isOpeningBracket(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool isClosingBracket(char c)
{
    return c == ')' || c == '}' || c == ']';
}

void infix2postfix(char exp[])
{
    int n = strlen(exp);
    char postfix[100]; 
    int k = 0;         
    for (int i = 0; i < n; i++)
    {
        if (isOperand(exp[i])) 
        {
            postfix[k++] = exp[i]; 
        }
        else if (!isOpeningBracket(exp[i]) && !isClosingBracket(exp[i]))
        {
            while (!OperatorStack_isEmpty() && !isOpeningBracket(OperatorStack_peek()) && hasHigherPrecedence(OperatorStack_peek(), exp[i])) 
            {
                postfix[k++] = OperatorStack_pop(); 
            }
            OperatorStack_push(exp[i]); 
        }
        else if (isOpeningBracket(exp[i])) 
        {
            OperatorStack_push(exp[i]); 
        }
        else if (isClosingBracket(exp[i]))
        {
            while (!OperatorStack_isEmpty() && !isOpeningBracket(OperatorStack_peek())) 
            {
                postfix[k++] = OperatorStack_pop(); 
            }
            OperatorStack_pop(); 
        }
    }
    while (!OperatorStack_isEmpty()) 
    {
        postfix[k++] = OperatorStack_pop();
    }
    printf("\nPostfix expression\n"); 
    for (int i = 0; i < k; i++)
    {
        printf("%c", postfix[i]);
    }
}

int main()
{
    char exp[100];
    printf("\nEnter infix expression without any spaces");
    scanf("%s", &exp);
    infix2postfix(exp);
    return 0;
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

