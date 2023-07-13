class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n,0);
        if(nums == temp)return {{0,0,0}};
        int i = 0 ,j = n-1;
        sort(nums.begin(),end(nums));
        set<vector<int>>st;

        for(int a = 0; a < n-2; a++){
            i = a+1; j = n-1;
        while(i < j){
    if(nums[i]+nums[j]+nums[a] == 0  && j!=a){
                multiset<int>s{nums[i],nums[j],nums[a]};
                vector<int>temp(begin(s),end(s));
                // sort(begin(temp),end(temp));
                st.insert(temp);
                i++;
                j--;
            }
            else if(nums[i]+nums[j]+nums[a] < 0){
                i++;
            }
            else{
                j--;
            }
        }
        }
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};