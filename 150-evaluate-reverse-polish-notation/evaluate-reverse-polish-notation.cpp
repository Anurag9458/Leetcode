class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<string>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!="+" && arr[i]!="-" && arr[i]!="*" && arr[i]!="/"){
                st.push(arr[i]);
            }else{
                string sign=arr[i];
                string a=st.top();st.pop();
                string b=st.top();st.pop();
                int temp1=stoi(a),temp2=stoi(b);
                if(arr[i]=="+"){
                    temp2+=temp1;
                }else if(arr[i]=="-"){
                    temp2-=temp1;
                }else if(arr[i]=="*"){
                    temp2*=temp1;
                }else{
                    temp2/=temp1;
                }
                a=to_string(temp2);
                st.push(a);
            }
        }

        string temp=st.top();
        st.pop();
        int ans=stoi(temp);
        return ans;
    }
};