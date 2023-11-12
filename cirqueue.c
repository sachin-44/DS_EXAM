#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

int cq[SIZE];  
int front = -1, rear = -1;

bool isEmpty()
{
    return front == -1 && rear == -1;
}

bool isFull()
{
    return (rear + 1) % SIZE == front;
}

void enqueue(int el)
{
    if (isFull())
        printf("\nQueue Full");
    else
    {
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        cq[rear] = el;
    }
}

void dequeue()
{
    if (isEmpty())
        printf("\nQueue Empty");
    else
    {
        int deleted = cq[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("Deleted: %d", deleted);
    }
}

void printQ()
{
    if (isEmpty())
        printf("\nQueue empty");
    else
    {
        if (front <= rear)
            for (int i = front; i <= rear; i++)
                printf("%d ", cq[i]);
        else
        {
            for (int i = front; i < SIZE; i++)
                printf("%d ", cq[i]);
            for (int i = 0; i <= rear; i++)
                printf("%d ", cq[i]);
        }
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

    return 0;
}
