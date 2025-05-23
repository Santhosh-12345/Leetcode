/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            temp->next->random=temp->random? temp->random->next : NULL;
            temp=temp->next->next;
        }
        Node* dummy=new Node(0);
        Node* res=dummy;
        temp=head;
        while(temp!=NULL)
        {
            res->next=temp->next;
            res=res->next;

            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};