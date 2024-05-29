class Solution {

string add(string &s){
    string temp=s;
    reverse(begin(s),end(s));
    int i=1;
    int flag=0;
    temp[0]='0';
    while(i<temp.size()){
        if(temp[i]=='1'){
            temp[i]='0';
        }else{
            temp[i]='1';
            break;
        }
        i++;
    }
    reverse(begin(temp),end(temp));
    return temp;
}

public:
    int numSteps(string s) {
        
        int ans=0;
        while(s.length()!=1){
            if(s.back()=='0'){
                s.pop_back();
            }
            else{
              s=add(s);
            }
           ans++;
        }
        if(s[0]=='0'){
            ans++;
        }
        return ans;
    }
};