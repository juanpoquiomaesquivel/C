#include "JXStack.h"

typedef struct jxs_node
{
    void *info;
    struct jxs_node *previous;
} JXSNode;

static JXSNode *jxs_new_node(void *info)
{
    JXSNode *nd = (JXSNode *)malloc(sizeof(JXSNode));

    if (nd == NULL)
        exit(EXIT_FAILURE);

    nd->info = info;
    nd->previous = NULL;

    return nd;
}

static void jxs_free_node(JXSNode *node, void (*func_free)(void *ptr))
{
    if (func_free != NULL)
        func_free(node->info);

    free(node);
}

void jxs_push(JXStack *jxs, void *info)
{
    JXSNode *nd = jxs_new_node(info);

    if (jxs_is_empty(*jxs))
        jxs->top = nd;
    else
    {
        JXSNode *aux = jxs->top;
        nd->previous = aux;
        jxs->top = nd;
    }
}

void jxs_pop(JXStack *jxs)
{
    if (!jxs_is_empty(*jxs))
    {
        JXSNode *aux = jxs->top;
        jxs->top = aux->previous;
        jxs_free_node(aux, jxs->func_free);
    }
}

void *jxs_top(JXStack jxs)
{
    return !jxs_is_empty(jxs) ? jxs.top->info : NULL;
}

void jxs_clear(JXStack *jxs)
{
    if (!jxs_is_empty(*jxs))
    {
        JXSNode *aux = jxs->top;

        do
        {
            jxs->top = aux->previous;
            jxs_free_node(aux, jxs->func_free);
            aux = jxs->top;
        }
        while (aux != NULL);
    }
}

bool jxs_is_empty(JXStack jxs)
{
    return jxs.top == NULL;
}

void jxs_show(JXStack jxs)
{
    puts("Stack [");

    if (!jxs_is_empty(jxs))
    {
        JXSNode *aux = jxs.top;
        char *str;

        do
        {
            str = jxs.func_show != NULL ? jxs.func_show(aux->info) : "_";
            printf("\t%s\n", str);
            free(str);
            aux = aux->previous;
        }
        while (aux != NULL);
    }

    puts("]");
}
