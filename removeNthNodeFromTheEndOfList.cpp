#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int countNodes(ListNode* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    // cout << "Count is: " << count << endl;
    return count;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = countNodes(head);
    ListNode* curr = head;
    ListNode* prev = new ListNode(0);
    for (int i = 0; i < size; i++) {
        if (i == size - n - 1) {
            prev = curr;
        }
        if (i == size - n) {
            if (curr->next != nullptr) {
                if (i == 0){
                    head = head -> next;
                }
                prev->next = curr->next;
            } else if (curr->next == nullptr) {
                if (size == 1){
                    return NULL;
                }
                prev->next = nullptr;
            }
        }
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head){
    while (head!=nullptr){
        cout << head->val << " --> ";
        head = head -> next;
    }
    cout << "NULL";
}

int main(){
    ListNode* h1 = new ListNode(2);
    ListNode* n2 = new ListNode(4);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(6);
    // ListNode* n6 = new ListNode(4);
    h1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    // n5->next = n6;
    printList(h1);
    cout << endl;
    ListNode* head = removeNthFromEnd(h1,2);
    printList(head); 
    return 0;
}