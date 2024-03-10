class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        map<int,int>mp;
        for(int i:nums1){
            mp[i]++;
        }

        for(int i:nums2){
            if(mp.count(i)){
                st.insert(i);
            }
        }
        vector<int>temp(begin(st),end(st));
        return temp;
    }
};