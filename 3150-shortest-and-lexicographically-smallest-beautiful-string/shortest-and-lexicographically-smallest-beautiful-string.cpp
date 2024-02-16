class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n=s.size();

        int i=0,j=0;

        string temp;
        vector<string>v;
        int count=0;

        while(j<n){
            if(s[j]=='1'){
                count++;
            }
            temp.push_back(s[j]);
            j++;
            if(count==k){
                break;
            }
            
        }
        // cout<<temp<<" ";
        if(count<k){
            return "";
        }

        v.push_back(temp);
        // cout<<j<<" ";
        while(j<n){
            if(count==k){
                while(count==k){
                    if(s[i]=='1'){
                        count--;
                    }
                    i++;
                }
            }

            if(s[j]=='1'){
                count++;
            }
            if(count==k){
                v.push_back(s.substr(i,j-i+1));
            }
            j++;

        }
        
       

        for(string &s:v){
            if(s[0]=='0'){
                int i=0;
                while(s[i]=='0'){
                    i++;
                }
                s=s.substr(i);
            }
        }

        string ans=v[0];

        for(string s:v){
            if(ans.size()>s.size()){
                ans=s;
            }else if(ans.size()==s.size()){
                ans=min(s,ans);
            }
        }

        return ans;
    }
};