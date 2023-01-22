#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
/*
    Descubra quantos clientes de uma agencia
    bancaria teriam que esperar mais do que 20 
    minutos na fila do banco, contrariando a 
    legislacao.
*/
{
    int info;
    struct No* proximo;
};

struct Fila
{
    struct No* inicio;
    struct No* fim;
    int tamanho;
    
};

struct Fila* criar(){
    struct Fila* nova_fila = (struct Fila*) malloc(sizeof(struct Fila));
    if(nova_fila != NULL) {
        nova_fila->inicio = NULL;
        nova_fila->fim = NULL;
        nova_fila->tamanho = 0;
    }
    return nova_fila;
}
void enfileirar(struct Fila* f, int item) {
    assert(f != NULL);
    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    if(novo_no != NULL) {
        novo_no->info = item;
        novo_no->proximo = NULL;
        
        if(f->fim != NULL) {
            f->fim->proximo = novo_no;
        } 
        else {
            f->inicio = novo_no;
        }
        
        f->fim = novo_no;
        f->tamanho++;
    }
};

int desenfileirar(struct Fila* f) {
    assert(f != NULL);
    assert(f->inicio != NULL);
    struct No* aux = f->inicio;
    int elemento = aux->info;
    f->inicio = aux->proximo;
    
    if(f->inicio == NULL) {
        f->fim = NULL;
    }
    f->tamanho--;
    free(aux);
    return elemento;
};

bool vazia(struct Fila* f) {
    assert(f != NULL);
    return (f->inicio == NULL);
};

int tamanho(struct Fila* f) {
    assert(f != NULL);
    return f->tamanho;
}

int inicio(struct Fila* f) {
    assert(f != NULL);
    assert(f->inicio != NULL);
    return f->inicio->info;
}

void liberar(struct Fila* f) {
    assert(f != NULL);
    while(f->inicio != NULL) {
        desenfileirar(f);
    }
    free(f);
}

int calcular_clientes_em_espera_maxima(struct Fila* filaTEntrada, struct Fila* filaTAtendimento){
    int esperaTotal = 0;
    int clientesEmEsperaMaxima = 0;

    while (!vazia(filaTEntrada))
    {
        int t_entrada = desenfileirar(filaTEntrada);
        int t_atendimento = desenfileirar(filaTAtendimento);

        if(esperaTotal - t_entrada > 20){
            clientesEmEsperaMaxima += 1;
        }

        esperaTotal += t_atendimento;

        return clientesEmEsperaMaxima;
    }
    
}

int main (){
    int num_clients, t_entrada, t_atendimento, clienteEmEsperaMaxima;
    printf("Informe o numero de clientes");
    scanf("%d", &num_clients);

    struct Fila* filaTEntrada = criar();
    struct Fila* filaTAtendimento = criar();

    for(int i = 0; i<num_clients; i++){
        printf("\n Informe o tempo em que o cliente %d entrou na fila: ", i+1);
        scanf("%d", &t_entrada);
        enfileirar(filaTEntrada, t_entrada);

        printf("\n Informe o tempo de atendimento do cliente %d", i +1);
        scanf("%d", &t_atendimento);
        enfileirar(filaTAtendimento, t_atendimento);      
        printf("\n");
    }
    clienteEmEsperaMaxima = calcular_clientes_em_espera_maxima(filaTEntrada, filaTAtendimento);
    printf("\n Neste dia, %d cliente(s) esperarao mais de 20min na fila", clienteEmEsperaMaxima);
    return 0;
}