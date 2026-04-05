class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> count;
        int limit=1;
        while(limit*limit*limit<=n) limit++;
        limit--;
        for(int a=1;a<=limit;a++){
            for(int b=a;b<=limit;b++){
                int sum=a*a*a+b*b*b;
                if(sum>n) break;
                count[sum]++;
            }
        }
        vector<int> ans;
        for(auto &p:count){
            if(p.second>=2)ans.push_back(p.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};