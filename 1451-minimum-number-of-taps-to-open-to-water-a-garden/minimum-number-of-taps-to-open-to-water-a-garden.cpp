class Solution {
public:
    int minTaps(int n, vector<int>& gallery) {
         vector<int>v(n+1,0);
        
        for(int i=0;i<gallery.size();i++){
            int start=max(0,i-gallery[i]);
            int end=min(n,i+gallery[i]);
            
            v[start]=max(v[start],end);
            
        }
        
        int maxi=0,curr=0,ans=0;
        
        for(int i=0;i<=n;i++){
            
            if(i>maxi){
                return -1;
            }
            
            if(i>curr){
                ans++;
                curr=maxi;
            }
            maxi=max(maxi,v[i]);
        }
        
        return ans;
    }
};