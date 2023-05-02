#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, int num);
int pop(Stack *s);
int peek(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);

int main() {
    Stack s;
    s.top = -1;

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("Top of stack: %d\n", peek(&s));
    printf("Popped %d from the stack.\n", pop(&s));
    printf("Top of stack: %d\n", peek(&s));
    printf("Popped %d from the stack.\n", pop(&s));
    printf("Top of stack: %d\n", peek(&s));
    printf("Popped %d from the stack.\n", pop(&s));
    printf("Top of stack: %d\n", peek(&s));

    return 0;
}

void push(Stack *s, int num) {
    if (is_full(s)) {
        printf("Stack overflow.\n");
        return;
    }

    s->top++;
    s->data[s->top] = num;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow.\n");
        return -1;
    }

    int num = s->data[s->top];
    s->top--;

    return num;
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return s->data[s->top];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}
