class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>s;
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int diff=0;
            while(!s.empty()&& temperatures[i]>temperatures[s.top()]){
                   diff=i-s.top();
                   res[s.top()]=diff;
                   s.pop();
            }
            s.push(i);
        }
        return res;
    }
};