class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

       vector<vector<int>>ans;

        vector<int>temp,temp1;
        set<int>st;

       while(true){
           int n=nums.size();
           st.clear();
           temp.clear();
           temp1.clear();

            for(int i=0;i<n;i++){
                if(st.find(nums[i])==st.end()){
                    st.insert(nums[i]);
                    temp.push_back(nums[i]);
                }else{
                    temp1.push_back(nums[i]);
                }
            }
            
            nums=temp1;
            if(n==0){
                break;
            }

            ans.push_back(temp);
       } 
        return ans;
       
    }
};