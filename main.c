#include "list.h"

int main(){
    record *root = NULL;

    insert_sorted(&root, "bbb");
    insert_sorted(&root, "ccc");
    insert_sorted(&root, "aaa");
    insert_sorted(&root, "ddd");
    insert_sorted(&root, "eee");
    output_list(root);
    free_list(root);

    return(0);
}
