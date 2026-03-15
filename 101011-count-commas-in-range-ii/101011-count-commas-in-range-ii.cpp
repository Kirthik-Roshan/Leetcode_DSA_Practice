class Solution {
public:
    long long countCommas(long long n) {
        long long st=1000,count=1,ans=0;
        while(st<=n){
            long long ed=min(n,st*1000-1);
            ans+=(ed-st+1)*count;
            st*=1000;
            count++;
        }
        return ans;
    }
};