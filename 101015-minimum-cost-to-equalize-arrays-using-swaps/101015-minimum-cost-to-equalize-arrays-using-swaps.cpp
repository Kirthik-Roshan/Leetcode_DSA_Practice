class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> cnt1,cnt2;
        for(int x:nums1) cnt1[x]++;
        for(int x:nums2) cnt2[x]++;
        unordered_map<int,int> total;
        for(auto &p:cnt1) total[p.first]+=p.second;
        for(auto &p:cnt2) total[p.first]+=p.second;
        for(auto &p:total){
            if(p.second%2) return -1;
        }
        int sp=0;
        for(auto &p:total){
            int diff=abs(cnt1[p.first]-cnt2[p.first]);
            sp+=diff/2;
        }
        return sp/2;
    }
};