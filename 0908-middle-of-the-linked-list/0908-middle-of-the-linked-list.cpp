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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        temp=head;
        int cnt1=0;
        while(temp)
        {
            cnt1++;
            if(cnt1==cnt/2+1)
            break;
            temp=temp->next;
        }
        return temp;

    }
};