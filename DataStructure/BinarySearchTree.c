#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *left;
    struct node_struct *right;
} node;

node *root = NULL;
int size = 0;

void insert(int number);
node *getNode(int num);
node *insert_helper(node *root, int number);
void delete(int num);
node *delete_helper(node *root, int num);
node *find_min(node *root);
void search(int num);
int search_helper(node *root, int num);
void display(node *root);
int getSize();
void flush_input_buffer();
int menu();

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
            printf("Enter number to insert: \n");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            printf("Enter the number to delete: \n");
            scanf("%d", &num);
            delete (num);
            break;
        case 3:
            printf("Enter a number to search: \n");
            scanf("%d", &num);
            search(num);
            break;
        case 4:
            display(root);
            break;
        case 5:
            printf("The tree size is %d.\n", getSize(root));
            break;
        case 6:
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
        printf("2) Delete a number\n");
        printf("3) Search a number\n");
        printf("4) Display the tree\n");
        printf("5) Get size\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 6);
    return choice;
}

node *getNode(int num)
{
    node *temp = (node *)(malloc(sizeof(node)));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(int number)
{
    root = insert_helper(root, number);
    size++;
}

node *insert_helper(node *root, int number)
{
    if (root == NULL)
    {
        return getNode(number);
    }
    if (number < root->data)
    {
        root->left = insert_helper(root->left, number);
    }
    else if (number > root->data)
    {
        root->right = insert_helper(root->right, number);
    }
    return root;
}

void delete(int num)
{
    root = delete_helper(root, num);
}

node *delete_helper(node *root, int num)
{
    if (root == NULL)
    {
        printf("%d not found.\n", num);
        return NULL;
    }
    if (num < root->data)
    {
        root->left = delete_helper(root->left, num);
    }
    else if (num > root->data)
    {
        root->right = delete_helper(root->right, num);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            size--;
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            size--;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            size--;
            return temp;
        }
        else
        {
            node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_helper(root->right, temp->data);
        }
    }
    return root;
}

node *find_min(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

void search(int num)
{
    int index = search_helper(root, num);
    if (index == -1)
    {
        printf("%d not found.\n", num);
    }
    else
    {
        printf("%d found.\n", num);
    }
}

int search_helper(node *root, int num)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == num)
    {
        return 1;
    }
    if (num < root->data)
    {
        return search_helper(root->left, num);
    }
    else
    {
        return search_helper(root->right, num);
    }
}

void display(node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int getSize(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        return getSize(root->left) + 1 + getSize(root->right);
    }
}


void flush_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
