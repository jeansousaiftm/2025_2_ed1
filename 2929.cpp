#include<stdio.h>
#include<string.h>

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

    Stack s, m;

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char p[10];
        scanf("%s", p);
        if (strcmp(p, "PUSH") == 0) {
            int x;
            scanf("%d", &x);
            s.push(x);
            if (m.empty() || x <= m.top()) {
                m.push(x);
            }
        }
        if (strcmp(p, "MIN") == 0) {
            if (m.empty()) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", m.top());
            }
        }
        if (strcmp(p, "POP") == 0) {
            if (m.empty()) {
                printf("EMPTY\n");
            } else {
                if (m.top() == s.top()) {
                    m.pop();
                }
                s.pop();
            }
        }
    }

    return 0;
}
