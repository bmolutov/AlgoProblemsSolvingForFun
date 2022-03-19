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
        int len = 0;
        ListNode * temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp -> next;
        }
        if (len == 1) {
            return true;
        }
        int len2 = len / 2;
        ListNode * ref1 = head;
        ListNode * ref2 = head;
        while (len2 > 0) {
            len2--;
            ref2 = ref2 -> next;
        }
        if (len % 2 == 1) {
            ref2 = ref2 -> next;
        }
        // cutting the reference
        ListNode * trial = nullptr;
        if (len % 2 == 1) {
            trial = head;
            while (trial -> next -> next != ref2) {
                trial = trial -> next;
            }
        }
        else if (len % 2 == 0) {
            trial = head;
            while (trial -> next != ref2) {
                trial = trial -> next;
            }
        }
        trial -> next = nullptr;
        // reversing
        ListNode * prev = nullptr;
        ListNode * cur = ref1;
        ListNode * next = nullptr;
        while (cur != nullptr) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        // final
        while (prev != nullptr && ref2 != nullptr) {
            if (prev -> val != ref2 -> val) {
                return false;
            }
            prev = prev -> next;
            ref2 = ref2 -> next;
        }
        return true;
    }
};