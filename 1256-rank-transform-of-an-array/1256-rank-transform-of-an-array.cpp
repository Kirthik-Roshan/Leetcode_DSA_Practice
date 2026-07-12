class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr,res;
        unordered_map<int,int>rank;
        int rk=1;
        sort(temp.begin(),temp.end());
        for(int num:temp){
            if(!rank.count(num)) rank[num]=rk++;
        }
        for(int num:arr) res.push_back(rank[num]);
        return res;
    }
};