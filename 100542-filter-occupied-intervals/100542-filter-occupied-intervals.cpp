class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        if(occupiedIntervals.empty()) return {};
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>> merged;
        for(auto &in: occupiedIntervals){
            if(merged.empty() || in[0]>merged.back()[1]+1) merged.push_back(in);
            else merged.back()[1]=max(merged.back()[1],in[1]);
        }
        vector<vector<int>> ans;
        for(auto &in:merged){
            int L=in[0],R=in[1];
            if(R<freeStart || L>freeEnd){
                ans.push_back({L,R});
                continue;
            }
            if(L<=freeStart-1) ans.push_back({L,freeStart-1});
            if(R>=freeEnd+1) ans.push_back({freeEnd+1,R});
            
        }
        return ans;
    }
};