#include<stdio.h>

struct Node {

    int value;
    Node *next, *prev;

    Node(int _value) {
        value = _value;
        next = NULL;
        prev = NULL;
    }

    Node() {
        next = NULL;
        prev = NULL;
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

        n->prev = end;
        end->next = n;
        end = n;

    }

    void pushFront(int value) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        start->prev = n;
        n->next = start;
        start = n;

    }

    void print() {
        Node *aux = start;
        while (aux != NULL) {
            printf("%d <-> ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }

    void printReverse() {
        Node *aux = end;
        while (aux != NULL) {
            printf("%d <-> ", aux->value);
            aux = aux->prev;
        }
        printf("\n");
    }

    // complexidade tempo: O(n)
    /*int size() {
        int c = 0;
        Node *aux = start;
        while (aux != NULL) {
            c++;
            aux = aux->next;
        }
        return c;
    }*/

    // O(1)
    int size() {
        return c;
    }

    // O(1)
    void popFront() {

        if (empty()) return;

        c--;

        if (start == end) {
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *aux = start;
        start = start->next;
        start->prev = NULL;
        delete(aux);

    }

    // O(1)
    void popBack() {

        if (empty()) return;

        c--;

        if (start == end) {
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *aux = end;
        end = end->prev;
        end->next = NULL;
        delete(aux);
    }

    // O(pos)
    /*void insert(int x, int pos) {

        if (pos <= 0) {
            pushFront(x);
            return;
        }

        if (pos >= size()){
            pushBack(x);
            return;
        }

        Node* aux = start;
        for (int i = 0; i < pos - 1; i++) {
            aux = aux->next;
        }

        Node* n = new Node(x);
        n->next = aux->next;
        aux->next = n;
        c++;

    }*/

    // O(pos)
    /*void remove(int pos) {

        if (pos <= 0) {
            popFront();
            return;
        }

        if (pos >= size() - 1) {
            popBack();
            return;
        }

        Node* aux = start;
        for (int i = 0; i < pos - 1; i++) {
            aux = aux->next;
        }

        Node* toDel = aux->next;
        aux->next = toDel->next;
        delete(toDel);
        c--;

    }*/

};

int main() {

    List l;

    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(5);
    l.pushBack(3);
    l.popFront();
    l.pushFront(8);
    l.pushBack(50);
    l.popBack();
    l.pushFront(78);
    l.pushBack(1);
    l.popBack();
    l.pushBack(75);
    l.pushFront(25);
    l.popFront();
    l.pushBack(60);
    l.popBack();
    l.pushFront(34);
    l.pushBack(80);
    l.pushBack(30);
    l.popFront();
    l.pushBack(23);
    l.popFront();
    l.popBack();
    l.pushFront(5);
    l.pushFront(66);
    l.popFront();

    l.print();
    l.printReverse();

    return 0;
}
