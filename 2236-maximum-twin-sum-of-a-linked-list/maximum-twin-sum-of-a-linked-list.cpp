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
    int pairSum(ListNode* head) {
        
        ListNode *slow=head,*fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *temp=reverse(slow->next);
        slow->next=NULL;

        int ans=0;
        slow=head;
        fast=temp;
        while(slow && fast){
            ans=max(ans,slow->val+fast->val);
            slow=slow->next;
            fast=fast->next;
        }
    return ans;
    }
};