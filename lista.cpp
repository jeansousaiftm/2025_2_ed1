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

    void pushFront(int value) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        n->next = start;
        start = n;

    }

    void print() {
        //printf("start: %d end: %d\n", start, end);
        Node *aux = start;
        while (aux != NULL) {
            //printf("[%d] %d [%d] -> ", aux, aux->value, aux->next);
            printf("%d -> ", aux->value);
            aux = aux->next;
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
        delete(aux);

    }

    // O(n)
    void popBack() {

        if (empty()) return;

        c--;

        if (start == end) {
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *newEnd = start;
        while (newEnd->next != end) {
            newEnd = newEnd->next;
        }

        delete(end);
        end = newEnd;
        end->next = NULL;

    }

    // O(x * n)
    void atividade1(int x) {

        for (int i = 0; i < x; i++) {
            popBack();
        }

    }

    // O(1)
    void atividade2() {

        if (size() <= 1) return;
        if (size() == 2) {
            popBack();
            return;
        }

        Node* second = start->next;
        start->next = second->next;
        delete(second);
        c--;

    }

    // O(1)
    void atividade3() {
        pushBack(size());
    }

    // O(n)
    void atividade4(int n) {
        for (int i = 1; i <= n; i++) {
            pushBack(i);
        }
    }

    //O(n)
    void atividade5(int x) {

        if (size() <= 1) return;

        Node* aux = start;
        while (aux->next != end) {
            aux = aux->next;
        }

        Node* n = new Node(x);
        n->next = end;
        aux->next = n;
        c++;

    }

    // O(pos)
    void insert(int x, int pos) {

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

    }

    // O(n)
    void atividade5_nova(int x) {

        if (size() <= 1) return;
        insert(x, size() - 1);

    }

    // O(pos)
    void remove(int pos) {

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

    }

    // O(1)
    void atividade2_nova() {
        if (size() <= 1) return;
        remove(1);
    }

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

    l.insert(4, 4);
    l.insert(100, 8);

    l.remove(6);
    l.remove(3);

    l.print();

    return 0;
}
