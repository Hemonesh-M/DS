#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL; // Empty list.
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    Node* head = new Node{3, NULL};
    head->next = new Node{7, NULL};
    head->next->next = new Node{9, NULL};
    head->next->next->next = new Node{11, NULL};
    head->next->next->next->next = new Node{13, NULL};

    cout << "Linked List: 3 -> 7 -> 9 -> 11 -> 13" << endl;

    Node* middle = findMiddle(head);

    if (middle != NULL) {
        cout << "Middle Element: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    // Clean up memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
