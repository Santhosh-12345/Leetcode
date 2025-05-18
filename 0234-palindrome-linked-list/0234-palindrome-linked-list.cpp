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
    ListNode* reversell(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* newH=reversell(head->next);

        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newH;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reversell(slow);
        ListNode* temp1=head;
        ListNode* temp2=newHead;
        while(temp2)
        {
            if(temp1->val!=temp2->val)
            {
                reversell(newHead);
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        reversell(newHead);
        return true;
    }
};