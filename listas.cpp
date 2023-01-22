#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct No {
    int info;
    struct No* proximo;
};
struct Lista {
    struct No* inicio;
    int tamanho;
};
struct Lista* criar(){
    struct Lista* nova_lista = (struct Lista*) malloc(sizeof(struct Lista));
    if(nova_lista != NULL){
        nova_lista->inicio = NULL;
        nova_lista->tamanho = 0;
    }
    return nova_lista;
}
bool verificar_se_lista_vazia(struct Lista* li){
    assert(li != NULL);// verifica o resultado de uma expressao logica passada por parametro para ela
    if(li->inicio == NULL || li->tamanho == 0){
        return true;
    }
    else {
        return false;
    }
}
void inserir_in_list(struct Lista* li, int posicao, int item){
    assert(li != NULL);
    assert(posicao >= 0 && posicao <= li->tamanho);
    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    novo_no->info = item;
    if(posicao == 0){
        novo_no->proximo = li->inicio;
        li->inicio = novo_no;
    }
    else {
        struct No* aux = li->inicio;
        for(int i = 0; i< posicao - 1; i++){
            aux = aux->proximo;// ponteiro auxiliar
        }
        novo_no->proximo = aux->proximo;
        aux->proximo = novo_no;
    }
    li->tamanho++;
}
void imprimir_lista(struct Lista* li){
    assert(li != NULL);
    printf("\nLista: ");
    struct No* aux = li->inicio;
    for(int i = 0; i < li->tamanho; i++){
        printf("%d", aux->info);
        aux = aux->proximo;
    }
}
int tamanho(struct Lista* li){
    assert(li != NULL);
    return li->tamanho;
}
int obter_item(struct Lista* li, int posicao){
    assert(li != NULL);
    assert(posicao >= 0 && posicao < li->tamanho);
    struct No* aux = li->inicio;
    for(int i=0; i < posicao; i++){
        aux = aux->proximo;
    }
    return aux->info;
}
int remover_item(struct Lista* li, int posicao){
    assert(verificar_se_lista_vazia(li) === false);
    assert(posicao>= 0 && posicao < li->tamanho);
    struct No* ant = NULL;// ponteiro auxiliar 1
    struct No* aux = li->inicio;// ponteiro auxiliar 2
    for(int i = 0; i < posicao; i++){
        ant = aux;
        aux = aux->proximo;
    }
    if(ant === NULL){
        li->inicio = aux->proximo;
    }
    else {
        ant->proximo = aux->proximo;
    }
    int elemento = aux->info;
    li->tamanho--;
    free(aux); // desloca a memoria
    return elemento;

}

void liberar_item(struct Lista* li){
    while (verificar_se_lista_vazia(li) == false)
    {
        remover_item(li, 0);
    }
    free(li);
    
}
int main(){
    struct Lista* minha_lista = criar();
    /*if(verificar_se_lista_vazia(minha_lista) == true){
        printf("\n OK, lista Vazia!");
    }
    else {
        printf("\n Ops! algo deu errado!");
    }*/
    inserir_in_list(minha_lista, 0, 5);
    inserir_in_list(minha_lista, 0, 3);
    inserir_in_list(minha_lista, 2, 6);
    inserir_in_list(minha_lista, 1, 0);
    inserir_in_list(minha_lista, 4, 7);
    inserir_in_list(minha_lista, 1, 2);
    inserir_in_list(minha_lista, 5, 6);
    inserir_in_list(minha_lista, 3, 4);
    imprimir_lista(minha_lista);
    printf("\n Tamanho da Lista: %d", tamanho(minha_lista));
    return 0;
}