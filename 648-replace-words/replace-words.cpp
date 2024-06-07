class Solution {
public:
    string replaceWords(vector<string>& dictionary, string se) {
        map<string,int>mp;
        for(string s:dictionary){
            mp[s]++;
        }

        string ans;

        int n=se.size();
        vector<string>v;
        string temp;
        for(int i=0;i<n;i++){
            if(temp.size() && se[i]==' '){
                v.push_back(temp);
                temp="";
            }else{
                temp.push_back(se[i]);
            }
        }

        v.push_back(temp);
        vector<string>v1;
        for(auto it:v){
            int m=it.size();
            string s;
            for(int i=0;i<m;i++){
                if(s.size() && mp.count(s)){
                    v1.push_back(s);
                    break;
                }else{
                    s.push_back(it[i]);
                }
            }
            if(s.size()==m){
                v1.push_back(s);
            }
        }

        for(auto it:v1){
            ans+=it;
            ans+=" ";
        }
        ans.pop_back();
        return ans;

    }
};