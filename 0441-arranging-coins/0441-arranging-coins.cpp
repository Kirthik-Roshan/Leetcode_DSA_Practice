class Solution {
public:
    int arrangeCoins(int n) {
        int i;
        for(i=1;i<=n;i++){
            if(i<=n) n-=i;
        }
        return i-1;
    }
};