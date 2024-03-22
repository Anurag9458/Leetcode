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

    ListNode* reverse(ListNode *head){
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head,*prev;
       if(!head->next){
        return 1;
       }
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        fast=slow;
        prev->next=NULL;
        // cout<<fast->val<<" "<<slow->val<<endl;
        // slow->next=NULL;
        fast=reverse(fast);
        slow=head;


        while(slow && fast){
            if(slow->val!=fast->val){
                return 0;
            }
            slow=slow->next;
            fast=fast->next;
        }

        return 1;

    }
};