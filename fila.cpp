#include<stdio.h>

struct Node {

    int value;
    Node *next;

    Node(int _value) {
        value = _value;
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

    void pushBack(int value) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

    }

    void pushFront(int value) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        n->next = start;
        start = n;

    }

    void print() {
        //printf("start: %d end: %d\n", start, end);
        Node *aux = start;
        while (aux != NULL) {
            //printf("[%d] %d [%d] -> ", aux, aux->value, aux->next);
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }


    // O(n)
    void insertPriority(int x) {

        if (x < 65 || empty()) {
            pushBack(x);
            return;
        }

        if (start->value < 65) {
            pushFront(x);
            return;
        }

        if (end->value >= 65) {
            pushBack(x);
            return;
        }

        Node* aux = start;
        while (aux->next->value >= 65) {
            aux = aux->next;
        }

        Node* n = new Node(x);
        n->next = aux->next;
        aux->next = n;
        c++;

    }

};

int main() {

    List l;

    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.pushBack(x);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.insertPriority(x);
    }

    l.print();

    return 0;
}
