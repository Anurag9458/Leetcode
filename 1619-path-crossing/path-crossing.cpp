class Solution {
public:
    bool isPathCrossing(string path) {
        int a=0,b=0;
        map<pair<int,int>,int>mp;
        mp[{0,0}]++;
        for(char c:path){
            if(c=='N'){
                a++;
                if(mp.count({a,b}))return 1;
                mp[{a,b}]++;
            }
            else if(c=='E'){
                b++;
                if(mp.count({a,b}))return 1;
                mp[{a,b}]++;
            }
            else if(c=='W'){
                b--;
                if(mp.count({a,b}))return 1;
                mp[{a,b}]++;
            }
            else{
                a--;
                if(mp.count({a,b}))return 1;
                mp[{a,b}]++;
            }
        }

        for(auto it:mp){
            cout<<it.first.first<<" "<<it.first.second<<endl;
        }

        return 0;
    }
};