class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v(26,0);
        for(char c:p){
            v[c-'a']++;
        }
        // for(int i:v){
        //     cout<<i<<" ";
        // }
        vector<int>v1(26,0);
        int i=0,j=0;
        int n=s.size(),m=p.size();
        if(m>n){
            return {};
        }

        while(j<m){
            v1[s[j]-'a']++;
            j++;
        }
        // cout<<endl;
        // for(int i:v1){
        //     cout<<i<<" ";
        // }

        vector<int>ans;

        if(v==v1){
            ans.push_back(i);
        }

        while(j<n){
            v1[s[i]-'a']--;
            v1[s[j]-'a']++;
            i++;
            j++;
            if(v1==v){
                ans.push_back(i);
            }
        }

        return ans;

    }
};