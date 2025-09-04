#include<stdio.h>
#include<string.h>

struct Node {

    char idioma[500];
    char traducao[500];
    Node *next;

    Node(char _idioma[500], char _traducao[500]) {
        strcpy(idioma, _idioma); // idioma = _idioma
        strcpy(traducao, _traducao); // traducao = _traducao
        next = NULL;
    }

    Node() {
        strcpy(idioma, "");
        strcpy(traducao, "");
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

    void pushBack(char idioma[500], char traducao[500]) {

        Node *n = new Node(idioma, traducao);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

    }

    void search(char idioma[500]) {

        Node *aux = start;

        while (aux != NULL) {
            if (strcmp(aux->idioma, idioma) == 0) {
                printf("%s\n", aux->traducao);
                return;
            }
            aux = aux->next;
        }

    }

};

int main() {

    List l;
    int n;
    scanf("%d%*c", &n);
    for (int i = 0; i < n; i++) {
        char traducao[500];
        char idioma[500];
        scanf("%[^\n]%*c", idioma);
        scanf("%[^\n]%*c", traducao);
        l.pushBack(idioma, traducao);
    }

    int m;
    scanf("%d%*c", &m);
    for (int i = 0; i < m; i++) {
       char idioma[500];
       char nome[500];
       scanf("%[^\n]%*c", nome);
       scanf("%[^\n]%*c", idioma);

       printf("%s\n", nome);
       l.search(idioma);
       printf("\n");
    }

    return 0;
}


