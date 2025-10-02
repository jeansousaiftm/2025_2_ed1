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
    int soma;

    List() {
        start = NULL;
        end = NULL;
        c = 0;
        soma = 0;
    }

    bool empty() {
        return start == NULL;
    }

    void pushBack(int value) {

        Node *n = new Node(value);
        c++;
        soma += value;

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
        soma += value;

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

    // O(1)
    void popFront() {

        if (empty()) return;

        c--;

        if (start == end) {
            soma = 0;
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *aux = start;
        start = start->next;
        soma -= aux->value;
        delete(aux);

    }

    // O(n)
    void popBack() {

        if (empty()) return;

        c--;

        if (start == end) {
            soma = 0;
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *newEnd = start;
        while (newEnd->next != end) {
            newEnd = newEnd->next;
        }

        soma -= end->value;
        delete(end);
        end = newEnd;
        end->next = NULL;

    }

    double media() {
        if (c == 0) {
            return 0;
        }
        return (double) soma / c;
    }
};

int main() {

    List l;

    int n, o, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &o, &x);
        switch(o) {
        case 1:
            l.pushFront(x);
            break;
        case 2:
            l.pushBack(x);
            break;
        case 3:
            l.popFront();
            break;
        case 4:
            l.popBack();
            break;
        };
        printf("%.3lf\n", l.media());
    }

    return 0;
}
