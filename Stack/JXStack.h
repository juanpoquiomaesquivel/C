#ifndef JXSTACK_H_INCLUDED
#define JXSTACK_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct jxs_stack
{
    struct jxs_node *top;
    void (*func_free)(void *ptr);
    int (*func_cmp)(const void *ptr1, const void *ptr2);
    char *(*func_show)(const void *ptr);
} JXStack;

void jxs_push(JXStack *jxs, void *info);
void jxs_pop(JXStack *jxs);
void *jxs_top(JXStack jxs);
void jxs_clear(JXStack *jxq);
bool jxs_is_empty(JXStack jxq);
void jxs_show(JXStack jxq);

#endif // JXSTACK_H_INCLUDED
