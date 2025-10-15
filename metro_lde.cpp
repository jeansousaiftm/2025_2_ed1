#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct Node {

    char value[100];
    Node *next, *prev;

    Node(char _value[100]) {
        strcpy(value, _value);
        next = NULL;
        prev = NULL;
    }

    Node() {
        next = NULL;
        prev = NULL;
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

    void pushBack(char value[100]) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        n->prev = end;
        end->next = n;
        end = n;

    }

    void findPath(char e1[100], char e2[100]) {

        Node *aux = start;
        int p1 = 0, p2 = 0;
        bool achou1 = false, achou2 = false;
        while (aux != NULL) {
            if (strcmp(aux->value, e1) == 0) {
                achou1 = true;
            }
            if (strcmp(aux->value, e2) == 0) {
                achou2 = true;
            }
            if (!achou1) p1++;
            if (!achou2) p2++;
            aux = aux->next;
            if (achou1 && achou2) break;
        }


        if (p1 < p2) {
            printf("direita %d\n", (p2 - p1));
        } else if (p1 > p2) {
            printf("esquerda %d\n", (p1 - p2));
        }

    }

};

int main() {

    List l;
    l.pushBack("PALMEIRAS BARRA FUNDA");
    l.pushBack("MARECHAL DEODORO");
    l.pushBack("SANTA CECILIA");
    l.pushBack("REPUBLICA");
    l.pushBack("ANHANGABAU");
    l.pushBack("SE");
    l.pushBack("PEDRO II");
    l.pushBack("BRAS");
    l.pushBack("BRESSER MOOCA");
    l.pushBack("BELEM");
    l.pushBack("TATUAPE");
    l.pushBack("CARRAO");
    l.pushBack("PENHA");
    l.pushBack("VILA MATILDE");
    l.pushBack("GUILHERMINA ESPERANCA");
    l.pushBack("PATRIARCA");
    l.pushBack("ARTUR ALVIM");
    l.pushBack("CORINTHIANS ITAQUERA");

    char e1[100], e2[100];
    scanf("%[^\n]%*c", e1);
    scanf("%[^\n]%*c", e2);

    l.findPath(e1, e2);

    return 0;
}

