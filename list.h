#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __list_h__
#define __list_h__

/* linked-list*/

typedef struct rec {
    char *value;
    struct rec *next;
} record;

/* Using insert sort to insert new node into list. */
void insert_sorted(record **r, const char *value);

void delete_node(record **r, const char *value);

void search_node(record *r, const char *value);

void output_list(record *r);

void free_list(record *r);

#endif
