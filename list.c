#include "list.h"

void insert_sorted(record **r, const char *value)
{
    if (!value) {
        printf("Can not insert NULL in list.\n");
        return;
    }
    record *newrec = NULL;
    while (*r && strcmp(value, (*r)->value) > 0)
        r = &((*r)->next);
    newrec = malloc(sizeof(record));
    newrec->value = strdup(value);
    newrec->next = *r;
    *r = newrec;
}

void delete_node(record **r, const char *value)
{
    if (!value) {
        printf("Can not delete a NULL in list.\n");
        return;
    }

    while (*r && strcmp(value, (*r)->value) > 0)
        r = &((*r)->next);

    if (!(*r) || strcmp(value, (*r)->value) != 0) {
        printf("%s is not in this list.\n", value);
        return;
    }
    record *ptr = *r;
    *r = (*r)->next;

    free(ptr->value);
    free(ptr);
}

void search_node(record *r, const char *value)
{
    if (!value) {
        printf("NULL is not in this list.\n");
        return;
    }

    int i;
    for (i = 1; r && strcmp(value, r->value) > 0; i++)
        r = r->next;
    if (r && strcmp(value, r->value) == 0)
        printf("%s is at %d position.\n", value, i);
    else
        printf("Can not find %s in this list.\n", value);
}

void output_list(record *r)
{
    while(r){
        printf("%s->",r->value);
        r = r->next;
    }
    printf("\n");
}

void free_list(record *r)
{
    record *ptr = r;
    while (ptr) {
        free(ptr->value);
        r = r->next;
        free(ptr);
        ptr = r;
    }
}

