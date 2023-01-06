#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val;
    struct nodo *ant;
    struct nodo *sig;
} Nodo;

typedef struct lde
{
    Nodo *cab;
} Lde;

Nodo *crear_nodo(int val);
void insertar_al_inicio(Lde *ld, int val);
void insertar_al_final(Lde *ld, int val);
bool insertar_antes_de(Lde *ld, int val, int pos);
bool insertar_despues_de(Lde *ld, int val, int pos);
bool reemplazar_en(Lde *ld, int val, int pos);
bool eliminar_el_primero(Lde *ld);
bool eliminar_el_ultimo(Lde *ld);
bool eliminar_antes_de(Lde *ld, int pos);
bool eliminar_despues_de(Lde *ld, int pos);
bool eliminar_en(Lde *ld, int pos);
int obtener_el_primero(Lde ld);
int obtener_el_ultimo(Lde ld);
int obtener_antes_de(Lde ld, int pos);
int obtener_despues_de(Lde ld, int pos);
int obtener_en(Lde ld, int pos);
bool borrar(Lde *ld);
void mostrar(Lde ld);
bool esta_vacia(Lde ld);

int menu()
{
    int op;
    Lde ld = {.cab = NULL};
    int val, pos;

    do
    {
        puts("Lista doblemente enlazada...");
        puts("[0] Salir");
        puts("[1] Insertar al inicio");
        puts("[2] Insertar al final");
        puts("[3] Insertar antes de");
        puts("[4] Insertar despues de");
        puts("[5] Reemplazar en");
        puts("[6] Eliminar el primero");
        puts("[7] Eliminar el ultimo");
        puts("[8] Eliminar antes de");
        puts("[9] Eliminar despues de");
        puts("[10] Eliminar en");
        puts("[11] Obtener el primero");
        puts("[12] Obtener el ultimo");
        puts("[13] Obtener antes de");
        puts("[14] Obtener despues de");
        puts("[15] Obtener en");
        puts("[16] Borrar");
        puts("[17] Mostrar");
        puts("[18] Esta vacia?");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            borrar(&ld);

            return EXIT_SUCCESS;
        case 1:
            printf("Ingrese valor a enlistar al inicio: ");
            scanf("%d", &val);
            insertar_al_inicio(&ld, val);
            break;
        case 2:
            printf("Ingrese valor a enlistar al final: ");
            scanf("%d", &val);
            insertar_al_final(&ld, val);
            break;
        case 3:
            printf("Ingrese valor a enlistar antes de: ");
            scanf("%d", &val);
            printf("Ingrese posicion de referencia: ");
            scanf("%d", &pos);
            insertar_antes_de(&ld, val, pos);
            break;
        case 4:
            printf("Ingrese valor a enlistar despues de: ");
            scanf("%d", &val);
            printf("Ingrese posicion de referencia: ");
            scanf("%d", &pos);
            insertar_despues_de(&ld, val, pos);
            break;
        case 5:
            printf("Ingrese valor a enlistar en lugar de: ");
            scanf("%d", &val);
            printf("Ingrese posicion de referencia: ");
            scanf("%d", &pos);
            reemplazar_en(&ld, val, pos);
            break;
        case 6:
            printf("Eliminando el primero...");
            eliminar_el_primero(&ld);
            break;
        case 7:
            printf("Eliminando el ultimo...");
            eliminar_el_ultimo(&ld);
            break;
        case 8:
            printf("Ingrese posicion de referencia a eliminar antes de: ");
            scanf("%d", &pos);
            eliminar_antes_de(&ld, pos);
            break;
        case 9:
            printf("Ingrese posicion de referencia a eliminar despues de: ");
            scanf("%d", &pos);
            eliminar_despues_de(&ld, pos);
            break;
        case 10:
            printf("Ingrese posicion de referencia a eliminar en: ");
            scanf("%d", &pos);
            eliminar_en(&ld, pos);
            break;
        case 11:
            printf("Valor al inicio: %d\n", obtener_el_primero(ld));
            break;
        case 12:
            printf("Valor al final: %d\n", obtener_el_ultimo(ld));
            break;
        case 13:
            printf("Ingrese posicion de referencia a obtener antes de: ");
            scanf("%d", &pos);
            printf("Valor antes de: %d\n", obtener_antes_de(ld, pos));
            break;
        case 14:
            printf("Ingrese posicion de referencia a obtener despues de: ");
            scanf("%d", &pos);
            printf("Valor despues de: %d\n", obtener_despues_de(ld, pos));
            break;
        case 15:
            printf("Ingrese posicion de referencia a obtener en: ");
            scanf("%d", &pos);
            printf("Valor en: %d\n", obtener_en(ld, pos));
            break;
        case 16:
            puts("Borrando la lista...");
            borrar(&ld);
            break;
        case 17:
            mostrar(ld);
            break;
        case 18:
            printf("Esta vacia? %s\n", esta_vacia(ld) ? "yes" : "no");
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
    nd->ant = NULL;
    nd->sig = NULL;

    return nd;
}

void insertar_al_inicio(Lde *ld, int val)
{
    Nodo *nd = crear_nodo(val);

    if (!esta_vacia(*ld))
    {
        nd->sig = ld->cab;
        ld->cab->ant = nd;
    }

    ld->cab = nd;
}

void insertar_al_final(Lde *ld, int val)
{
    Nodo *nd = crear_nodo(val);

    if (esta_vacia(*ld))
        ld->cab = nd;
    else
    {
        Nodo *aux = ld->cab;

        while (aux->sig != NULL)
            aux = aux->sig;

        aux->sig = nd;
        nd->ant = aux;
    }
}

bool insertar_antes_de(Lde *ld, int val, int pos)
{
    if (!esta_vacia(*ld) && pos >= 0)
    {
        Nodo *aux = ld->cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
        {
            Nodo *nd = crear_nodo(val);
            nd->sig = aux;

            if (aux == ld->cab)
            {
                nd->sig = ld->cab;
                ld->cab->ant = nd;
                ld->cab = nd;
            }
            else
            {
                aux->ant->sig = nd;
                nd->ant = aux->ant;
                nd->sig = aux;
                aux->ant = nd;
            }

            return true;
        }
    }

    return false;
}

bool insertar_despues_de(Lde *ld, int val, int pos)
{
    if (!esta_vacia(*ld) && pos >= 0)
    {
        Nodo *aux = ld->cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
        {
            Nodo *nd = crear_nodo(val);

            if (aux->sig != NULL)
            {
                nd->sig = aux->sig;
                aux->sig->ant = nd;
            }

            aux->sig = nd;
            nd->ant = aux;

            return true;
        }
    }

    return false;
}

bool reemplazar_en(Lde *ld, int val, int pos)
{
    if (!esta_vacia(*ld) && pos >= 0)
    {
        Nodo *aux = ld->cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
        {
            aux->val = val;

            return true;
        }
    }

    return false;
}

bool eliminar_el_primero(Lde *ld)
{
    if (!esta_vacia(*ld))
    {
        Nodo *aux = ld->cab;
        ld->cab = ld->cab->sig;

        if (ld->cab != NULL)
            ld->cab->ant = NULL;

        free(aux);

        return true;
    }
    else
        return false;
}

bool eliminar_el_ultimo(Lde *ld)
{
    if (!esta_vacia(*ld))
    {
        Nodo *aux = ld->cab;

        while (aux->sig != NULL)
            aux = aux->sig;

        if (aux == ld->cab)
            ld->cab = NULL;
        else
            aux->ant->sig = NULL;

        free(aux);

        return true;
    }
    else
        return false;
}

bool eliminar_antes_de(Lde *ld, int pos)
{
    if (!esta_vacia(*ld) && pos >= 0)
    {
        Nodo *aux = ld->cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
            if (aux != ld->cab)
            {
                Nodo *_aux = aux->ant;

                if (_aux == ld->cab)
                {
                    ld->cab = aux;
                    ld->cab->ant = NULL;
                }
                else
                {
                    _aux->ant->sig = aux;
                    aux->ant = _aux->ant;
                }

                free(_aux);

                return true;
            }
    }

    return false;
}

bool eliminar_despues_de(Lde *ld, int pos)
{
    if (!esta_vacia(*ld) && pos >= 0)
    {
        Nodo *aux = ld->cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
            if (aux->sig != NULL)
            {
                Nodo *aux_ = aux->sig;
                aux->sig = aux_->sig;

                if (aux_->sig != NULL)
                    aux_->sig->ant = aux;

                free(aux_);

                return true;
            }
    }

    return false;
}

bool eliminar_en(Lde *ld, int pos)
{
    if (!esta_vacia(*ld) && pos >= 0)
    {
        Nodo *aux = ld->cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
        {
            if (aux == ld->cab)
            {
                ld->cab = ld->cab->sig;

                if (ld->cab != NULL)
                    ld->cab->ant = NULL;
            }
            else
            {
                aux->ant->sig = aux->sig;

                if (aux->sig != NULL)
                    aux->sig->ant = aux->ant;
            }

            free(aux);

            return true;
        }
    }

    return false;
}

int obtener_el_primero(Lde ld)
{
    if (!esta_vacia(ld))
        return ld.cab->val;
    else
        return -9999;
}

int obtener_el_ultimo(Lde ld)
{
    if (!esta_vacia(ld))
    {
        Nodo *aux = ld.cab;

        while (aux->sig != NULL)
            aux = aux->sig;

        return aux->val;
    }
    else
        return -9999;
}

int obtener_antes_de(Lde ld, int pos)
{
    if (!esta_vacia(ld) && pos >= 0)
    {
        Nodo *aux = ld.cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
            if (aux != ld.cab)
                return aux->ant->val;
    }

    return -9999;
}

int obtener_despues_de(Lde ld, int pos)
{
    if (!esta_vacia(ld) && pos >= 0)
    {
        Nodo *aux = ld.cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
            if (aux->sig != NULL)
                return aux->sig->val;
    }

    return -9999;
}

int obtener_en(Lde ld, int pos)
{
    if (!esta_vacia(ld) && pos >= 0)
    {
        Nodo *aux = ld.cab;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            aux = aux->sig;
            i++;
        }

        if (i == pos)
            return aux->val;
    }

    return -9999;
}

bool borrar(Lde *ld)
{
    if (!esta_vacia(*ld))
    {
        Nodo *aux;

        do
        {
            aux = ld->cab;
            ld->cab = ld->cab->sig;
            free(aux);
        }
        while (ld->cab != NULL);

        return true;
    }
    else
        return false;
}

void mostrar(Lde ld)
{
    printf("Lde [ ");

    if (!esta_vacia(ld))
    {
        Nodo *aux = ld.cab;

        do
        {
            printf("%d ", aux->val);
            aux = aux->sig;
        }
        while (aux != NULL);
    }

    puts("]");
}

bool esta_vacia(Lde ld)
{
    return ld.cab == NULL;
}
