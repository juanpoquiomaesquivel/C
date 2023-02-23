#ifndef JXQUEUE_H_INCLUDED
#define JXQUEUE_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct jxnode
{
    char *str;
    struct jxnode *next;
} JXNode;

typedef struct jxqueue
{
    JXNode *root;
} JXQueue;

JXNode *jx_newNode(char *);
void jx_freeNode(JXNode *);
void jx_enqueue(JXQueue *, char *);
void jx_dequeue(JXQueue *);
char *jx_front(JXQueue );
void jx_clean(JXQueue *);
size_t jx_size(JXQueue );
bool jx_isEmpty(JXQueue );
void jx_show(JXQueue );

#endif // JXQUEUE_H_INCLUDED
