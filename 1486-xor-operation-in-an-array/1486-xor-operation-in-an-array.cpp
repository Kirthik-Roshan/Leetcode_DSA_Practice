class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>res;int count=0;
        for(int i=0;i<n;i++) res.push_back(start+(2*i));
        for(int num:res) count^=num;
        return count;
    }
};