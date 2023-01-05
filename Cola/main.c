#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val;
    struct nodo *sig;
} Nodo;

typedef struct cola
{
    Nodo *cab;
} Cola;

Nodo *crear_nodo(int val);
void encolar(Cola *c, int val);
bool decolar(Cola *c);
int frente(Cola c);
int cola(Cola c);
bool borrar(Cola *c);
void mostrar(Cola c);
bool esta_vacia(Cola c);

int menu()
{
    int op;
    Cola c = {.cab = NULL};
    int val;

    do
    {
        puts("Cola...");
        puts("[0] Salir");
        puts("[1] Encolar");
        puts("[2] Decolar");
        puts("[3] Frente");
        puts("[4] Cola");
        puts("[5] Borrar");
        puts("[6] Mostrar");
        puts("[7] Esta vacia?");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            borrar(&c);

            return EXIT_SUCCESS;
        case 1:
            printf("Ingrese valor a encolar: ");
            scanf("%d", &val);
            encolar(&c, val);
            break;
        case 2:
            puts("Decolando...");
            decolar(&c);
            break;
        case 3:
            printf("Valor en el frente: %d\n", frente(c));
            break;
        case 4:
            printf("Valor en la cola: %d\n", cola(c));
            break;
        case 5:
            puts("Borrando la cola...");
            borrar(&c);
            break;
        case 6:
            mostrar(c);
            break;
        case 7:
            printf("Esta vacia? %s\n", esta_vacia(c) ? "yes" : "no");
            break;
        default:
            puts("Elija otra opcion...");
        }

        system("pause");
        system("cls");
    }
    while (true);
}

int main()
{
    return menu();
}

Nodo *crear_nodo(int val)
{
    Nodo *nd = (Nodo *)malloc(sizeof(Nodo));

    if (nd == NULL)
        exit(EXIT_FAILURE);

    nd->val = val;
    nd->sig = NULL;

    return nd;
}

void encolar(Cola *c, int val)
{
    Nodo *nd = crear_nodo(val);

    if (esta_vacia(*c))
        c->cab = nd;
    else
    {
        Nodo *aux = c->cab;

        while (aux->sig != NULL)
            aux = aux->sig;

        aux->sig = nd;
    }
}

bool decolar(Cola *c)
{
    if (!esta_vacia(*c))
    {
        Nodo *aux = c->cab;
        c->cab = c->cab->sig;
        free(aux);

        return true;
    }
    else
        return false;
}

int frente(Cola c)
{
    if (!esta_vacia(c))
        return c.cab->val;
    else
        return -9999;
}

int cola(Cola c)
{
    if (!esta_vacia(c))
    {
        Nodo *aux = c.cab;

        while (aux->sig != NULL)
            aux = aux->sig;

        return aux->val;
    }
    else
        return -9999;
}

bool borrar(Cola *c)
{
    if (!esta_vacia(*c))
    {
        Nodo *aux;

        do
        {
            aux = c->cab;
            c->cab = c->cab->sig;
            free(aux);
        }
        while (c->cab != NULL);

        return true;
    }
    else
        return false;
}

void mostrar(Cola c)
{
    printf("Cola [ ");

    if (!esta_vacia(c))
    {
        Nodo *aux = c.cab;

        do
        {
            printf("%d ", aux->val);
            aux = aux->sig;
        }
        while (aux != NULL);
    }

    puts("]");
}

bool esta_vacia(Cola c)
{
    return c.cab == NULL;
}
