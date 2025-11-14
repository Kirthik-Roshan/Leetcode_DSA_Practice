class monotoq{
    public:
    deque<int>d;
    void push(int x){
        while(!d.empty() && d.back()<x){
            d.pop_back();
        }
        d.push_back(x);
    }
    void pop(int x){
        if(!d.empty()&& d.front()==x){
            d.pop_front();
        }
    }
    int top(){
        return d.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        monotoq mq;vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(i<k-1) mq.push(nums[i]);
            else{
                mq.push(nums[i]);
                res.push_back(mq.top());
                mq.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};