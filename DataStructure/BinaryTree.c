#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int data;
    struct node_struct *left;
    struct node_struct *right;
} node;

node *root = NULL;

node *get_node(int value) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(int value) {
    if (root == NULL) {
        root = get_node(value);
        return;
    }
    node *current_node = root;
    while (1) {
        if (value <= current_node->data) {
            if (current_node->left == NULL) {
                current_node->left = get_node(value);
                return;
            } else {
                current_node = current_node->left;
            }
        } else {
            if (current_node->right == NULL) {
                current_node->right = get_node(value);
                return;
            } else {
                current_node = current_node->right;
            }
        }
    }
}

int search(int value) {
    node *current_node = root;
    while (current_node != NULL) {
        if (current_node->data == value) {
            return 1;
        } else if (value < current_node->data) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }
    return 0;
}

void print_in_order(node *current_node) {
    if (current_node == NULL) {
        return;
    }
    print_in_order(current_node->left);
    printf("%d ", current_node->data);
    print_in_order(current_node->right);
}

int main() {
    int choice;
    while (1) {
        printf("1) Insert\n");
        printf("2) Search\n");
        printf("3) Display (in-order traversal)\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int value;
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(value)) {
                    printf("%d found in the tree.\n", value);
                } else {
                    printf("%d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("In-order traversal: ");
                print_in_order(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
