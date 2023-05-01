#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
} node;

node *head = NULL;
int size = 0;

void insert(int number);
void delete(int num);
void search(int num);
void update(int position, int number);
void display();
int getSize();
int menu();
node *getNode(int num);

int main()
{
    int ch;
    while (1)
    {
        ch = menu();
        int num, pos;
        switch (ch)
        {
        case 1:
            printf("Enter number to insert: ");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            printf("Enter a number to search: ");
            scanf("%d", &num);
            search(num);
            break;
        case 3:
            printf("Enter the position to enter the number: ");
            scanf("%d", &pos);
            printf("Enter the number to update in position %d: ", pos);
            scanf("%d", &num);
            update(pos, num);
            break;
        case 4:
            printf("Enter the number to delete: ");
            scanf("%d", &num);
            delete (num);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("The array size is %d.\n", getSize());
            break;
        case 7:
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
        printf(" 1)Insert a number.\n");
        printf(" 2)Search a number.\n");
        printf(" 3)Update a number.\n");
        printf(" 4)Delete a number.\n");
        printf(" 5)Display the array.\n");
        printf(" 6)Get size.\n");
        printf(" 7)Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 7);
    return choice;
}

node *getNode(int num)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = num;
    temp->next = NULL;
    return temp;
}

void insert(int number)
{
    node *newnode = getNode(number);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    size++;
}

void delete(int num)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Array is Empty.\n");
        return;
    }
    if (head->data == num)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
        size--;
        return;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == num)
        {
            node *tmp = temp->next;
            temp->next = temp->next->next;
            free(tmp);
            size--;
            return;
        }
        temp = temp->next;
    }
    printf("%d not found.\n", num);
}

void search(int num)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Array is Empty.\n");
        return;
    }
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            printf("%d found in position %d.\n", num, i);
            return;
        }
        i++;
        temp = temp->next;
    }
    printf("%d not found.\n", num);
}

void update(int position, int number)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Array is Empty.\n");
        return;
    }
    node *newnode = getNode(number);
    if (position == 0)
    {
        if (head->next != NULL)
            newnode->next = head->next;
        head = newnode;
        return;
    }
    int i = 0;
    while (temp != NULL)
    {
        if (i == position - 1)
        {
            if (temp->next == NULL)
            {
                temp->next = newnode;
            }
            else
            {
                newnode->next = temp->next->next;
                temp->next = newnode;
            }
            return;
        }
        i++;
        temp = temp->next;
    }
    printf("Error: Invalid position.\n");
}

void display()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Array is Empty.\n");
        return;
    }
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
