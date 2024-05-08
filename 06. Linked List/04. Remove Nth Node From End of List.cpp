// Reference: https://leetcode.com/problems/remove-nth-node-from-end-of-list/



// Given the head of a linked list, remove the nth node from the end of the list and return 
// its head.

 

// Example 1:
// ==========
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// ==========
// Input: head = [1], n = 1
// Output: []

// Example 3:
// ==========
// Input: head = [1,2], n = 1
// Output: [1]
 


// Constraints:
// ============
// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
 

// Follow up: Could you do this in one pass?





class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = NULL, *cur = head, *nth = head;
        while (n--)
            nth = nth->next;
        while (nth != NULL) {
            prev = cur;
            cur = cur->next;
            nth = nth->next;
        }

        if (cur->next == NULL && prev == NULL) {
            head = NULL;
        } else if (cur->next == NULL) {
            prev->next = NULL;
        } else {
            cur->val = cur->next->val;
            cur->next = cur->next->next;
        }
        return head;
    }
};

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
