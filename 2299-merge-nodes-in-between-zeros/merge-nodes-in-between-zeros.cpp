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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans=new ListNode(0),*a=ans;
        ListNode *curr=head->next;

        int temp=0;
        while(curr){
            if(curr->val==0){
                curr=curr->next;
                a->next=new ListNode(temp);
                a=a->next;
                temp=0;
            }else{
                temp+=curr->val;
                curr=curr->next;
            }
        }

        return ans->next;

    }
};