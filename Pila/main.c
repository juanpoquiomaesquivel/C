#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int val;
    struct nodo *abj;
} Nodo;

typedef struct pila {
    Nodo *cima;
} Pila;

Nodo *crear_nodo(int val);
void empilar(Pila *p, int val);
bool depilar(Pila *p);
int cima(Pila p);
bool borrar(Pila *p);
void mostrar(Pila p);
bool esta_vacia(Pila p);

int menu() {
    int op;
    Pila p = {.cima = NULL};
    int val;

    do {
        puts("Pila...");
        puts("[0] Salir");
        puts("[1] Empilar");
        puts("[2] Depilar");
        puts("[3] Cima");
        puts("[4] Borrar");
        puts("[5] Mostrar");
        puts("[6] Esta vacia?");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op) {
        case 0:
            borrar(&p);

            return EXIT_SUCCESS;
        case 1:
            printf("Ingrese valor a empilar: ");
            scanf("%d", &val);
            empilar(&p, val);
            break;
        case 2:
            puts("Depilando...");
            depilar(&p);
            break;
        case 3:
            printf("Valor en la cima: %d\n", cima(p));
            break;
        case 4:
            puts("Borrando la pila...");
            borrar(&p);
            break;
        case 5:
            mostrar(p);
            break;
        case 6:
            printf("Esta vacia? %s\n", esta_vacia(p) ? "yes" : "no");
            break;
        default:
            puts("Elija otra opcion...");
        }

        system("pause");
        system("cls");
    } while (true);
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
    nd->abj = NULL;

    return nd;
}

void empilar(Pila *p, int val)
{
    Nodo *nd = crear_nodo(val);

    if (!esta_vacia(*p))
        nd->abj = p->cima;

    p->cima = nd;
}

bool depilar(Pila *p)
{
    if (!esta_vacia(*p))
    {
        Nodo *aux = p->cima;
        p->cima = p->cima->abj;
        free(aux);

        return true;
    }
    else
        return false;
}

int cima(Pila p)
{
    if (!esta_vacia(p))
        return p.cima->val;
    else
        return -9999;
}

bool borrar(Pila *p)
{
    if (!esta_vacia(*p))
    {
        Nodo *aux;

        do
        {
            aux = p->cima;
            p->cima = p->cima->abj;
            free(aux);
        }
        while (p->cima != NULL);

        return true;
    }
    else
        return false;
}

void mostrar(Pila p)
{
    printf("Pila [ ");

    if (!esta_vacia(p))
    {
        Nodo *aux = p.cima;

        do
        {
            printf("%d ", aux->val);
            aux = aux->abj;
        }
        while (aux != NULL);
    }

    puts("]");
}

bool esta_vacia(Pila p)
{
    return p.cima == NULL;
}
