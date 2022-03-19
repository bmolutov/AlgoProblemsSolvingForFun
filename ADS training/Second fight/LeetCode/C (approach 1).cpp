link: https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        ListNode * cur = head;
        while (cur != NULL) {
            if (cur -> val == INT_MAX) {
                return true;
            }
            cur -> val = INT_MAX;
            cur = cur -> next;
        }
        return false;
    }
};