using ll=long long;
class Solution {
    
    int check(vector<int>&arr,int mid,int k){
        int count=0;
        int buc=0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid){
                count++;
            }else{
                count=0;
            }

            if(count==k){
                buc++;
                count=0;
            }
        }
        return buc;
    }


public:
    int minDays(vector<int>& arr, int m, int k) {

        int n=arr.size();
       
        int lo=0,hi=*max_element(begin(arr),end(arr));

        int ans=-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(arr,mid,k)>=m){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;
    }
};