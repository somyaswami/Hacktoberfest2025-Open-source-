/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
leetcode_problem MERGE TWO SORTED LIST
* ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting point of the new merged list.
        // This simplifies the logic, especially handling the head of the list.
        ListNode dummy(0);
        
        // 'tail' will always point to the last node of the merged list (initially the dummy node).
        ListNode* tail = &dummy;
        
        // Iterate while both lists have nodes.
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                // The smaller node is in list1. Append it to the merged list.
                tail->next = list1;
                list1 = list1->next; // Move list1 pointer forward
            } else {
                // The smaller node is in list2. Append it to the merged list.
                tail->next = list2;
                list2 = list2->next; // Move list2 pointer forward
            }
            
            // Move the tail pointer to the newly appended node.
            tail = tail->next;
        }
        
        // After the loop, at least one list is exhausted. 
        // Append the remaining nodes of the non-empty list to the tail.
        if (list1 != nullptr) {
            tail->next = list1;
        } else if (list2 != nullptr) {
            tail->next = list2;
        }
        
        // The merged list starts at the node after the dummy node.
        return dummy.next;
    }
};
