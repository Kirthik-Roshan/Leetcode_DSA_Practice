class Solution {
public:
    int bitwiseComplement(int n) {
       int temp=n;
       if(n==0) return 1;
       int res=0,i=0;
       while(temp>0){
        int d=temp&1;
        res+=(!d)*(1<<i);
        i++;
        temp>>=1;
       } 
       return res;
    }
};