#include "JXQueue.h"

typedef struct jxq_node
{
    void *info;
    struct jxq_node *next;
} JXQNode;

static JXQNode *jxq_new_node(void *info)
{
    JXQNode *nd = (JXQNode *)malloc(sizeof(JXQNode));

    if (nd == NULL)
        exit(EXIT_FAILURE);

    nd->info = info;
    nd->next = NULL;

    return nd;
}

static void jxq_free_node(JXQNode *node, void (*func_free)(void *p))
{
    if (func_free != NULL)
        func_free(node->info);

    free(node);
}

void jxq_enqueue(JXQueue *jxq, void *info)
{
    JXQNode *nd = jxq_new_node(info);

    if (jxq_is_empty(*jxq))
        jxq->root = nd;
    else
    {
        JXQNode *aux = jxq->root;

        while (aux->next != NULL)
            aux = aux->next;

        aux->next = nd;
    }
}

void jxq_dequeue(JXQueue *jxq)
{
    if (!jxq_is_empty(*jxq))
    {
        JXQNode *aux = jxq->root;
        jxq->root = aux->next;
        jxq_free_node(aux, jxq->func_free);
    }
}

void *jxq_peek(JXQueue jxq)
{
    return !jxq_is_empty(jxq) ? jxq.root->info : NULL;
}

void jxq_clear(JXQueue *jxq)
{
    if (!jxq_is_empty(*jxq))
    {
        JXQNode *aux = jxq->root;

        do
        {
            jxq->root = aux->next;
            jxq_free_node(aux, jxq->func_free);
            aux = jxq->root;
        }
        while (aux != NULL);
    }
}

bool jxq_is_empty(JXQueue jxq)
{
    return jxq.root == NULL;
}

void jxq_show(JXQueue jxq)
{
    printf("Queue [ ");

    if (!jxq_is_empty(jxq))
    {
        JXQNode *aux = jxq.root;
        char *str;

        do
        {
            str = jxq.func_show != NULL ? jxq.func_show(aux->info) : "_";
            printf("%s ", str);
            free(str);
            aux = aux->next;
        }
        while (aux != NULL);
    }

    puts("]");
}
