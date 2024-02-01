class Solution {
    
    bool solve(vector<int>temp,int k){
        bool flag=0;
        if(temp[1]-temp[0]>k)flag=1;
        if(temp[2]-temp[1]>k)flag=1;
        if(temp[2]-temp[0]>k)flag=1;
        return flag;
    }
    
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
            int n = nums.size();
            sort(begin(nums),end(nums));
            vector<vector<int>>ans;
            
            vector<int>temp;
            for(int i=0;i<n;i++){
                temp.push_back(nums[i]);
                // cout<<temp.size()<<" ";
                if(temp.size()==3 && solve(temp,k)){
                     ans.clear();
                    return ans;
                }
                if(temp.size()==3){
                   ans.push_back(temp);
                    temp.clear();
                }
            }
        
        return ans;
    }
};