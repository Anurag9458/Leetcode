class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),end(arr));
        int temp=arr[1]-arr[0];
        for(int i=1;i<arr.size();i++)if(arr[i]-arr[i-1]!=temp)return 0;
        return 1;
    }
};