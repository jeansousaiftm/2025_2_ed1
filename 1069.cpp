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

    int n;
    char p[10010];
    scanf("%d", &n);

    for (int j = 0; j < n; j++) {
        scanf("%s", p);
        Stack s;
        int c = 0;
        for (int i = 0; i < strlen(p); i++) {
            if (p[i] == '<') {
                s.push('<');
            }
            if (p[i] == '>') {
                if (!s.empty()) c++;
                s.pop();
            }
        }
        printf("%d\n", c);
    }





    return 0;
}
