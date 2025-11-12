class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // stores indexes

        // traverse twice to simulate circular array
        for(int i = 0; i < 2 * n; i++) {
            int num = nums[i % n]; // use modulo for circular behavior

            // while current number > top of stack’s number
            while(!st.empty() && num > nums[st.top()]) {
                res[st.top()] = num;
                st.pop();
            }
            if(i < n) st.push(i);
        }

        return res;
    }
};
