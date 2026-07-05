class Solution {
public:
    int getrange(int x){
        int mx=0,mn=9;
        while(x>0){
            int d=x%10;
            mx=max(mx,d);
            mn=min(mn,d);
            x/=10;
        }
        return mx-mn;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxrange=-1;
        for(int x:nums)
            maxrange=max(maxrange,getrange(x));
        int sum=0;
        for(int x:nums){
            if(getrange(x)==maxrange)
                sum+=x;
        }
        return sum;
    }
};