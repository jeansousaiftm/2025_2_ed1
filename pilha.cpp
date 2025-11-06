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

struct Stack {

    Node *t;

    Stack() {
        t = NULL;
    }

    bool empty() {
        return t == NULL;
    }

    void push(int value) {
        Node *n = new Node(value);

        if (empty()) {
            t = n;
            return;
        }

        n->next = t;
        t = n;
    }

    void pop() {

        if (empty()) {
            return;
        }

        Node *aux = t;
        t = t->next;
        delete(aux);
    }

    int top() {
        return t->value;
    }

};

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        printf("%d\n", s.top());
        s.pop();
    }

    return 0;
}
