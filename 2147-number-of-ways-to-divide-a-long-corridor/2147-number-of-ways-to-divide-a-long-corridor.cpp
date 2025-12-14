class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD=1e9+7;
        int seat=0,plant=0;
        long long res=1;
             for(char ch:corridor){
                if(seat!=2){
                    if(ch=='S') seat++;
                }
                else{
                    if(ch=='S'){
                        plant++;
                        res*=plant;
                        res%=MOD;
                        seat=1;
                        plant=0;
                    }
                    else plant++;
               }  
       }
       return seat!=2?0:res;
    }
};