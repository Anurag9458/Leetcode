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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head->next)return NULL;
        if(head->next && !head->next->next){
            ListNode *temp=head->next;
            head->next=NULL;
            delete(temp);
            return head;
        }
        ListNode *curr=head,*prev=NULL,*next=head;
        
        while(next && next->next){
            prev=curr;
            curr=curr->next;
            next=next->next->next;
        }
        
        ListNode *del=curr,*temp=curr->next;
        prev->next=temp;
        delete(del);

        return head;

    }
};