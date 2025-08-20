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

    List() {
        start = NULL;
        end = NULL;
    }

    bool empty() {
        return start == NULL;
    }

    void pushBack(int value) {

        Node *n = new Node(value);

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

    }

};

int main() {



    return 0;
}
