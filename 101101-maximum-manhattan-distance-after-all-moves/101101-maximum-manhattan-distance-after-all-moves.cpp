class Solution {
public:
    int maxDistance(string moves) {
        int dx=0,dy=0,k=0;
        for(char ch:moves){
            if(ch=='R') dx++;
            else if(ch=='L') dx--;
            else if(ch=='U') dy++;
            else if(ch=='D') dy--;
            else k++;
        }
        return abs(dx)+abs(dy)+k;
    }
};