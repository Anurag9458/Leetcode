class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;

        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push({'(',i});
            }else if(s[i]==')'){
                if(st.empty() || st.top().first!='('){
                    st.push({')',i});
                }
                else if(st.top().first=='(')
                st.pop();
            }
        }

        vector<int>temp;

        while(!st.empty()){
            temp.push_back(st.top().second);
            st.pop();
        }

        reverse(begin(temp),end(temp));

        string ans;

        int j=0,i=0;
        for(i=0;i<n && j<temp.size();i++){
            if(i==temp[j]){
                j++;
            }else{
                ans.push_back(s[i]);
            }
        }

        while(i<n){
            ans.push_back(s[i++]);
        }


        return ans;
    }
};