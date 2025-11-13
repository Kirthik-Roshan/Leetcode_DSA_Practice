class Solution {
public:
    int reverse(int x) {
     long rev=0;
     long sign=(x<0)?-1:1;
     x=llabs(x);
     while(x>0){
        rev=rev*10+x%10;
        if(rev>INT_MAX) return 0;
        x/=10;
     }
     rev*=sign;
     return rev;
    }
};