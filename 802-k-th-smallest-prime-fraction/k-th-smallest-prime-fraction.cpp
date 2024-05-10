class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,vector<int>>>v;

        int n=arr.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                float a=(float)arr[i]/arr[j];
                // cout<<a<<" ";
                v.push_back({a,{arr[i],arr[j]}});
            }
        }

        sort(begin(v),end(v));


        return v[k-1].second;

    }
};