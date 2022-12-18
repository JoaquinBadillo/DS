//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode* temp;
        struct ListNode* current;
        struct ListNode* prev = nullptr;
        for (temp = head; temp != nullptr; temp = temp -> next) {
            current = new ListNode(temp -> val, prev);
            prev = current;
        }
        return current;
    }
};