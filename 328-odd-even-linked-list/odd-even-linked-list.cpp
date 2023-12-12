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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next || !head->next->next)return head;
        ListNode *curr=head,*next=head->next,*temp=head->next;

        while(curr->next && next->next){
            curr->next=next->next;
            curr=curr->next;
            next->next=curr->next;
            next=next->next;
        }
            curr->next=temp;
        return head;

    }
};