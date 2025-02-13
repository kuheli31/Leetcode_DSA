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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // Edge case: empty or single-node list

        ListNode* odd = head;  
        ListNode* even = head->next;  
        ListNode* evenHead = even; // Save even head for reconnection

        while (even && even->next) { 
            odd->next = even->next;  // Connect odd nodes
            odd = odd->next; 

            even->next = odd->next;  // Connect even nodes
            even = even->next;
        }

        odd->next = evenHead; // Append even list after odd list

        return head;
    }
};