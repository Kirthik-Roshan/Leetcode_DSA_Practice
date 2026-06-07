class Solution {
public:
    vector<string> ans;
    void dfs(int idx,int n,int k,int cost,bool prevOne,string &curr){
        if(cost>k) return;
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back('0');
        dfs(idx+1,n,k,cost,false,curr);
        curr.pop_back();
        if(!prevOne){
            curr.push_back('1');
            dfs(idx+1,n,k,cost+idx,true,curr);
            curr.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string curr;
        dfs(0,n,k,0,false,curr);
        return ans;
    }
};