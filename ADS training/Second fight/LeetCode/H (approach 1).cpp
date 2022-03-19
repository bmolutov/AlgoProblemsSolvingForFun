link: https://leetcode.com/problems/delete-node-in-a-linked-list/
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
    void deleteNode(ListNode* node) {
        while (true) {
            node -> val = node -> next -> val;
            if (node -> next -> next == nullptr) {
                break;
            }
            else {
                node = node -> next;
            }
        }
        node -> next = nullptr;
    }
};