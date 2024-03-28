class Solution {
public:
    int minOperations(int k) {
        if(k<=1){
            return 0;
        }

        int a=sqrt(k);
        int ans=0;
        if(a*a!=k){
            a++;
        }
        // cout<<a<<" "; 
        ans+=a-1;
        int sum=a;
        while(sum<k){
            sum+=a;
            ans++;
        }

         return ans;   
    }
};