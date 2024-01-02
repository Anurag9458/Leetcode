class Solution {

    int solve(unsigned long d,unsigned long need){
       return need * d / (d-1) - (need % (d-1) ? 0 : 1);
    }
   

public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
         long hcf=__gcd(d1,d2);
            long l= d1/hcf*d2;
        int s=u1+u2;

        return max({solve(l,s),solve(d1,u1),solve(d2,u2)});
        
    }
};