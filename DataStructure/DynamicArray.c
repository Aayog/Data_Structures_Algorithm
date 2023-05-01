#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4
#define GROWTH_FACTOR 2

int *array;
int capacity = 0;
int size = 0;

void insert(int number);
void delete(int num);
void search(int num);
void update(int position, int number);
void display();
int getSize();

int menu()
{
    int choice;
    printf("\n1) Insert a number.\n");
    printf("2) Search a number.\n");
    printf("3) Update a number.\n");
    printf("4) Delete a number.\n");
    printf("5) Display the array.\n");
    printf("6) Get size.\n");
    printf("7) Exit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    array = calloc(INITIAL_CAPACITY, sizeof(int));
    capacity = INITIAL_CAPACITY;
    int choice, num, pos;
    while (1)
    {
        choice = menu();
        switch (choice)
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
            printf("Enter the position to update: ");
            scanf("%d", &pos);
            printf("Enter the new number: ");
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

void insert(int number) {
    if (size == capacity) {
        capacity *= GROWTH_FACTOR;
        int *new_array = realloc(array, capacity * sizeof(int));
        if (new_array == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
        array = new_array;
    }
    array[size] = number;
    size++;
}

void delete(int num) {
    int i, j;
    for (i = 0; i < size; i++) {
        if (array[i] == num) {
            for (j = i; j < size - 1; j++) {
                array[j] = array[j + 1];
            }
            size--;
            return;
        }
    }
    printf("%d not found.\n", num);
}

void search(int num) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == num) {
            printf("%d found in position %d.\n", num, i);
            return;
        }
    }
    printf("%d not found.\n", num);
}

void update(int position, int number) {
    if (position < 0 || position >= size) {
        printf("Error: Invalid position.\n");
        return;
    }
    array[position] = number;
}

void display() {
    int i;
    printf("Array contents:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int getSize() {
    return size;
}