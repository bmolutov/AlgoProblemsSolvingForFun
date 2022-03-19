link: https://leetcode.com/problems/palindrome-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = head;
        // reversing the right side
        ListNode * prev = nullptr;
        ListNode * cur = slow;
        ListNode * next = nullptr;
        while (cur != nullptr) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        slow = prev;
        while (slow != nullptr) {
            if (slow -> val != fast -> val) {
                return false;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
    }
};