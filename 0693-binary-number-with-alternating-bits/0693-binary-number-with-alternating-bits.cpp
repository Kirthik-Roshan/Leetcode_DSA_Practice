class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp=n&1;
        n>>=1;
        while(n>0){
            int curr=n&1;
            if(temp==curr) return false;
            temp=curr;
            n>>=1;
        }
        return true;
    }
};