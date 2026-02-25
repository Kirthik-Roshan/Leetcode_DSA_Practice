class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int x : arr){
            int num = x;
            int count = 0;
            while(num > 0){
                count += (num & 1);  
                num >>= 1;          
            }
            mp[x] = count;
        }
        sort(arr.begin(), arr.end(), [&](int a, int b){
            if(mp[a] == mp[b])
                return a < b;      
            return mp[a] < mp[b];  
        });

        return arr;
    }
};