class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& grump, int m) {
        int n=cus.size();
        int i=0,j=0;
        int maxi=0;
        int temp=0;
        while(i<m){
            if(grump[i]){
                temp+=cus[i];
            }
            i++;
        }

        maxi=max(maxi,temp);

        while(i<n){
            if(grump[i])
            temp+=cus[i];
            if(grump[j])
            temp-=cus[j];
            maxi=max(maxi,temp);
            i++;
            j++;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(!grump[i]){
                ans+=cus[i];
            }
        }
        
        // cout<<maxi;
        return ans+maxi;

    }
};