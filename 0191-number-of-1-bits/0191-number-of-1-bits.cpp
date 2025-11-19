class Solution {
public:
    int hammingWeight(int n) {
        int temp=n,count=0;
        while(temp>0){
            if(temp&1) count++;
            temp>>=1;
        }
        return count;
    }
};