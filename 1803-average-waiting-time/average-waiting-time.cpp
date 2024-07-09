class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& arr) {
        double ans=0;
        double sum=0,temp=0;

        int n=arr.size();
        
        sum+=arr[0][0]+arr[0][1];
        temp=arr[0][1];

        for(int i=1;i<n;i++){
           
            if(sum<arr[i][0]){
                sum=arr[i][0]+arr[i][1];
            }else{
                 sum+=arr[i][1];
            }
            temp+=(sum-arr[i][0]);
            cout<<temp<<" ";
        }

        ans=(double)temp/n;

        return ans;

    }
};