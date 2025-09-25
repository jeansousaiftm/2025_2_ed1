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


    // O(n)
    int biblioteca(int p) {
        if (p <= 0) return 0;
        int l = 1;
        Node *aux = start;
        while (aux != NULL) {
            if (p <= aux->value) {
                return l;
            }
            p -= aux->value;
            aux = aux->next;
            l++;
        }
        return 0;
    }

};

int main() {

    List l;
    int n, x, p;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.pushBack(x);
    }

    scanf("%d", &p);

    printf("%d\n", l.biblioteca(p));

    return 0;
}
