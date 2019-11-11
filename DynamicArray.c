#include<stdio.h>
#include<stdlib.h>

int total = 0;
int size = 0;
int* array;

void insert(int number);
void delete(int num);
void search(int num);
void update(int position, int number);
void display();
int getSize();

int menu(){
    int choice;
    do{
        printf(" 1)Insert a number.\n");
        printf(" 2)Search a number.\n");
        printf(" 3)Update a number.\n");
        printf(" 4)Delete a number.\n");
        printf(" 5)Display the array.\n");
        printf(" 6)Get size.\n");
        printf(" 7)Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
    }while(choice < 1 || choice > 7);
    return choice;
}

int main(){
    int ch;
    while(1){
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
            delete(num);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("The array size is %d.\n",getSize());
            break;
        case 7:
            exit(0);    
        default:
            break;
        }
    }

}


void insert(int number){
    if (size == 0){
        array = (int*)(malloc(sizeof(int)*1));
        array[0] = number;
        total++;
    }else if(size <= total){
        array[size] = number;
    }else{
        total *= 2;
        int* temp = array;
        array = realloc(array, sizeof(int)*total);
        int i = 0;
        for(i = 0; i < size; i++){
            array[i] = temp[i];
        }
        array[i] = number;
    }
    size++;
}


void delete(int num){
    int i = 0;
    for(i = 0; i < size; i++){
        if(array[i] == num){
            int j;
            for (j = i; j < size-1; j++){
                array[j] = array[j+1];
            }
            size--;
            return;
        }
    }
    printf("%d not found.\n", num);
}

void search(int num){
    int i = 0;
    for(i = 0; i < size; i++){
        if(array[i] == num){
            printf("%d found in position %d.\n", num, i);
            return;
        }
    }
    printf("%d not found.\n", num);
}

void update(int position, int number){
    if(position < 0 || position > size){
        printf("The position is not in the array.\n");
        return;
    }
    array[position] = number;
}

void display(){
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int getSize(){
    return size;
}