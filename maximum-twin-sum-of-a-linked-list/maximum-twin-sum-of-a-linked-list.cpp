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

    ListNode* reverse(ListNode *head)
    {
        ListNode *curr=head,*prev=NULL,*next;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

public:
    int pairSum(ListNode* head) {
        ListNode *curr=head;
        int n=0;
        while(curr)
        {
            curr=curr->next;n++;
        }
        n/=2;
        n--;
        ListNode *temp=head;
        curr=head;
        while(n--)curr=curr->next;
        temp=curr->next;
        curr->next=NULL;
        temp=reverse(temp);
        curr=head;
        int ans=0;
        while(curr)
        {
            ans=max(ans,curr->val+temp->val);
                temp=temp->next;curr=curr->next;
        }
        return ans;
    }
};