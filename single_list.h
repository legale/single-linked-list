/* file: single_list.h
 *
 * Copyright (C) 2018  legale.legale <legale.legale@gmail.com>
 * This software is provided under MIT license.
 */

#ifndef _SINGLE_LIST_H
#define _SINGLE_LIST_H

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h> //memcmp
#include <stdlib.h> //malloc

#include "inline.h"
#include "likely.h"

//#include "../utils/inline.h"    //INLINE constant


//structures
typedef struct _string_s {
    size_t len;
    char val[1];
} string_s;


typedef struct _llist_node_s {
    void *pointer;
    string_s *key;
    struct _llist_node_s *next;
} llist_node_s;


//list_s
typedef struct _llist_s {
    uint32_t elements; //list_s elements counter
    llist_node_s *head; //head node_s
    llist_node_s *tail; //tail node_s
} llist_s;


//functions declaration
bool list_set(llist_s *list, const char *key, void *pointer);

void *list_cut_first(llist_s *list);

llist_node_s *list_get_node(llist_s *list, string_s *key);

void *list_cut_p(llist_s *list, string_s *key);

void *list_get_p(llist_s *list, string_s *key);

void list_free(llist_s *lst);



/* Macros */

#define STR_VAL(str) (str)->val
#define STR_LEN(str) (str)->len

#define STRING_EQ(s1, s2) (s1 == s2 || (STR_LEN(s1) == STR_LEN(s2) && !memcmp(STR_VAL(s1), STR_VAL(s2), STR_LEN(s1))))

#define LIST_INIT() ((llist_s *)calloc(1, sizeof(llist_s)))

/*string_s struct size + len + 1 byte terminator */
#define STRING_ALLOC(len) (string_s *)malloc(sizeof(string_s) + (len) + 1)

#define STRING_CPY(src, dst) (memcpy(dst, src, STR_LEN(src)))

static ALWAYS_INLINE bool string_eq(string_s *s1, string_s *s2) {
    return s1 == s2 || (STR_LEN(s1) == STR_LEN(s2) && !memcmp(STR_VAL(s1), STR_VAL(s2), STR_LEN(s1)));
}

static ALWAYS_INLINE string_s *create_string(const char *string, uint64_t len) {
    if (len == 0) len = strlen(string);

    if (UNLIKELY(!len)) return NULL;

    string_s *str = STRING_ALLOC(len);
    str->len = len;

    memcpy(str->val, string, str->len + 1);

    return str;
}


#endif /* single_list.h  */