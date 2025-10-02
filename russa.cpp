#include<stdio.h>
#include<string.h>

struct Node {

    int value;
    char nome[100];
    Node *next;

    Node(int _value, char _nome[100]) {
        value = _value;
        strcpy(nome, _nome);
        next = NULL;
    }

    Node() {
        next = NULL;
    }

};

struct List {

    Node *start;
    Node *end;
    int c;

    List() {
        start = NULL;
        end = NULL;
        c = 0;
    }

    bool empty() {
        return start == NULL;
    }

    void pushBack(int value, char nome[100]) {

        Node *n = new Node(value, nome);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

    }

    void print(int alturaLimite) {
        Node *aux = start;
        int c = 0;
        while (aux != NULL) {
            if (aux->value >= alturaLimite) {
                printf("%s\n", aux->nome);
                c++;
            }
            aux = aux->next;
        }
        if (c == 0) {
            printf("Lista Vazia\n");
        }
    }



};

int main() {

    List l;

    int n, a;
    scanf("%d%*c", &n);
    for (int i = 0; i < n; i++) {
        char nome[100];
        int altura;
        scanf("%s %d%*c", nome, &altura);
        l.pushBack(altura, nome);
    }
    scanf("%d", &a);
    l.print(a);

    return 0;
}
