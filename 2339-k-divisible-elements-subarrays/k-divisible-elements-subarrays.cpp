class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        int count=0,ans=0;
        set<vector<int>>st;
        vector<int>temp;
        for(int i=0;i<n;i++){
            count=0;
            temp.clear();
            for(int j=i;j<n;j++){
                if(nums[j]%p==0){
                    count++;
                }
                if(count>k)break;
                temp.push_back(nums[j]);
                st.insert(temp);
                
            }
        }

        // for(auto it:st){
        //     for(int i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }

        return st.size();
    }
};