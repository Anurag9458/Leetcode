class Solution {
public:
    int passThePillow(int n, int time) {
        int temp=time%(n-1);
        int a=time/(n-1);
        if(a%2){
            return n-temp;
        }
        return temp+1;
    }
};