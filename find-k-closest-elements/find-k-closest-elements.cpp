class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, n = arr.size();
        int right = n - 1;
        while(right - left >= k){
            if(x - arr[left] <= arr[right] - x){
                right--;
            }
            else{
                left++;
            }
        }
        return vector<int>(begin(arr) + left, begin(arr) + right + 1);
    }
};