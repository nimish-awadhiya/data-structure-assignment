#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addAtBeg(char x) {
        Node* newNode = new Node{ x, head };
        head = newNode;
    }

    void append(char x) {
        Node* newNode = new Node{ x, nullptr };
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtPOS(char x, int pos) {
        if (pos == 1) {
            addAtBeg(x);
            return;
        }
        Node* newNode = new Node{ x, nullptr };
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (!temp) return; // Position out of bounds
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayMORE() {
        Node* temp = head;
        while (temp) {
            cout << "Address: " << temp << ", Value: " << temp->data << ", Next: " << temp->next << endl;
            temp = temp->next;
        }
    }

    void removeFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void removePOS(int pos) {
        if (pos == 1) {
            removeFirst();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (!temp) return; // Position out of bounds
        }
        Node* toDelete = temp->next;
        if (toDelete) {
            temp->next = toDelete->next;
            delete toDelete;
        }
    }
};

int main() {
    LinkedList list;
    list.addAtBeg('A');
    list.append('B');
    list.addAtPOS('C', 2);
    list.display();
    list.displayMORE();
    list.removeFirst();
    list.removeLast();
    list.removePOS(1);
    list.display();

    return 0;
}
