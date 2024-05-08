// Reference: https://leetcode.com/problems/merge-two-sorted-lists/



// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the 
// nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:
// ==========
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// ==========
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// ==========
// Input: list1 = [], list2 = [0]
// Output: [0]
 


// Constraints:
// ============
// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.





class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list = new ListNode();
        ListNode* itr = list;
        while (list1 != NULL || list2 != NULL) {
            int val1 = (list1 == NULL) ? INT_MAX : list1->val;
            int val2 = (list2 == NULL) ? INT_MAX : list2->val;
            if (val1 <= val2) {
                itr->next = list1;
                list1 = list1->next;
            } else {
                itr->next = list2;
                list2 = list2->next;
            }
            itr = itr->next;
        }
        return list->next;
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
