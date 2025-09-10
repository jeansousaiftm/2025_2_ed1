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

};

int main() {

    List l;

    l.pushBack(10);
    l.pushBack(3);
    l.pushBack(5);
    l.pushBack(8);

    l.print();
    l.popBack();
    l.print();
    l.popBack();
    l.print();
    l.popBack();
    l.print();
    l.popBack();
    l.print();
    l.popBack();
    l.print();

    return 0;
}
