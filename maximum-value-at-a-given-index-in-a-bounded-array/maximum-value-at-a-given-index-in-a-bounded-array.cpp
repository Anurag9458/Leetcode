class Solution {
public:
    int maxValue(long n, long index, long maxsum) {
        long r=n-index-1;
        long l=index;

        long lo=1,hi=maxsum;

        long ans=0;

        while(lo<=hi)
        {
            long mid=lo+(hi-lo)/2;
            long sum=mid;
            long ls=0,rs=0;
            long m=mid-1;

            if(r<=m)
            {
                rs=m*(m+1)/2-((m-r)*(m-r+1)/2);
            }
            else
            {
                rs=m*(m+1)/2+1*(r-m);
            }

            if(l<=m)
            {
                ls=m*(m+1)/2-((m-l)*(m-l+1)/2);
            }
            else
            {
                ls=m*(m+1)/2+1*(l-m);
            }

            sum+=rs+ls;

            if(sum<=maxsum)
            {
                ans=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        return ans;
    }
};