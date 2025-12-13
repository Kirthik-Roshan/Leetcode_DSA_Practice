class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive){
        vector<pair<string,string>>mp;
        vector<string>catg={"electronics","grocery","pharmacy","restaurant"};
        vector<string>res;
        for(int i=0;i<code.size();i++){
            string c=code[i];
            string b=businessLine[i];
            bool a=isActive[i];
            bool flag=1;
            if(c.empty()) continue;
             for (char ch : c) {
                if (!(isalnum(ch) || ch == '_')) {
                    flag = false;
                    break;
                }
            }
            if(flag && find(catg.begin(),catg.end(),b)!=catg.end() && a) mp.push_back({b,c});
        }
            sort(mp.begin(),mp.end());
            for(auto &p:mp){
                res.push_back(p.second);
        }
        return res;
    }
};