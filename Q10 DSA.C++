#include <iostream>
#include <cstring>
using namespace std;

struct Contact {
    char name[100];
    char mobile[15];  // Mobile number as string
};

struct Node {
    Contact contact;
    Node* next;
};

class ContactList {
private:
    Node* head;

public:
    ContactList() : head(nullptr) {}

    // 1) Add node at the beginning
    void addAtBeg(const char* name, const char* mobile) {
        Node* newNode = new Node;
        strncpy(newNode->contact.name, name, 100);
        strncpy(newNode->contact.mobile, mobile, 15);
        newNode->next = head;
        head = newNode;
    }

    // 2) Add node at the end
    void append(const char* name, const char* mobile) {
        Node* newNode = new Node;
        strncpy(newNode->contact.name, name, 100);
        strncpy(newNode->contact.mobile, mobile, 15);
        newNode->next = nullptr;

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
            cout << "Name: " << temp->contact.name << ", Mobile: " << temp->contact.mobile << endl;
            temp = temp->next;
        }
    }

    // 5) Display more information (address, name, mobile, next pointer)
    void displayMORE() {
        Node* temp = head;
        while (temp) {
            cout << "Address: " << temp << ", Name: " << temp->contact.name << ", Mobile: " << temp->contact.mobile << ", Next: " << temp->next << endl;
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
};

int main() {
    ContactList contacts;
    
    contacts.addAtBeg("Alice", "123-456-7890");
    contacts.append("Bob", "987-654-3210");
    contacts.addAtBeg("Charlie", "555-555-5555");
    
    cout << "Contact List: \n";
    contacts.display();
    
    cout << "\nDisplaying More Information: \n";
    contacts.displayMORE();
    
    contacts.removeFirst();
    contacts.removeLast();
    
    cout << "\nAfter Deletions, Contact List: \n";
    contacts.display();
    
    return 0;
}
