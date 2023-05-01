#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
    struct node_struct *prev;
} node;

node *head = NULL;
int size = 0;

void insert(int number);
void delete(int num);
void search(int num);
void update(int position, int number);
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
        int num, pos;
        switch (ch)
        {
        case 1:
            printf("Enter number to insert: \n");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            printf("Enter a number to search: \n");
            scanf("%d", &num);
            search(num);
            break;
        case 3:
            printf("Enter the position to enter the number: \n");
            scanf("%d", &pos);
            printf("Enter the number to update in position %d: \n", pos);
            scanf("%d", &num);
            update(pos, num);
            break;
        case 4:
            printf("Enter the number to delete: \n");
            scanf("%d", &num);
            delete (num);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("The linked list size is %d.\n", getSize());
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
        printf("\n1) Insert a number\n");
        printf("2) Search a number\n");
        printf("3) Update a number\n");
        printf("4) Delete a number\n");
        printf("5) Display the linked list\n");
        printf("6) Get size\n");
        printf("7) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 7);
    return choice;
}

node *getNode(int num)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = num;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insert(int number)
{
    node *newnode = getNode(number);
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        node *tail = head->prev;
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
    }
    size++;
}

void delete(int num)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    if (head->data == num)
    {
        node *tmp = head;
        if (head == head->next) {  // only one element in the list
            head = NULL;
        } else {
            head = head->next;
            head->prev = tmp->prev;
            tmp->prev->next = head;
        }
        free(tmp);
        size--;
        return;
    }
    while (temp->next != head)
    {
        if (temp->next->data == num)
        {
            node *tmp = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            free(tmp);
            size--;
            return;
        }
        temp = temp->next;
    }
    // Check if the last node contains the data to be deleted
    if (temp->data == num)
    {
        node *tmp = temp;
        temp->prev->next = head;
        head->prev = temp->prev;
        free(tmp);
        size--;
        return;
    }
    printf("%d not found.\n", num);
}

void search(int num)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    int i = 0;
    while (temp->next != head)
    {
        if (temp->data == num)
        {
            printf("%d found in position %d.\n", num, i);
            return;
        }
        i++;
        temp = temp->next;
    }
    // Check if the last node contains the data
    if (temp->data == num)
    {
        printf("%d found in position %d.\n", num, i);
        return;
    }
    printf("%d not found.\n", num);
}

void update(int position, int number)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    node *newnode = getNode(number);
    if (position == 0)
    {
        if (head->next != head)
        {
            head->next->prev = newnode;
            newnode->next = head->next;
        }
        else
        {
            newnode->next = head;
        }
        head->prev->next = newnode;
        newnode->prev = head->prev;
        head = newnode;
        return;
    }
    int i = 0;
    node *temp = head;
    while (temp->next != head)
    {
        if (i == position - 1)
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            return;
        }
        i++;
        temp = temp->next;
    }
    // Check if the last node is the desired position
    if (i == position - 1)
    {
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
        return;
    }
    printf("Error: Invalid position.\n");
}

void display()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    printf("The linked list is: ");
    node *temp = head;
    while (temp->next != head)
    {
        printf("%d", temp->data);
        printf(" <-> ");
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf(" <-> ");
    printf("%d", head->data);
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
        ;
}
