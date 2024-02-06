class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>q;

        if(a>0)q.push({a,'a'});
        if(b>0)q.push({b,'b'});
        if(c>0)q.push({c,'c'});

        string ans;

        pair<int,char>prev={0,'#'};

        while(!q.empty()){
            auto it=q.top();
            q.pop();

            if(prev.first>0)q.push(prev);

            if(it.first<prev.first){
                ans+=it.second;
                it.first-=1;
            }else{
                ans+=it.second;
                if(it.first>1)ans+=it.second;
                it.first-=2;
            }
            prev=it;

        }

        return ans;
    }
};