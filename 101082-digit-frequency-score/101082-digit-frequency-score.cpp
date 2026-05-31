class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum=0;
        unordered_map<int,int>freq;
        int temp=n;
        while(temp>0){
            int d=temp%10;
            freq[d]++;
            temp/=10;
        }
        for(auto p:freq){
            sum+=(p.first*p.second);
        }
        return sum;
    }
};