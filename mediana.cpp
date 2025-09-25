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
    Node *median;
    Node *end;
    int c;

    List() {
        start = NULL;
        median = NULL;
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
            median = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

        if (c % 2 == 1) median = median->next;

    }

    // O (1)
    double medianValue() {
        if (c % 2 == 0) {
            double v1 = median->value;
            double v2 = median->next->value;
            return (v1 + v2) / 2;
        } else {
            return median->value;
        }
    }

    void print() {
        Node *aux = start;
        while (aux != NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("%.2lf\n", medianValue());
    }

};

int main() {

    List l;

    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.pushBack(x);
        l.print();
    }


    return 0;
}
