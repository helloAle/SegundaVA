#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct Queue {

    int tamanho, first, last, quant_Itens;
	// capacidade da fila,  primeiro, ultimo, quantidade de itens na fila;
    float *data;
	// numeros inseridos

};

void criarQueue( struct Queue *f, int c ) { 

    f->tamanho = c;
    f->data = (float*) malloc (f->tamanho * sizeof(float));
    f->first = 0;
    f->last = -1;
    f->quant_Itens = 0; 

}

void inserir(struct Queue *f, int v) {

    if(f->last == f->tamanho-1)
        f->last = -1;

    f->last++;
    f->data[f->last] = v; // Incrementa last e insere
    f->quant_Itens++; // Mais um item inserido

}

int remover( struct Queue *f ) { // pega o item do come√ßo da fila

    int temp = f->data[f->first++]; // pega o valor e incrementa o first

    if(f->first == f->tamanho)
        f->first = 0;

    f->quant_Itens--;  // Retirado um item.
    return temp;

}

int estaVazia( struct Queue *f ) { // retorna verdadeiro se a fila esta vazia.

    return (f->quant_Itens==0);

}

int estaCheia( struct Queue *f ) { // retorna verdadeiro se a fila est√° cheia.

    return (f->quant_Itens == f->tamanho);
}

void mostrarQueue(struct Queue *f){

    int cont, i;

    for ( cont=0, i= f->first; cont < f->quant_Itens; cont++){

        printf("%0.2f\t",f->data[i++]);

        if (i == f->tamanho)
            i=0;

    }
    printf("\n\n");

}

main () {
	setlocale(LC_ALL, "Portuguese");
    int opcao, capa;
    float valor;
    struct Queue umaQueue;

    // CriaÁ„o a Fila.
    printf("\ntamanho da Fila ");
    scanf("%d",&capa);
    criarQueue(&umaQueue, capa);

    // Apresentando o menu.
    while( 1 ){
        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpÁ„o? ");
        scanf("%d", &opcao);

        switch(opcao){

            case 0: exit(0);

            case 1: // o case 1 mostra se a fila est√° cheia, se n√£o, insere um novo elemento.
                if (estaCheia(&umaQueue)){

                    printf("\n Fila Cheia!!!\n\n");

                }
                else {

                    printf("\n Valor do elemento a ser inserido? ");
                    scanf("%f", &valor);
                    inserir(&umaQueue,valor);

                }

                break;

            case 2: // o case 2 mostra se a fila esta°  vazia ou remove o elemento.
                if (estaVazia(&umaQueue)){

                    printf("\n Fila vazia!!!\n\n");

                }
                else {

                    valor = remover(&umaQueue);
                    printf("\n%0.2f removido com sucesso\n\n", valor) ; 

                }
                break;

                case 3: // o case 3 mostra se a fila est√° vazia, se n√£o, mostra o conteudo.
                    if (estaVazia(&umaQueue)){

                        printf("\n Fila vazia!!!\n\n");

                    }
                    else {

                        printf("\n Conteudo da fila => ");
                        mostrarQueue(&umaQueue);

                    }
                    break;

                default:
                    printf("\n Op√ß√£o Invalida\n\n");

        }
    }
}
