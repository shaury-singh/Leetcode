#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int carry = 0;
    while (l1!=nullptr || l2!=nullptr || carry){
        int sum = carry;
        if (l1!=nullptr){
            sum += l1->val;
            l1 = l1->next;
        } 
        if (l2!=nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        current->next = new ListNode(sum%10);
        current = current->next;
        carry = sum/10;
    }
    ListNode* result = dummy->next;
    delete dummy;
    return result;
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
    h1->next = n2;
    n2->next = n3;
    ListNode* h2 = new ListNode(5);
    ListNode* N2 = new ListNode(6);
    ListNode* N3 = new ListNode(4);
    h2->next = N2;
    N2->next = N3;
    ListNode* result = addTwoNumbers(h1,h2);
    printList(result);
    return 0;
}