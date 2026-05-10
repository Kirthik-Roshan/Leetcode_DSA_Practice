class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(string &chunk:chunks) s+=chunk;
        unordered_map<string,int> freq;
        int n=s.size();
        int i=0;
        while(i<n){
            if(!(s[i]>='a' && s[i]<='z')){
                i++;
                continue;
            }
            int start=i;
            string word="";
            while(i<n){
                if(s[i]>='a' && s[i]<='z'){
                    word+=s[i];
                    i++;
                }
                else if(s[i]=='-'){
                    if(i>start && i+1<n && s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z'){
                        word+='-';
                        i++;
                    }
                    else break;
                    
                }
                else break;
                
            }

            if(!word.empty()) freq[word]++;
            if(i<n && !((s[i]>='a' && s[i]<='z') || s[i]=='-')) i++;
        }
        vector<int> ans;
        for(string &q: queries) ans.push_back(freq[q]);
        return ans;
    }
};