class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        //multiset<int>st;
        //map<int,int>mp;
        vector<int>v(1e6+7,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //st.insert(abs(nums[i]-nums[j]));
                //mp[abs(nums[i]-nums[j])]++;
                v[abs(nums[i]-nums[j])]++;
            }
        }

        for(int i=0;i<=1e6;i++){
            if(v[i]){
                k-=v[i];
            }
            if(k<=0){
                return i;
            }
        }

        return -1;
    }
};