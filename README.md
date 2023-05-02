# Implementing Data Structures

In computer science, a data structure is a way of organizing and storing data in a computer so that it can be accessed and used efficiently. A wide variety of data structures are available, each with its own strengths and weaknesses. This project aims to implement several common data structures in C language, including linear and non-linear data structures.
## Linear Data Structures
### Dynamic Array

A dynamic array is an array whose size is not determined at compile time but instead can be increased or decreased during runtime. In this project, we implemented a dynamic array using malloc and realloc functions to allocate and reallocate memory. This implementation allows for efficient operations such as appending and accessing elements by index.
Linked List

A linked list is a data structure in which elements are stored in a sequence, and each element is linked to the next element using a pointer. We implemented four different types of linked lists in this project:

    Single Linked List
    Single Circular Linked List
    Double Linked List
    Double Circular Linked List

In each type of linked list, the elements are stored in a linear sequence, and each element has a pointer to the next (and/or previous) element in the list. The circular linked lists have their last element pointing back to the first element to form a cycle. This structure allows for efficient insertion and deletion of elements at any position within the list.
### Stack

A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. It has two main operations: push, which adds an element to the top of the stack, and pop, which removes the top element from the stack. We implemented a stack using a dynamic array as its underlying data structure, allowing for efficient memory usage and resizing as elements are added or removed.
### Queue

A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. It has two main operations: enqueue, which adds an element to the back of the queue, and dequeue, which removes the front element from the queue. We implemented a queue using a circular linked list as its underlying data structure, enabling efficient insertion and deletion operations without the need for additional memory allocation.

--- 

## Non-Linear Data Structures
### Binary Tree

A binary tree is a non-linear data structure in which each node has at most two children. The children are referred to as the left child and the right child. We implemented a binary tree using pointers and dynamic memory allocation. The nodes in the tree are arranged in a hierarchical structure, with the top node called the root. This structure enables efficient traversal algorithms such as in-order, pre-order, and post-order traversals.
### Binary Search Tree

A binary search tree is a special type of binary tree where the left child of a node is always smaller than the node, and the right child is always larger. This property allows for efficient searching, insertion, and deletion of elements. We implemented a binary search tree using pointers and dynamic memory allocation, providing methods for inserting, searching, and deleting elements while maintaining the tree's properties.
### Trie

A trie, also known as a digital tree or prefix tree, is a non-linear data structure used for efficient retrieval of keys. It is typically used for searching for strings in a large set of strings. We implemented a trie using pointers and dynamic memory allocation. Each node in the trie represents a character, and each path from the root to a leaf node represents a unique string. This structure allows for efficient string searching, insertion, and deletion operations while minimizing memory usage.

---

## Implementing algorithms

### Sorting algorithms:
- [ ] Bubble sort
- [ ] Selection sort
- [ ] Insertion sort
- [ ] Merge sort
- [ ] Quick sort
- [ ] Heap sort

### Searching algorithms:

- [ ] Linear search
- [ ] Binary search

### Graph algorithms:

- [ ] Breadth-first search (BFS)
- [ ] Depth-first search (DFS)
- [ ] Dijkstra's algorithm
- [ ] Bellman-Ford algorithm
- [ ] Floyd-Warshall algorithm
- [ ] Prim's algorithm
- [ ] Kruskal's algorithm

### Dynamic programming:

- [ ] Fibonacci series
- [ ] Longest common subsequence (LCS)
- [ ] Knapsack problem
- [ ] Coin change problem
- [ ] Edit distance

### Tree traversal algorithms:

- [ ] Pre-order traversal
- [ ] In-order traversal
- [ ] Post-order traversal

### String manipulation algorithms:

- [ ] Palindrome checking
- [ ] Anagram checking
- [ ] String reversal
- [ ] String matching (KMP algorithm, Boyer-Moore algorithm)

### Bit manipulation algorithms:

- [ ] Bitwise AND, OR, XOR operations
- [ ] Bitwise left and right shift operations
- [ ] Counting set bit
#### Questions from Cracking the coding interview
