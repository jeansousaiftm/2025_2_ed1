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

struct Queue {

    Node *start;
    Node *end;

    Queue() {
        start = NULL;
        end = NULL;
    }

    bool empty() {
        return start == NULL;
    }

    void enqueue(int value) {

        Node *n = new Node(value);

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

    }

    void enqueueOrdered(int value) {

        Node *n = new Node(value);

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        if (value >= start->value) {
            n->next = start;
            start = n;
            return;
        }

        if (value <= end->value) {
            end->next = n;
            end = n;
            return;
        }

        Node *aux = start;

        while (aux->next->value > value) {
            aux = aux->next;
        }
        n->next = aux->next;
        aux->next = n;

    }

    void dequeue() {

        if (empty()) return;

        if (start == end) {
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *aux = start;
        start = start->next;
        delete(aux);

    }

    int front() {
        return start->value;
    }

};

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        Queue q, qo;
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            q.enqueue(x);
            qo.enqueueOrdered(x);
        }
        int c = 0;
        while (!q.empty()) {
            if (q.front() == qo.front()) {
                c++;
            }
            q.dequeue();
            qo.dequeue();
        }
        printf("%d\n", c);
    }


    return 0;
}
