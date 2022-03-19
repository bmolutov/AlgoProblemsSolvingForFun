link: https://leetcode.com/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * a = headA;
        ListNode * b = headB;
        if (a == nullptr || b == nullptr) {
            return nullptr;
        }
        while (true) {
            if (a == b) {
                return a;
            }
            a = a -> next;
            b = b -> next;
            if (a == b) {
                return a;
            }
            if (a == nullptr) {
                a = headB;
            }
            if (b == nullptr) {
                b = headA;
            }
        }
    }
};