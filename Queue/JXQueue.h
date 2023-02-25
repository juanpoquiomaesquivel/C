#ifndef JXQUEUE_H_INCLUDED
#define JXQUEUE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct jxq_queue
{
    struct jxq_node *root;
    void (*func_free)(void *p);
    char *(*func_show)(const void *p);
} JXQueue;

void jxq_enqueue(JXQueue *jxq, void *datum);
void jxq_dequeue(JXQueue *jxq);
void *jxq_peek(JXQueue jxq);
void jxq_clear(JXQueue *jxq);
bool jxq_is_empty(JXQueue jxq);
void jxq_show(JXQueue jxq);

#endif // JXQUEUE_H_INCLUDED
