class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        int ans=0;
        sort(begin(p),end(p));
        int n=p.size();

        int i=0,j=n-1;
        int w=0;
        while(i<=j){
          if(p[i]+p[j]<=l){
            ans++;i++;j--;
          }else{
            ans++;j--;
          }
        }

        return ans;

    }
};