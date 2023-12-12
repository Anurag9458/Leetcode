class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        string ans,temp;

        stack<int>st1;
        stack<char>st2;

        int i=0;

        while(i<n){
        
        int count=0;

        if(s[i]>='0' && s[i]<='9'){
            while(s[i]>='0' && s[i]<='9'){
                count=count*10+(s[i]-'0');
                i++;
            }
            i--;
            st1.push(count);
            // cout<<count<<" ";
        }else if(s[i]==']'){
            count=0;
            temp="";

            if(!st1.empty()){
                count=st1.top();
                cout<<count<<endl;
                st1.pop();
            }

            while(!st2.empty() && st2.top()!='['){
                temp=st2.top()+temp;
                cout<<temp<<" ";
                st2.pop();
            }

            if(!st2.empty() && st2.top()=='['){
                st2.pop();
            }

            int j=0;
            ans="";
            while(j<count){
                ans+=temp;
                j++;
            }

            j=0;

            while(j<ans.size()){
                st2.push(ans[j]);
                j++;
            }
            // cout<<ans<<" ";
            ans="";
            temp="";

        }else if(s[i]=='['){
            cout<<i<<" ";
            if(s[i-1]>='0' && s[i-1]<='9'){st2.push(s[i]);cout<<i<<" ";}
            else{
                st2.push(s[i]);
                st1.push(1);
            }

        }else{
            st2.push(s[i]);
            // cout<<st2.top()<<" ";
        }

        i++;

        }

        while(!st2.empty()){
            ans+=st2.top();
            st2.pop();
        }
        
        reverse(begin(ans),end(ans));
        return ans;
    }
};