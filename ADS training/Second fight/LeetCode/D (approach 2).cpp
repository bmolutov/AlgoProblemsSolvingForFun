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
        unordered_map <ListNode*, int> mp;
        while (headA != nullptr) {
            mp[headA]++;
            headA = headA -> next;
        }
        while (headB != nullptr) {
            if (mp[headB] > 0) {
                return headB;
            }
            headB = headB -> next;
        }
        return nullptr;
    }
};