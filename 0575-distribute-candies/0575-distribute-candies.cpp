class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int count=0;
        int n=candyType.size()/2;
        sort(candyType.begin(),candyType.end());
        candyType.erase(unique(candyType.begin(),candyType.end()),candyType.end());
        if(candyType.size()<=n) count=candyType.size(); 
        else count=n; 
        return count;      
    }
};