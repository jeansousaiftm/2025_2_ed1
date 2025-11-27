#include<stdio.h>
#include<string.h>

struct Node {

    char value;
    Node *next;

    Node(char _value) {
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

    void push(char value) {
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

    void insertFace() {
        if (empty()) {
            push('F');
            push('A');
            push('C');
            push('E');
        }
    }

    int compare(char a, char b, char c, char d) {
        int pontos = 1;
        Node *aux = t;
        if (aux->value != a) pontos = 0;
        aux = aux->next;
        if (aux->value != b) pontos = 0;
        aux = aux->next;
        if (aux->value != c) pontos = 0;
        aux = aux->next;
        if (aux->value != d) pontos = 0;

        if (pontos == 1) {
            pop();
            pop();
            pop();
            pop();
        } else {
            push(a);
            push(b);
            push(c);
            push(d);
        }

        return pontos;
    }

};

int main() {

    int n;
    char a, b, c, d;
    scanf("%d%*c", &n);
    Stack s;
    int pontos = 0;

    for (int j = 0; j < n; j++) {
        scanf("%c %c %c %c%*c", &a, &b, &c, &d);
        s.insertFace();
        pontos += s.compare(a, b, c, d);
    }

    printf("%d\n", pontos);

    return 0;
}
