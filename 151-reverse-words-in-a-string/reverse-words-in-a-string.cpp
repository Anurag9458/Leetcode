class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string temp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(temp.size())
                v.push_back(temp);
                temp="";
            }
            else
            temp.push_back(s[i]);
        }
        
        if(temp.size())
        v.push_back(temp);

        reverse(begin(v),end(v));
        
        string ans;

        for(string i:v){
            ans+=(i+' ');
        }

        ans.pop_back();

        return ans;

    }
};