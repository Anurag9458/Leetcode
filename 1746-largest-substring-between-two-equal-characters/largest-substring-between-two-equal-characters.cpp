class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxi=-1;
        map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp.count(s[i])){
                maxi=max(maxi,i-mp[s[i]]-1);
            }else{
                mp[s[i]]=i;
            }
        }
        return maxi;
    }
};