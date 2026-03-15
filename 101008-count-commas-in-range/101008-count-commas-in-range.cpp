class Solution {
public:
    int countCommas(int n) {
        long long start=1000;
        int count=1;
        long long ans=0;
        while(start<=n){
            long long ed=min((long long)n,start*1000-1);
            ans+=(ed-start+1)*count;
            start*=1000;
            count++;
        }
        return ans;
    }
};