class Solution {

    int solve(int a,string s){
        int n=s.size();
        vector<int>v(26);
        for(int i=0;i<a;i++)v[s[i]-'a']++;
        
        for(int i=a;i<n;i+=a){
            vector<int>v1(26);
            for(int j=i;j<i+a;j++)v1[s[j]-'a']++;

            if(v1!=v){
                return 0;
            }
        }

        return 1;



    }

public:
    int minAnagramLength(string s) {
        int n=s.size();

        int ans=n;

        for(int i=1;i*i<=n;i++){
            if(n%i==0){
            if(solve(i,s))ans=min(ans,i);
            if(solve(n/i,s))ans=min(ans,(n/i));
            }
        }

        return ans;

    }
};