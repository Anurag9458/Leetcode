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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp1=list1,*curr=list1,*temp2=list1;
        a--;
        b++;
        while(a--){
            temp1=temp1->next;
        }
        while(b--){
            temp2=temp2->next;
        }
        // cout<<temp1->val<<" "<<temp2->val<<endl;
        temp1->next=NULL;
        temp1->next=list2;

        while(temp1->next){
            temp1=temp1->next;
        }
        temp1->next=temp2;

        return list1;

    }
};