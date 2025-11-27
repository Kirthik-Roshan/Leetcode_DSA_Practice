class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string>row(numRows);
        int curr=0,direction=1;
        for(char c:s){
            row[curr]+=c;
            if(curr==0) direction=1;
            else if(curr==numRows-1) direction=-1;
            curr+=direction;
        }
         string res;
         for(string r:row) res+=r;
         return res;
    }
};