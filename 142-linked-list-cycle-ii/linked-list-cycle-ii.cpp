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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *p=head;
        ListNode *q=head;
        ListNode *r=NULL;
        while(q!=0 && q->next!=0)
        {
            p=p->next;
            q=q->next->next;
            if(p == q)
            {
                int count=0;
                ListNode *start=head;
                while(start!=p)
                {
                    count++;
                    start=start->next;  
                    p=p->next;                 
                }
                cout<<"tail connects to node index "<<count;
                return start;
            }
        }
        cout<<"no cycle";
        return NULL;
    }
};