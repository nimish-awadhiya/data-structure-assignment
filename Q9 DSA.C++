#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class OddEvenList {
private:
    Node* head;

public:
    OddEvenList() : head(nullptr) {}

    // 1) Add node at the beginning
    void addAtBeg(int x) {
        Node* newNode = new Node{ x, head };
        head = newNode;
    }

    // 2) Add node at the end
    void append(int x) {
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

    // 3) Get the length of the list
    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // 4) Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 5) Display more information (address, data, next pointer)
    void displayMORE() {
        Node* temp = head;
        while (temp) {
            cout << "Address: " << temp << ", Data: " << temp->data << ", Next: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // 6) Remove the first node
    void removeFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 7) Remove the last node
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

    // Special method to reorder the list (odd first, then even)
    void reorderList() {
        Node* oddHead = nullptr, * evenHead = nullptr;
        Node* oddTail = nullptr, * evenTail = nullptr;
        Node* temp = head;

        while (temp) {
            if (temp->data % 2 != 0) {
                if (!oddHead) oddHead = oddTail = temp;
                else {
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
            } else {
                if (!evenHead) evenHead = evenTail = temp;
                else {
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            }
            temp = temp->next;
        }

        // Combine odd and even lists
        if (oddTail) oddTail->next = evenHead;
        if (evenTail) evenTail->next = nullptr;
        head = oddHead;
    }
};

int main() {
    OddEvenList list;
    
    list.addAtBeg(3);
    list.append(8);
    list.addAtBeg(1);
    list.append(6);
    list.addAtBeg(5);
    
    cout << "Before Reordering, List: ";
    list.display();
    
    // Reorder to put odd numbers first, then even numbers
    list.reorderList();
    
    cout << "After Reordering (Odd-Even List): ";
    list.display();
    
    return 0;
}
