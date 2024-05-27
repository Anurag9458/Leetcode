class Solution {
public:
    int specialArray(vector<int>& nums) {
     int n=nums.size();
     sort(begin(nums),end(nums));
     int maxi=*max_element(begin(nums),end(nums));
     for(int i=0;i<=maxi;i++){
        int ind=lower_bound(begin(nums),end(nums),i)-begin(nums);
        if(n-ind==i){
            return i;
        }
     }
        return -1;
    }
};