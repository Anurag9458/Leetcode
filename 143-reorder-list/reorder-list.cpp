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

    ListNode *reverse(ListNode *head){
        ListNode *curr=head,*prev=NULL,*next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next){
            return;
        }
        ListNode *slow=head,*fast=head,*prev;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=NULL;
        fast=slow;
        slow=head;
        fast=reverse(fast);

        while(slow && fast){
            ListNode *temp=NULL,*temp1=NULL;
            
            if(slow->next){
                temp=slow->next;
            }
            if(fast->next){
                temp1=fast->next;
            }
            slow->next=fast;
            fast->next=temp;
            prev=slow;
            fast=temp1;
            slow=temp;
        }

        if(fast){
            slow=head;
        while(slow->next){
            slow=slow->next;
        }
        slow->next=fast;
        }
      
    }
};