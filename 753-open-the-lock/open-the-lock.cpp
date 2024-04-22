class Solution {

    void solve(queue<string>&q,unordered_set<string>&st,string s){

        for(int i=0;i<4;i++){
            char c=s[i];

            char in=c=='9'?'0':c+1;
            char de=c=='0'?'9':c-1;

            s[i]=in;
            if(st.find(s)==st.end()){
                st.insert(s);
                q.push(s);
            }
            s[i]=de;
            if(st.find(s)==st.end()){
                st.insert(s);
                q.push(s);
            }

            s[i]=c;

        }

    }

public:
    int openLock(vector<string>& d, string target) {
        string s="0000";
        unordered_set<string>st(begin(d),end(d));

        if(st.find(s)!=st.end()){
            return -1;
        }

        queue<string>q;

        q.push(s);

        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string temp=q.front();
                q.pop();

                if(temp==target){
                    return level;
                }

                solve(q,st,temp);

            }
            level++;
        }
        return -1;
    }
};