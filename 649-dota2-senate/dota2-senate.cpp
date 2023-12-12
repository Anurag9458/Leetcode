class Solution {

    bool solve(char c,string &s,int i){
        bool check=0;

        while(true){
            if(i==0)check=1;
            if(s[i]==c){
                s.erase(begin(s)+i);
                break;
            }
            i=(i+1)%s.size();
        }

        return check;

    }

public:
    string predictPartyVictory(string s) {

        // int n=s.size();
        int rcount=count(begin(s),end(s),'R');
        int dcount=s.size()-rcount;
        int i=0;

        while(rcount && dcount){
            if(s[i]=='R'){
                if(solve('D',s,(i+1)%s.size()))i--;
                dcount--;
                
            }else{
                if(solve('R',s,(i+1)%s.size()))i--;
                rcount--;
            }
            i=(i+1)%s.size();
        }

        return rcount==0?"Dire":"Radiant";

    }
};