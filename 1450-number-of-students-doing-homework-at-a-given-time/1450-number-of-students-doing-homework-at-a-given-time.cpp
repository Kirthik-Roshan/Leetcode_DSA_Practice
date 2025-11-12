class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int k=queryTime;
        int count=0;
        queue<int>s,e;
        for(int i=0;i<endTime.size();i++){
            s.push(startTime[i]);
            e.push(endTime[i]);
        }
        while(!e.empty()){
            int a=s.front();
            int b=e.front();
            if(a<=k && k<=b) count++;
            s.pop();
            e.pop();
        }
        return count;
    }
};