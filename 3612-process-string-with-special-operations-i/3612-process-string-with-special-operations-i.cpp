class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char ch:s){
            if(isalpha(ch)) result+=ch;
            else if(ch=='*' && result!="") result.erase(result.size()-1);
            else if(ch=='#') result+=result;
            else if(ch=='%') reverse(result.begin(),result.end());
        }
        return result;
    }
};