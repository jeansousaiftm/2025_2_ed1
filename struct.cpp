#include<stdio.h>

struct Pessoa {

    char nome[100];
    char endereco[100];

    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("Endereco: %s\n", endereco);
    }

    void ler() {
        printf("Digite o nome: ");
        scanf("%[^\n]%*c", nome);
        printf("Digite o endereco: ");
        scanf("%[^\n]%*c", endereco);
    }

};

int main() {

    Pessoa p;

    p.ler();
    p.imprimir();

    //char teste[100];

    //scanf("%[^\n]%*c", teste);
    //printf("%s\n", teste);

    return 0;
}
