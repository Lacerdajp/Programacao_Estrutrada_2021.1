#include <stdio.h>

struct lista // cria a struct lista
{
    int val;            // cria a variavel valor onde sera armazenado o valor do elemento da lista
    struct lista *ant;  // cria o alemento antecessor
    struct lista *prox; // cria o proximo elemento
};
typedef struct lista Lista; // define o nome da struct lista como Lista
Lista *new_lst()
{                // cria a função de nova lista que retorna um valor do tipo lista
    return NULL; // retorna nulo
}
Lista *insert_lst(Lista *lst, int val)
{                                                // cria uma função parainserir valores na lista, onde recebe como parametro uma variavel Lista e uma variavel in, e sera retornado uma Lista
    Lista *new = (Lista *)malloc(sizeof(Lista)); // cria um novo elemento do tipo que será alocada na memoria
    new->val = val;                              // o valor int passado por parametro é armazenado no valor do elemento
    new->ant = NULL;                             // o elemento anterior armazena nulo
    new->prox = lst;                             // armazena a lst no proximo elemento
    if (lst != NULL)                             // verifica se lst é nula
    {
        lst->ant = new; // o anterior a lst passada no parametro  é o novo elemento
    }
    return new; // retorna a lista com o novo elemento
}
Lista *print_lst(Lista *lst)
{                // Cria uma função para imprimir no terminal e recebe como parametro um elemento da lista
    Lista *pont; // Cria uma variavel  do tipo lista chamadqa pont
    for (pont = lst; pont != NULL; pont = pont->prox)
    {
        // iguala a variavel ao elemento recebido, depois cria um loop ate que seja igual a nulo, e ao fim incrementa para mudar o ponteiro

        printf("valor: %d\n", pont->val); // imprime o valor do elemento pont
    }
}
Lista *remove_lst(Lista *lst, int val) // a função remove a lista e retorna uma nova, recebe uma lista e um valor para ser retirado.
{
    Lista *p; // cria uma variavel do tipo lista
    for (p = lst; p != NULL; p = p->prox)
    {
        // igula a variavel ao elemento lista passado por parametro, depois cria um loop até que p seja nulo, enquanto nao for ira incrementar para o proximo elemento da lista
        if (p->val == val) // verifica se valor do elemento for igual ao valor passado no paramentro
        {
            if (lst == p) // verifica se p é o primeiro elemento
            {
                lst = p->prox; // a lista pulara o primeiro elemento e sera igual ao prox
            }
            else // caso não seja
            {
                p->ant->prox = p->prox; // o proximo elemento do elemento anterior a p se tornará o proximo elemento de p
            }
            if (p->prox != NULL) // verifica se não é o ultimo
            {
                p->prox->ant = p->ant; // o elemento anterior do proximo elemento de p se torna o anterior de p
            }
            break; // quebra para o final do loop
        }
    }
    free(p);    // libera p
    return lst; // retorna lista
}

int main()
{
    Lista *lst;                   // cria a variavel do tipo lista
    lst = new_lst();              // cria a lista
    lst = insert_lst(lst, 60);    // insere o valor no elemento
    lst = insert_lst(lst, 50);    // insere valor no elemento
    lst = insert_lst(lst, 20);    // insere valor no elemento
    lst = insert_lst(lst, 60);    // insere valor no elemento
    lst = insert_lst(lst, 30);    // insere valor no elemento
    lst = insert_lst(lst, 90);    // insere valor no elemento
    printf("Lista completa: \n"); // informa A lista completa
    print_lst(lst);               // imprime a lista

    lst = remove_lst(lst, 50);         // remove todos os elementos que contem o valor
    printf("Lista com as removes:\n"); // informa que é a lista com os removes
    print_lst(lst);                    // imprime a lista nova
    free(lst);                         // libera a lista
    return 0;                          // retorna 0 para finalizar
}
