#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val;
    struct nodo *sig;
} Nodo;

typedef struct lse
{
    Nodo *cab;
} Lse;

Nodo *crear_nodo(int val);
void insertar_al_inicio(Lse *ls, int val);
void insertar_al_final(Lse *ls, int val);
bool insertar_antes_de(Lse *ls, int val, int pos);
bool insertar_despues_de(Lse *ls, int val, int pos);
bool reemplazar_en(Lse *ls, int val, int pos);
bool eliminar_el_primero(Lse *ls);
bool eliminar_el_ultimo(Lse *ls);
bool eliminar_antes_de(Lse *ls, int pos);
bool eliminar_despues_de(Lse *ls, int pos);
bool eliminar_en(Lse *ls, int pos);
int obtener_el_primero(Lse ls);
int obtener_el_ultimo(Lse ls);
int obtener_antes_de(Lse ls, int pos);
int obtener_despues_de(Lse ls, int pos);
int obtener_en(Lse ls, int pos);
bool borrar(Lse *ls);
void mostrar(Lse ls);
bool esta_vacia(Lse ls);

int menu()
{
    int op;
    Lse ls = {.cab = NULL};
    int val, pos;

    do
    {
        puts("Lista simplemente enlazada...");
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
            borrar(&ls);

            return EXIT_SUCCESS;
        case 1:
            printf("Ingrese valor a enlistar al inicio: ");
            scanf("%d", &val);
            insertar_al_inicio(&ls, val);
            break;
        case 2:
            printf("Ingrese valor a enlistar al final: ");
            scanf("%d", &val);
            insertar_al_final(&ls, val);
            break;
        case 3:
            printf("Ingrese valor a enlistar antes de: ");
            scanf("%d", &val);
            printf("Ingrese posicion de referencia: ");
            scanf("%d", &pos);
            insertar_antes_de(&ls, val, pos);
            break;
        case 4:
            printf("Ingrese valor a enlistar despues de: ");
            scanf("%d", &val);
            printf("Ingrese posicion de referencia: ");
            scanf("%d", &pos);
            insertar_despues_de(&ls, val, pos);
            break;
        case 5:
            printf("Ingrese valor a enlistar en lugar de: ");
            scanf("%d", &val);
            printf("Ingrese posicion de referencia: ");
            scanf("%d", &pos);
            reemplazar_en(&ls, val, pos);
            break;
        case 6:
            printf("Eliminando el primero...");
            eliminar_el_primero(&ls);
            break;
        case 7:
            printf("Eliminando el ultimo...");
            eliminar_el_ultimo(&ls);
            break;
        case 8:
            printf("Ingrese posicion de referencia a eliminar antes de: ");
            scanf("%d", &pos);
            eliminar_antes_de(&ls, pos);
            break;
        case 9:
            printf("Ingrese posicion de referencia a eliminar despues de: ");
            scanf("%d", &pos);
            eliminar_despues_de(&ls, pos);
            break;
        case 10:
            printf("Ingrese posicion de referencia a eliminar en: ");
            scanf("%d", &pos);
            eliminar_en(&ls, pos);
            break;
        case 11:
            printf("Valor al inicio: %d\n", obtener_el_primero(ls));
            break;
        case 12:
            printf("Valor al final: %d\n", obtener_el_ultimo(ls));
            break;
        case 13:
            printf("Ingrese posicion de referencia a obtener antes de: ");
            scanf("%d", &pos);
            printf("Valor antes de: %d\n", obtener_antes_de(ls, pos));
            break;
        case 14:
            printf("Ingrese posicion de referencia a obtener despues de: ");
            scanf("%d", &pos);
            printf("Valor despues de: %d\n", obtener_despues_de(ls, pos));
            break;
        case 15:
            printf("Ingrese posicion de referencia a obtener en: ");
            scanf("%d", &pos);
            printf("Valor en: %d\n", obtener_en(ls, pos));
            break;
        case 16:
            puts("Borrando la lista...");
            borrar(&ls);
            break;
        case 17:
            mostrar(ls);
            break;
        case 18:
            printf("Esta vacia? %s\n", esta_vacia(ls) ? "yes" : "no");
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

void insertar_al_inicio(Lse *ls, int val)
{
    Nodo *nd = crear_nodo(val);

    if (!esta_vacia(*ls))
        nd->sig = ls->cab;

    ls->cab = nd;
}

void insertar_al_final(Lse *ls, int val)
{
    Nodo *nd = crear_nodo(val);

    if (esta_vacia(*ls))
        ls->cab = nd;
    else
    {
        Nodo *aux = ls->cab;

        while (aux->sig != NULL)
            aux = aux->sig;

        aux->sig = nd;
    }
}

bool insertar_antes_de(Lse *ls, int val, int pos)
{
    if (!esta_vacia(*ls) && pos >= 0)
    {
        Nodo *aux = ls->cab;
        Nodo *_aux = NULL;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            _aux = aux;
            aux = aux->sig;
            i++;
        }

        if (i == pos)
        {
            Nodo *nd = crear_nodo(val);
            nd->sig = aux;

            if (aux == ls->cab)
                ls->cab = nd;
            else
                _aux->sig = nd;

            return true;
        }
    }

    return false;
}

bool insertar_despues_de(Lse *ls, int val, int pos)
{
    if (!esta_vacia(*ls) && pos >= 0)
    {
        Nodo *aux = ls->cab;
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
                nd->sig = aux->sig;

            aux->sig = nd;

            return true;
        }
    }

    return false;
}

bool reemplazar_en(Lse *ls, int val, int pos)
{
    if (!esta_vacia(*ls) && pos >= 0)
    {
        Nodo *aux = ls->cab;
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

bool eliminar_el_primero(Lse *ls)
{
    if (!esta_vacia(*ls))
    {
        Nodo *aux = ls->cab;
        ls->cab = ls->cab->sig;
        free(aux);

        return true;
    }
    else
        return false;
}

bool eliminar_el_ultimo(Lse *ls)
{
    if (!esta_vacia(*ls))
    {
        Nodo *aux = ls->cab;
        Nodo *_aux;

        while (aux->sig != NULL)
        {
            _aux = aux;
            aux = aux->sig;
        }

        if (aux == ls->cab)
            ls->cab = NULL;
        else
            _aux->sig = NULL;

        free(aux);

        return true;
    }
    else
        return false;
}

bool eliminar_antes_de(Lse *ls, int pos)
{
    if (!esta_vacia(*ls) && pos >= 0)
    {
        Nodo *aux = ls->cab;
        Nodo *_aux = NULL;
        Nodo *__aux = NULL;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            __aux = _aux;
            _aux = aux;
            aux = aux->sig;
            i++;
        }

        if (i == pos)
            if (aux != ls->cab)
            {
                if (_aux == ls->cab)
                    ls->cab = aux;
                else
                    __aux->sig = aux;

                free(_aux);

                return true;
            }
    }

    return false;
}

bool eliminar_despues_de(Lse *ls, int pos)
{
    if (!esta_vacia(*ls) && pos >= 0)
    {
        Nodo *aux = ls->cab;
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
                free(aux_);

                return true;
            }
    }

    return false;
}

bool eliminar_en(Lse *ls, int pos)
{
    if (!esta_vacia(*ls) && pos >= 0)
    {
        Nodo *aux = ls->cab;
        Nodo *_aux = NULL;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            _aux = aux;
            aux = aux->sig;
            i++;
        }

        if (i == pos)
        {
            if (aux == ls->cab)
                ls->cab = ls->cab->sig;
            else
                _aux->sig = aux->sig;

            free(aux);

            return true;
        }
    }

    return false;
}

int obtener_el_primero(Lse ls)
{
    if (!esta_vacia(ls))
        return ls.cab->val;
    else
        return -9999;
}

int obtener_el_ultimo(Lse ls)
{
    if (!esta_vacia(ls))
    {
        Nodo *aux = ls.cab;

        while (aux->sig != NULL)
            aux = aux->sig;

        return aux->val;
    }
    else
        return -9999;
}

int obtener_antes_de(Lse ls, int pos)
{
    if (!esta_vacia(ls) && pos >= 0)
    {
        Nodo *aux = ls.cab;
        Nodo *_aux = NULL;
        int i = 0;

        while (aux->sig != NULL && i != pos)
        {
            _aux = aux;
            aux = aux->sig;
            i++;
        }

        if (i == pos)
            if (aux != ls.cab)
                return _aux->val;
    }

    return -9999;
}

int obtener_despues_de(Lse ls, int pos)
{
    if (!esta_vacia(ls) && pos >= 0)
    {
        Nodo *aux = ls.cab;
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

int obtener_en(Lse ls, int pos)
{
    if (!esta_vacia(ls) && pos >= 0)
    {
        Nodo *aux = ls.cab;
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

bool borrar(Lse *ls)
{
    if (!esta_vacia(*ls))
    {
        Nodo *aux;

        do
        {
            aux = ls->cab;
            ls->cab = ls->cab->sig;
            free(aux);
        }
        while (ls->cab != NULL);

        return true;
    }
    else
        return false;
}

void mostrar(Lse ls)
{
    printf("Lse [ ");

    if (!esta_vacia(ls))
    {
        Nodo *aux = ls.cab;

        do
        {
            printf("%d ", aux->val);
            aux = aux->sig;
        }
        while (aux != NULL);
    }

    puts("]");
}

bool esta_vacia(Lse ls)
{
    return ls.cab == NULL;
}
