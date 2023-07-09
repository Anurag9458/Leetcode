class Solution {

    void solve(vector<int> &temp, int n){
        while(n){
            temp.push_back(n%10);
            n/=10;
        }
        reverse(begin(temp), end(temp));
    }

public:
    int divisorSubstrings(int num, int k) {
        vector<int> temp;
        int ans = 0;
        solve(temp, num);
        int i = 0, j = 0;
        int n= temp.size();
        if(k == 1){
            for(int i : temp){
                if(i && !(num % i))ans++;
            }
            return ans;
        }
        int sum = 0;
        while(j < k && j < n){
            sum = sum * 10 + temp[j++];
        }
        cout<<sum<<" ";
        int mod = pow(10,(k - 1)); 
        cout<<mod<<" ";
        if(sum && !(num % sum))ans++;
        while(j < n){
            sum = sum % mod;
            cout<<sum<<" ";
            sum = sum * 10 + temp[j++];
            // if(sum < mod)continue;
            cout<<sum<<" ";
            if( sum && !(num % sum))ans++;
        }
        return ans;
    }
};