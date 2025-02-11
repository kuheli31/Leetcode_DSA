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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *p = head;
        int count=0;
        //Traversing to find number of nodes
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
        //to reuse pointer p
        p = head;
        //Checking if count is even or odd
        if(count%2 == 0)
        {
            int midEven=(count + 1)/2;
            for(int i=0 ; i<midEven ; i++)
            {
                p=p->next;
            }
            //Printing nodes after middle node
            ListNode *list = p;
            int q;
            while(list!=0)
            {
                q=list->val;
                list = list->next;
            }
        }
        else
        {
            int midOdd=(count + 2)/2;
            for(int i=0 ; i<midOdd-1 ; i++)
            {
                p=p->next;
            }
            //Printing nodes after middle node
            ListNode *list = p;
            int q;
            while(list!=0)
            {
                q=list->val;
                list = list->next;
            }
        }
        return p;
    }
};