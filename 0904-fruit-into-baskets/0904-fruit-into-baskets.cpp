class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>freq;
        int left=0,maxfreq=0;
        for(int i=0;i<fruits.size();i++){
            freq[fruits[i]]++;
            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0) freq.erase(fruits[left]);
                left++;
            }
            maxfreq=max(maxfreq,i-left+1);
        }
        return maxfreq;
    }
};