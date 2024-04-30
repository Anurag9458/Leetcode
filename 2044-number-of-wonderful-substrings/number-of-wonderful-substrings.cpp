#define ll long long

class Solution {
public:
    long long wonderfulSubstrings(string s) {
        long long ans=0;
        int n=s.size();
        
        map<ll,ll>mp;
        int curr=0;
        mp[0]=1;
        
        for(char c:s){
            int shift=c-'a';
            curr^=(1<<shift);

            ans+=mp[curr];

            for(char i='a';i<='j';i++){
                shift=i-'a';

                ll check=(curr^(1<<shift));
                ans+=mp[check];
            }

            mp[curr]++;
        }
       return ans;
    }
};