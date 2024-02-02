#include <stdio.h>
#define MAX 20
int q[MAX]; 
int front = -1, rear = -1;
void enqueue(int el)
{
    if (rear == MAX - 1)
        printf("\nQueue full");
    else
    {
        if (front == -1 && rear == -1)       
            front = rear = 0; 
        else
        {
            rear++; 
        }
        q[rear] = el;
    }
}
void dequeue()
{
    int deleted;
    if (rear == MAX - 1)
    {
        printf("\nQueue empty");
    }
    else
    {
         deleted = q[front];
        
        if (front == rear) 
            front = rear = -1; 
        else
            front++; 
        printf("\nDeleted from queue: %d", deleted);
    }
}
void printQ()
{
    if ( front == -1 && rear == -1)
        printf("\nQueue empty");
    else
    {
        printf("\nElements of Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", q[i]);
    }
}
int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display queue");
        printf("\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printQ();
            break;
        }
    } while (ch < 4);
}
