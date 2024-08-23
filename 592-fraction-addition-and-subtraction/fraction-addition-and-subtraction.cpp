class Solution {
public:
    string fractionAddition(string s) {
        int nu=0,d=1;   

        int i=0;
        int n=s.size();
        while(i<n){
            int currn=0,currd=0;
            bool neg=s[i]=='-';

            if(s[i]=='+' || s[i]=='-'){
                i++;
            }

            while(i<n && isdigit(s[i])){
                int val=s[i]-'0';
                currn=currn*10+val;
                i++;
            }

            i++;

            if(neg){
                currn*=-1;
            }

            while(i<n && isdigit(s[i])){
                currd=currd*10+(s[i]-'0');
                i++;
            }

            nu=nu*currd + currn*d;
            d=d*currd;


        }
        int gcd=abs(__gcd(nu,d));
        nu/=gcd;
        d/=gcd;
        return to_string(nu)+"/"+to_string(d);
    }
};