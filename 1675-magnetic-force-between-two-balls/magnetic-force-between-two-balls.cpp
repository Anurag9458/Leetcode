class Solution {

    bool check(int mid,vector<int>&arr,int m){
        int count=1,prev=arr[0];
        // cout<<mid<<" ";
        for(int i=1;i<arr.size() && count<m ;i++){
            if(arr[i]-prev>=mid){
                count++;
                prev=arr[i];
            }
        }
        // cout<<endl;

        return count==m;
    }

public:
    int maxDistance(vector<int>& arr, int m) {
        sort(begin(arr),end(arr));
        int n=arr.size();
        int lo=1,hi=arr[n-1]+1;

        int ans=0;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,arr,m)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ans;

    }
};