#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int findLength(Node* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

Node* findMergePoint(Node* head1, Node* head2) {
    int len1 = findLength(head1);
    int len2 = findLength(head2);

    int lengthDiff = abs(len1 - len2);

    if (len1 > len2) {
        while (lengthDiff > 0) {
            head1 = head1->next;
            lengthDiff--;
        }
    } else {
        while (lengthDiff > 0) {
            head2 = head2->next;
            lengthDiff--;
        }
    }

    while (head1 != nullptr && head2 != nullptr) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

int main() {
    Node* commonNode = new Node{8, nullptr};
    
    Node* head1 = new Node{4, new Node{6, commonNode}};
    Node* head2 = new Node{5, new Node{7, commonNode}};

    cout << "Linked List 1: 4 -> 6 -> 8" << endl;
    cout << "Linked List 2: 5 -> 7 -> 8" << endl;

    Node* mergePoint = findMergePoint(head1, head2);

    if (mergePoint != nullptr) {
        cout << "Merge Point Value: " << mergePoint->data << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    delete head1;
    delete head2;
    return 0;
}
