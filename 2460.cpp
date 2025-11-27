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
    int r[100001];
    int p;

    Queue() {
        start = NULL;
        end = NULL;
        for (int i = 0; i < 100001; i++) {
            r[i] = 0;
        }
        p = 0;
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

    void remove(int value) {
        r[value] = 1;
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

    void front() {
        if (r[start->value] == 0) {
            if (p == 1) printf(" ");
            printf("%d", start->value);
            p = 1;
        }
    }

};

int main() {

    int n, m;
    Queue q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        q.enqueue(x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        q.remove(x);
    }

    while (!q.empty()) {
        q.front();
        q.dequeue();
    }
    printf("\n");

    return 0;
}
