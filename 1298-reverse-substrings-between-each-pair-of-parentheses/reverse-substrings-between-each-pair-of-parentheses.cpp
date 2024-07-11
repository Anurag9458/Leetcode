class Solution {
public:
    string reverseParentheses(string s) {
       string ans;

       stack<string>st;

       for(char c:s){
        
        if(c==')'){
            string temp;
            while(!st.empty() && st.top()!="("){
                temp+=st.top();
                st.pop();
            }
            reverse(begin(temp),end(temp));
            st.pop();
            st.push(temp);
        }else{
            string temp;
            temp+=c;
            st.push(temp);
        }
       }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
       reverse(begin(ans),end(ans));

        return ans;

    }
};