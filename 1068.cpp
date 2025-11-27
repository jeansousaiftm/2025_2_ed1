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

};

int main() {

    char p[10010];

    while(scanf("%s", p) != EOF) {
        Stack s;
        int c = 1;
        for (int i = 0; i < strlen(p); i++) {
            if (p[i] == '(') {
                s.push('(');
            }
            if (p[i] == ')') {
                if (s.empty()) c = 0;
                s.pop();
            }
        }
        if (c == 1 && s.empty()) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }





    return 0;
}
