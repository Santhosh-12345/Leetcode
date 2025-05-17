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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l=list1;
        ListNode* r=list2;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(l!=NULL && r!=NULL)
        {
            if(l->val<=r->val)
            {
                temp->next=new ListNode(l->val);
                l=l->next;
            }
            else
            {
                temp->next=new ListNode(r->val);
                r=r->next;
            }
            temp=temp->next;
        }
        while(l)
        {
            temp->next=new ListNode(l->val);
            l=l->next;
            temp=temp->next;
        }
         while(r)
        {
            temp->next=new ListNode(r->val);
            r=r->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};