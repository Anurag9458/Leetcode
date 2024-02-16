#define ll long long 

class Solution {


    ll find(vector<int>&nums1,vector<int>&nums2,int n,int m,ll product){
         ll count=0;
        for(int i=0;i<n;i++)
        {
            long long val=nums1[i];
             if(val>=0)
            {
                ll l=0;
                ll r=m-1;
                ll ans=-1;
                while(l<=r)
                {
                    ll mid=(l+r)/2;
                    if((val*nums2[mid])<=product)
                    {
                        ans=mid;
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
                count+=ans+1;
            }
            else
            {
                ll l=0;
                ll r=m-1;
                ll ans=m;
                while(l<=r)
                {
                    ll mid=(l+r)/2;
                    if((val*nums2[mid])<=product)
                    {
                        ans=mid;
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                count+=m-ans;
            }
        }
        return count;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
        int n=nums1.size(),m=nums2.size();
        ll f1=nums1[0],f2=nums1[n-1],f3=nums2[0],f4=nums2[m-1];
        ll lo=min({f1*f2,f1*f3,f1*f4,f2*f3,f2*f4,f3*f4});
        ll hi=max({f1*f2,f1*f3,f1*f4,f2*f3,f2*f4,f3*f4});

        ll ans=-1;
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;

            if(find(nums1,nums2,n,m,mid)>=k){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }

        }
        return ans;
    }   
};