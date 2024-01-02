class Solution {
public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
        
        long hcf=__gcd(d1,d2);
        long l=1,r=INT_MAX,lcm=(d1/hcf*d2);
        // cout<<l<<" ";
        while(l<=r){
            int mid = l + (r - l) / 2;
            int a = mid / d1, b = mid / d2;
            if (u1 <= mid - a && u2 <= mid - b && u1 + u2 <= (mid - (mid / lcm))) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

// #define ll long long
// class Solution {
// private:
//     int gcd(int a, int b) {
//         if (!b) return a;
//         return gcd(b, a % b);
//     }
//     int lcm(ll a, ll b) {
//         ll temp = (a / gcd(a, b)) * b;
//         return temp > INT_MAX ? INT_MAX : temp;
//     }
// public:
//     int minimizeSet(int divisor1, int divisor2, int uc1, int uc2) {
//         int l = 1, r = INT_MAX, LCM = lcm(divisor1, divisor2);
//         while (l <= r) {
            // int mid = l + (r - l) / 2;
            // int a = mid / divisor1, b = mid / divisor2;
            // if (uc1 <= mid - a && uc2 <= mid - b && uc1 + uc2 <= (mid - (mid / LCM))) {
            //     r = mid - 1;
            // } else {
            //     l = mid + 1;
            // }
//         }
//         return l;
//     }
// };