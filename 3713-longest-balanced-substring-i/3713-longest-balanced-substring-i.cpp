class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char,int> freq;

            for(int j = i; j < n; j++){
                freq[s[j]]++;

                int mn = INT_MAX, mx = INT_MIN;

                for(auto &p : freq){
                    mn = min(mn, p.second);
                    mx = max(mx, p.second);
                }

                if(mn == mx){
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};
