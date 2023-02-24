#ifndef JXQUEUE_H_INCLUDED
#define JXQUEUE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct jxq_node
{
    void *datum;
    struct jxq_node *next;
} JXQNode;

typedef struct jxq_queue
{
    JXQNode *root;
    void (*func_free)(void *p);
    char *(*func_show)(const void *p);
} JXQueue;

JXQNode *jxq_new_node(void *datum);
void jxq_free_node(JXQNode *jxn, void (* func_free)(void *p));
void jxq_enqueue(JXQueue *jxq, void *datum);
void jxq_dequeue(JXQueue *jxq);
void *jxq_peek(JXQueue jxq);
void jxq_clear(JXQueue *jxq);
bool jxq_is_empty(JXQueue jxq);
void jxq_show(JXQueue jxq);

#endif // JXQUEUE_H_INCLUDED
