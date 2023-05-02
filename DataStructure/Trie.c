#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct trie_node_struct {
    int is_end_of_word;
    struct trie_node_struct *children[ALPHABET_SIZE];
} trie_node;

trie_node *getTrieNode();
void insert(trie_node *root, const char *key);
int search(trie_node *root, const char *key);
void display(trie_node *root);
void flush_input_buffer();
int menu();

int main() {
    trie_node *root = getTrieNode();
    int ch;
    while (1) {
        ch = menu();
        char key[50];
        switch (ch) {
            case 1:
                printf("Enter a key to insert: \n");
                scanf("%s", key);
                insert(root, key);
                break;
            case 2:
                printf("Enter a key to search: \n");
                scanf("%s", key);
                if (search(root, key)) {
                    printf("%s found in trie.\n", key);
                } else {
                    printf("%s not found in trie.\n", key);
                }
                break;
            case 3:
                display(root);
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    }
}

int menu() {
    int choice;
    do {
        printf("\n1) Insert a key\n");
        printf("2) Search a key\n");
        printf("3) Display the trie\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 4);
    return choice;
}

trie_node *getTrieNode() {
    trie_node *node = (trie_node *)malloc(sizeof(trie_node));
    node->is_end_of_word = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(trie_node *root, const char *key) {
    int len = strlen(key);
    trie_node *temp = root;
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (!temp->children[index]) {
            temp->children[index] = getTrieNode();
        }
        temp = temp->children[index];
    }
    temp->is_end_of_word = 1;
}

int search(trie_node *root, const char *key) {
    int len = strlen(key);
    trie_node *temp = root;
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (!temp->children[index]) {
            return 0;
        }
        temp = temp->children[index];
    }
    return (temp != NULL && temp->is_end_of_word);
}

void display_trie(trie_node *root, char *buffer, int depth) {
    if (root->is_end_of_word) {
        buffer[depth] = '\0';
        printf("%*s- %s\n", depth * 2, "", buffer);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            buffer[depth] = i + 'a';
            display_trie(root->children[i], buffer, depth + 1);
        }
    }
}

void display(trie_node *root) {
    printf("\n");
    char buffer[50];
    display_trie(root, buffer, 0);
}


void flush_input_buffer() {
int c;
while ((c = getchar()) != '\n' && c != EOF) {
}
}
