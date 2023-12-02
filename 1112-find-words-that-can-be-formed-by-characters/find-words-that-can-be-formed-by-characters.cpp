class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        for(char c:chars)
        mp[c]++;

        int ans=0;

        for(int i=0;i<words.size();i++){
            map<char,int>mp1;
            for(char c:words[i]){
                mp1[c]++;
            }
            int flag=0;
            for(auto it:mp1){
                if(mp[it.first]<it.second)
                flag=1;
            }
            if(!flag)
            ans+=words[i].size();
        }

        return ans;
    }
};