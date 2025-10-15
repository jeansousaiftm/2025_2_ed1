#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct Node {

    char value;
    Node *next, *prev;

    Node(char _value) {
        value = _value;
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
    Node *first;
    int c;

    List() {
        start = NULL;
        first = NULL;
        end = NULL;
        c = 0;
    }

    bool empty() {
        return start == NULL;
    }

    void pushBack(char value) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            first = n;
            end = n;
            return;
        }

        n->prev = end;
        end->next = n;
        end = n;

    }

    void pushFront(char value) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            first = n;
            end = n;
            return;
        }

        start->prev = n;
        n->next = start;
        start = n;

    }

    void printUpperCase() {
        Node *aux = first;
        while (aux != NULL) {
            if (isupper(aux->value)) {
                printf("%c ", aux->value);
            }
            aux = aux->prev;
        }
    }

    void printLowerCase() {
        Node *aux = first;
        while (aux != NULL) {
            if (islower(aux->value)) {
                printf("%c ", aux->value);
            }
            aux = aux->next;
        }
    }

};

int main() {

    List l;
    char tmp[101];
    scanf("%s", tmp);

    for (int i = 0; i < strlen(tmp); i++) {
        if (isupper(tmp[i])) {
            l.pushFront(tmp[i]);
        } else {
            l.pushBack(tmp[i]);
        }
    }

    l.printUpperCase();
    l.printLowerCase();
    printf("\n");

    return 0;
}
