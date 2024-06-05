class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
      
     int n=words.size();
     vector<int>v(26,0);
     string temp=words[0];

     for(char c:temp){
        v[c-'a']++;
     }

     for(int i=1;i<n;i++){
        vector<int>v1(26,0);
        temp=words[i];
        for(char c:temp){
            v1[c-'a']++;
        }

        for(int j=0;j<26;j++){
            v[j]=min(v1[j],v[j]);
        }

     }    

    vector<string>ans;

    for(int i=0;i<26;i++){
        if(v[i]){
             string a;
            a.push_back('a'+i);
            while(v[i]--){
               ans.push_back(a);
            }
        }
    }

    return ans;

    }
};