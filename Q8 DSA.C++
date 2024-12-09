#include <iostream>
#include <cstring> // for strncpy
using namespace std;

struct Node {
    char name[100];  // Store friend's name
    Node* next;      // Pointer to the next node
};

class LinkedList {
private:
    Node* head;  // Head of the linked list

public:
    // Constructor to initialize the list
    LinkedList() : head(nullptr) {}

    // 1) Add a node at the beginning
    void addAtBeg(const char* name) {
        Node* newNode = new Node;        // Create a new node
        strncpy(newNode->name, name, sizeof(newNode->name));  // Copy the name into the node
        newNode->next = head;            // Set the next pointer to the current head
        head = newNode;                  // Move the head to the new node
    }

    // 2) Add a node at the end
    void append(const char* name) {
        Node* newNode = new Node;        // Create a new node
        strncpy(newNode->name, name, sizeof(newNode->name));  // Copy the name into the node
        newNode->next = nullptr;         // The next pointer is null for the last node

        if (!head) {
            head = newNode;              // If the list is empty, the new node becomes the head
            return;
        }

        Node* temp = head;
        while (temp->next) {             // Traverse the list to find the last node
            temp = temp->next;
        }
        temp->next = newNode;            // Set the last node's next pointer to the new node
    }

    // 3) Add a node at a specific position
    void addAtPOS(const char* name, int pos) {
        if (pos == 1) {
            addAtBeg(name);  // If position is 1, just add at the beginning
            return;
        }

        Node* newNode = new Node;        // Create a new node
        strncpy(newNode->name, name, sizeof(newNode->name));  // Copy the name into the node
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;      // Set new node's next pointer to the current node's next
        temp->next = newNode;            // Set the current node's next pointer to the new node
    }

    // 4) Get the length of the list
    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // 5) Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 6) Display more details (address of node, name, and next pointer)
    void displayMORE() {
        Node* temp = head;
        while (temp) {
            cout << "Address: " << temp << ", Name: " << temp->name << ", Next: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // 7) Remove the first node
    void removeFirst() {
        if (!head) return;  // If the list is empty, nothing to remove
        Node* temp = head;
        head = head->next;   // Move the head to the next node
        delete temp;         // Delete the old head
    }

    // 8) Remove the last node
    void removeLast() {
        if (!head) return;  // If the list is empty, nothing to remove
        if (!head->next) {   // If there's only one node in the list
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next) {  // Traverse to the second-to-last node
            temp = temp->next;
        }

        delete temp->next;  // Delete the last node
        temp->next = nullptr; // Set the second-to-last node's next pointer to null
    }

    // 9) Remove a node at a specific position
    void removePOS(int pos) {
        if (pos == 1) {
            removeFirst();  // If position is 1, just remove the first node
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;  // Skip the node to be deleted
        delete toDelete;                // Delete the node
    }
};

int main() {
    LinkedList friends;
    
    // Add some friends to the list
    friends.addAtBeg("Alice");
    friends.append("Bob");
    friends.addAtPOS("Charlie", 2);
    
    // Display the list of friends
    cout << "Friends List: ";
    friends.display();
    
    // Display additional details (address, name, next pointer)
    cout << "\nDisplaying More Information:\n";
    friends.displayMORE();
    
    // Remove the first node
    friends.removeFirst();
    cout << "\nAfter removing the first node, Friends List: ";
    friends.display();
    
    // Remove the last node
    friends.removeLast();
    cout << "\nAfter removing the last node, Friends List: ";
    friends.display();
    
    // Remove a node at a specific position
    friends.removePOS(1);
    cout << "\nAfter removing node at position 1, Friends List: ";
    friends.display();
    
    // Display the length of the list
    cout << "\nLength of the list: " << friends.getLength() << endl;
    
    return 0;
}
