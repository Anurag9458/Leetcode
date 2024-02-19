class Solution {

void merge(vector<int>&nums,int lo,int mid,int hi){
    int n1=mid-lo+1,n2=hi-mid;
    vector<int>arr1(n1),arr2(n2);
    for(int i=0;i<n1;i++){
        arr1[i]=nums[i+lo];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=nums[mid+i+1];
    }

    int i=0,j=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            nums[lo++]=arr1[i++];
        }else{
            nums[lo++]=arr2[j++];
        }
    }

    while(i<n1){
        nums[lo++]=arr1[i++];
    }

    while(j<n2){
        nums[lo++]=arr2[j++];
    }

}

void mergesort(vector<int>&nums,int lo,int hi){
    int mid=lo+(hi-lo)/2;
    if(hi<=lo){
        return;
    }
    mergesort(nums,lo,mid);
    mergesort(nums,mid+1,hi);
    merge(nums,lo,mid,hi);
}

public:
    vector<int> sortArray(vector<int>& nums) {
     int n=nums.size();
     mergesort(nums,0,n-1);
     return nums;   
    }
};