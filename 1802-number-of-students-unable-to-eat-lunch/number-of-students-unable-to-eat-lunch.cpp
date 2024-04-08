class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count=0,count1=0;
        
        for(int i:students){
           if(i){
            count1++;
           }else{
            count++;
           }
        }

        for(int i:sandwiches){
            if(i && count1){
                count1--;
            }else if(!i && count){
                count--;
            }else{
                break;
            }
        }

        return count1+count;
        
    }
};