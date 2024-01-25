#define ll long long int

class Solution {

    ll mod=1e9+7;

    ll solve(ll x,ll y){
        if(y==0){
            return 1;
        }
        ll temp=solve(x,y/2);
        temp=(temp*temp)%mod;
        if(y%2){
            temp=(temp*(x%mod))%mod;
        }
        return temp%mod;
    }

public:
    int minNonZeroProduct(int p) {
        ll maxi=1ll<<p;
        maxi=maxi-1;
        return maxi%mod*solve(maxi-1,(maxi)/2)%mod;
    }
};