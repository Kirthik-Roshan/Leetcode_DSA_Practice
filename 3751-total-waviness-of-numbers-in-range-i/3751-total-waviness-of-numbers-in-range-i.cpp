class Solution {
public:        
int waviness(int x){
        string s=to_string(x);
        int n=s.size();
        if(n<3) return 0;
        int count=0;
        for(int i=1;i<n-1;i++){
            int a=s[i-1]-'0';
            int b=s[i]-'0';
            int c=s[i+1]-'0';
            if(b>a && b>c) count++;
            if(b<a && b<c) count++;
        }
        return count;
        }
       int totalWaviness(int num1, int num2) {
        int total=0;
           for(int i=num1;i<=num2;i++){
               total+=waviness(i);
           }
           return total;
    }
};