# C++ String Reversal with a Linked List

**C++ console application** that demonstrates how to reverse a string in-place using a singly linked list.
The program reads a string from the user, builds a linked list where each node contains a character, reverses the list by re-linking the node pointers, prints the reversed string, and then frees all allocated memory.

---

## How It Works

- **User Input:** Prompts the user to enter a string.  
- **Build List:** Dynamically creates a linked list, with each character of the input string stored in a separate `Node`.  
- **Reverse List:** Reverses the list by iterating through it and redirecting the `next` pointers of each node.  
- **Print Result:** Traverses the newly reversed list and prints each character to the console.  
- **Memory Management:** Properly deallocates all nodes to prevent memory leaks.  
