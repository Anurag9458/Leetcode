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

    void solve(ListNode *head,int sum){
    int temp=0;
    ListNode *curr=head,*prev;

    while(curr && temp!=sum){
        temp+=curr->val;
        
        prev=curr;
        curr=curr->next;
    }
   
    
    temp=0;

    while(curr){
        temp+=curr->val;
        curr=curr->next;
        if(temp==0){
            break;
        }
    }
    
    if(temp==0)
    prev->next=curr;
    return;
}


public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
    map<int,int>mp;
    int sum=0;
    ListNode *curr=head;
    while(curr){
        sum+=curr->val;
       
        if(sum==0){
            head=curr->next;
            mp.clear();
        }
        else if(mp.count(sum)){
            solve(head,sum);
            
        }else{
            mp[sum]++;
        }
        curr=curr->next;
    }
    return head;

    }
};