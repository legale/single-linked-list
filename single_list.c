/* file: single_list.c
 *
 * Copyright (C) 2018  legale.legale <legale.legale@gmail.com>
 * This software is provided under MIT license.
 */


#include <stdlib.h>     //malloc() calloc() free()
#include <stdbool.h>    //bool true false
#include <string.h>     //memcpy() memcmp()

#include "single_list.h"




//add list_s element in the end
bool list_set(llist_s *list, const char *key, void *pointer) {
    if(!list || !key) false;
    llist_node_s *new;
    string_s *key_string = create_string(key, 0);

    new = list_get_node(list, key);
    if (!new) {
        new = (llist_node_s *) malloc(sizeof(llist_node_s)); //allocate memory for the new element
//        new->key = STRING_ALLOC(key->len); //allocate memory for the key
//        STRING_CPY(key, new->key); //copy key string to the node key string
    new->key = key_string;
    new->pointer = pointer;
        ++list->elements;
    } else {
        new->pointer = pointer;
        free(key_string);
        return true;
    }

    if (list->tail == NULL) {
        list->tail = new;
        list->head = new;
    } else {
        list->tail->next = new;
        list->tail = new;
    }
    return true;
};

//get first element of the linked list_s
void *list_cut_first(llist_s *list) {
    if (list == NULL || list->head == NULL) {
        return NULL;
    } else {
        void *ptr = list->head->pointer;
        if (list->head == list->tail) { //if head = tail
            free(list->head); //free list_s element memory
            list->head = NULL; //set list_s ptr to NULL
            list->tail = NULL; //set list_s ptr to NULL
        } else {
            llist_node_s *next = list->head->next;

            free(list->head->key);
            free(list->head);
            list->head = next;
        }
        --list->elements;
        return ptr;
    }
}


llist_node_s *list_get_node(llist_s *list, string_s *key) {
    if (list->elements == 0) return NULL;
    llist_node_s *node = list->head;

    while (node) {
        if (STRING_EQ(key, node->key)){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void *list_get_p(llist_s *list, string_s *key) {
    if (list->elements == 0) return NULL;
    llist_node_s *node = list->head;

    while (node) {
        if (STRING_EQ(key, node->key)){
            return node->pointer;
        }
        node = node->next;
    }
    return NULL;
}


void *list_cut_p(llist_s *list, string_s *key) {
    if (list->elements == 0) return NULL;
    llist_node_s *node = list->head;
    llist_node_s *prev = NULL;

    while (node->key) {
        if (STRING_EQ(key, node->key)) {
            if(prev) prev->next = node->next;
            void *ptr = node->pointer;
            free(node->key);
            free(node);
            return ptr;
        }
        prev = node;
        node = node->next;
    }
    return NULL;
}



void list_free(llist_s *lst) {
    if (lst == NULL) return;

    while(lst->head){
        llist_node_s *current = lst->head;
        lst->head = current->next;
        free(current->key);
        free(current);
    }
    free(lst);

}

