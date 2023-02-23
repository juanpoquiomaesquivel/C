#include "JXQueue.h"

JXNode *jx_newNode(char *str)
{
    JXNode *nd = (JXNode *)malloc(sizeof(JXNode));

    if (nd == NULL)
        exit(EXIT_FAILURE);

    nd->str = str;
    nd->next = NULL;
}

void jx_freeNode(JXNode *nd)
{
    free(nd->str);
    free(nd);
}

void jx_enqueue(JXQueue *queue, char *str)
{
    JXNode *nd = jx_newNode(str);

    if (jx_isEmpty(*queue))
        queue->root = nd;
    else
    {
        JXNode *aux = queue->root;

        while (aux->next != NULL)
            aux = aux->next;

        aux->next = nd;
    }
}

void jx_dequeue(JXQueue *queue)
{
    if (!jx_isEmpty(*queue))
    {
        JXNode *aux = queue->root;
        queue->root = aux->next;
        jx_freeNode(aux);
    }
}

char *jx_front(JXQueue queue)
{
    return queue.root->str;
}

void jx_clean(JXQueue *queue)
{
    JXNode *aux = queue->root;

    while (aux != NULL)
    {
        queue->root = aux->next;
        jx_freeNode(aux);
        aux = queue->root;
    }
}

size_t jx_size(JXQueue queue)
{
    JXNode *aux = queue.root;
    size_t len = 0;

    while (aux != NULL)
    {
        len++;
        aux = aux->next;
    }

    return len;
}

bool jx_isEmpty(JXQueue queue)
{
    return queue.root == NULL;
}

void jx_show(JXQueue queue)
{
    JXNode *aux = queue.root;
    printf("Queue [ ");

    while (aux != NULL)
    {
        printf("%s ", aux->str);
        aux = aux->next;
    }

    puts("]");
}
