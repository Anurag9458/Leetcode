class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count=0,prev=0,ans=0;

        for(auto it:bank){
            count=0;
            for(char i:it){
                if(i=='1')count++;
            }
            ans+=prev*count;
            if(count)prev=count;
        }
        return ans;
    }
};