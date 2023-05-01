#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
} node;

node *front = NULL;
node *rear = NULL;
int size = 0;

void enqueue(int number);
void dequeue();
void display();
int getSize();
void flush_input_buffer();
int menu();
node *getNode(int num);

int main()
{
    int ch;
    while (1)
    {
        ch = menu();
        int num;
        switch (ch)
        {
        case 1:
            printf("Enter number to enqueue: \n");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("The queue size is %d.\n", getSize());
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
}

int menu()
{
    int choice;
    do
    {
        printf("\n1) Enqueue a number\n");
        printf("2) Dequeue a number\n");
        printf("3) Display the queue\n");
        printf("4) Get size\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 5);
    return choice;
}

node *getNode(int num)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = num;
    temp->next = NULL;
    return temp;
}

void enqueue(int number)
{
    node *newnode = getNode(number);
    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    size++;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    node *temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    printf("%d dequeued from queue.\n", temp->data);
    free(temp);
    size--;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getSize()
{
    return size;
}

void flush_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}