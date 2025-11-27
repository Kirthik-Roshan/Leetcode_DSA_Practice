class Solution {
public:
    int expand(int left,int right,string s){
        while(left>=0 && right<s.size()&& s[left]==s[right]){
            left--;right++;
        } 
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int start=0,maxlen=1;
        for(int i=0;i<s.size();i++){
            int len1=expand(i,i,s);
            int len2=expand(i,i+1,s);
            int currlen=max(len1,len2);
            if(currlen>maxlen){
                maxlen=currlen;
                start=i-(currlen-1)/2;
            }
        }
        return s.substr(start,maxlen);
    }
};