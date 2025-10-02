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
    Node *maior;
    Node *menor;
    Node *end;
    int c;

    List() {
        start = NULL;
        maior = NULL;
        menor = NULL;
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
            menor = n;
            maior = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

        if (n->value > maior->value) maior = n;
        if (n->value < menor->value) menor = n;

    }

    void print() {
        printf("%d %d\n", menor->value, maior->value);
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
