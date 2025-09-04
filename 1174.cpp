#include<stdio.h>

struct Node {

    double value;
    Node *next;

    Node(double _value) {
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

    void pushBack(double value) {

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

    void pushFront(double value) {

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
        int pos = 0;
        while (aux != NULL) {

            if (aux->value <= 10) {
                printf("A[%d] = %.1lf\n", pos, aux->value);
            }
            aux = aux->next;
            pos++;
        }
    }

    // complexidade tempo: O(n)
    /*int size() {
        int c = 0;
        Node *aux = start;
        while (aux != NULL) {
            c++;
            aux = aux->next;
        }
        return c;
    }*/

    // O(1)
    int size() {
        return c;
    }

};

int main() {

    List l;

    for (int i = 0; i < 100; i++) {
        double x;
        scanf("%lf", &x);
        l.pushBack(x);
    }

    l.print();

    return 0;
}


