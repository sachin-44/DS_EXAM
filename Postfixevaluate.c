#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
int stack[100];
int top = -1;
void push(int el)
{
    stack[++top] = el;
}
int pop()
{
    return stack[top--];
}
int display()
{
    return stack[top];
}
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
int performOperation(char operator, int op1, int op2)
{
    switch (operator)
    {
    case '+':
        return op2 + op1;
    case '-':
        return op2 - op1;
    case '*':
        return op2 * op1;
    case '/':
        return op2 / op1;
    case '^':
        return pow(op2, op1);
    default:
        return -1;
    }
}
int postfixEval(char exp[])
{
    int n = strlen(exp);
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == ' ')   
            continue;        
        if (isDigit(exp[i])) 
        {
            int num = 0;
            while (isDigit(exp[i])) 
            {
                num = num * 10 + (int)(exp[i] - '0'); 
                i++;
            }
            i--;
            push(num); 
        }
        else 
        {
            int op1 = pop();
            int op2 = pop();
            int result = performOperation(exp[i], op1, op2);
            push(result);                             
        }
    }
    return display(); 
}
int main()
{
    char exp[100];
    printf("\nEnter postfix expression, each item must be space separated\n");
    gets(exp);
    int EvaluatedValue = postfixEval(exp);
    printf("\nResult Of evaluated postfix:  %d", EvaluatedValue);
    return 0;
}





Create a stack to store operands (or values).
Scan the given expression from left to right and do the following for every scanned element.
If the element is a number, push it into the stack.
If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack.
When the expression is ended, the number in the stack is the final answer
