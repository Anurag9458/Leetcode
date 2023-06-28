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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        if(!head)return NULL;
        while(head && head->val == val){
        if(head->val == val)
        {
            ListNode *temp = curr;
            curr = curr->next;
            head = head->next;
            delete(temp);
        }}
        if(!head)
        {
            return NULL;
        }
        while(curr && curr->next)
        {
            if(curr->next->val == val)
            {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete(temp);
            }
            else if(curr->next)
            curr = curr->next;
        }
        return head;
    }
};