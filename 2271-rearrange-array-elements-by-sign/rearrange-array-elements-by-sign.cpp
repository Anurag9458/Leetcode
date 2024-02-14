class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int i:nums){
            if(i>=0)
            pos.push_back(i);
            else
            neg.push_back(i);
        }
        vector<int>ans;
        int i=0,j=0,n=pos.size(),m=neg.size();
        while(i<n && j<m){
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }

        while(i<n){
            ans.push_back(pos[i++]);
        }

        while(j<m){
            ans.push_back(pos[j++]);
        }

        return ans;
    }
};