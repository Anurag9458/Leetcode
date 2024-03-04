class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        int n=token.size();
        int hi=n-1,lo=0;
        int temp=0,ans=0;
        sort(begin(token),end(token));
        while(lo<=hi){
            // cout<<power<<" "<<token[lo]<<" "<<token[hi]<<endl;
            if(power>=token[lo]){
                power-=token[lo];
                lo++;
                temp++;
                ans=max(ans,temp);
            }else if(ans && power<token[lo]){
                power+=token[hi];
                hi--;
                temp--;
                
            }else{
                break;
            }
            
        }

        return ans;
    }
};