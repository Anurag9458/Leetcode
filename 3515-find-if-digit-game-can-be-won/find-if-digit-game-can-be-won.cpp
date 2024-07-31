class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1=0,sum2=0,sum3=0;
        for(int i : nums){
            if(i<10){
                sum1+=i;
            }else if(i<100){
                sum2+=i;
            }else{
                sum3+=i;
            }
        }
        if(sum1<sum2){
            swap(sum1,sum2);
        }
        return sum1>(sum2+sum3);
    }
};