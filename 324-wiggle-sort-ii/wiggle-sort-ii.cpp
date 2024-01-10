class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        
        multiset<int>st;
        for(int i:nums)st.insert(i);
        vector<int>temp(begin(st),end(st));
        for(int i=n-1,j=0,k=i/2+1;i>=0;i--){
            nums[i]=temp[i&1 ? k++:j++];
        }
    }
};