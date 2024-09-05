//Uditi Madan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

/* 
 * adds a new node with a given (key, value) in the beginning of the linked list
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 * @return: a pointer to the new head of the linked list
 */
node* add(node* head, char* key, char* value) {

    //new node initialization
    node* newNode = (node*)malloc(sizeof(node));

    //malloc error handling
    if (newNode == NULL) {
        printf("Memory allocation failed");
        return 0;
    }

    //adding the new node with key and value to the head
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = head;

    return newNode; //returning the pointer
}

/* 
 * gets a value for the given key 
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: the corresponding value if the key is found, NULL otherwise
 */
char* get(node* head, char* key) {

    //initializing the key to find it's value in the linked list
    node* current = head;

    //finding the specified current key pair from the linked list
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; //returning the value of the key
        }
      current = current->next;
    }
  return NULL;
}

/* 
 * delete the node with the given key if found
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: a pointer to the new head of the linked list
 */
node* delete(node* head, char* key) {

    node* current = head;
    node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
            
                // if the node to be deleted is found at the top ie. head
                head = current->next;
                
            } else {
                prev->next = current->next;
            }
            
            //freeing the allocated memory space of the deleted linked list pair 
            free(current->key);
            free(current->value);
            free(current);
            return head;
        }
      prev = current;
      current = current->next;
    }
  return head;
}

/* 
 * prints the linked list
 * @param: head is the pointer to the first node in the linked list
 */
void printList(node* head) {

    node* current = head;
    printf("["); 
    while (current != NULL) {
    
        //printing the linked list key-value pair
        printf("[%s,%s]", current->key, current->value);
        if (current->next != NULL) {
            printf(",");    
        }
      current = current->next;
    }
  printf("]");
  printf("\n");
}
