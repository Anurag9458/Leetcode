class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lo=0,hi=n-1;
        int maxi=0;
        while(lo<hi){
            if(height[lo]<height[hi]){
                maxi=max((hi-lo)*height[lo],maxi);
                lo++;
            }else{
                maxi=max((hi-lo)*height[hi],maxi);
                hi--;
            }
        }

        return maxi;
    }
};