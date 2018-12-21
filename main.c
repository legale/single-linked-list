#include <stdio.h>


#include "single_list.h"

int main() {

    const char words[][100] = {
            "abc",
            "def",
            "jki",
            "123",
            "z"
    };

    llist_s *list = LIST_INIT();

    for(int i = 0; i < 5; ++i){
        list_set(list,words[i], (void *)111);
    }

    for(int i = 0; i < 5; ++i){
        string_s *key = create_string(words[i], 0);
        llist_node_s *node = list_get_node(list, key);
        printf("src key: %s dst key: %s key len: %u val: %u\n", words[i], node->key->val, node->key->len, (uint64_t)node->pointer);
        free(key);
    }


    list_free(list);

}