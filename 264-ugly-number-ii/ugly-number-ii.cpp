class Solution {
public:
    int nthUglyNumber(int n) {
        using ll=long long;
        set<ll>st;

        st.insert(1);
        int i=0;
        ll a=1;
        while(i<n){
            a=*st.begin();
            st.erase(a);
            st.insert(a*2);
            st.insert(a*3);
            st.insert(a*5);
            i++;
        
        }


        return a;
        
    }
};