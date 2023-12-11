class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        map<int,int>mp1,mp2;
        for(int i:nums1)mp1[i]++;
        for(int i:nums2)mp2[i]++;
        set<int>temp;
        for(int i:nums1)
        if(!mp2.count(i))
        temp.insert(i);
        vector<int>v1(begin(temp),end(temp));
        ans.push_back(v1);
        temp.clear();

        for(int i:nums2)
        if(!mp1.count(i))
        temp.insert(i);
        vector<int>v(begin(temp),end(temp));
        ans.push_back(v);

        return ans;
    }
};