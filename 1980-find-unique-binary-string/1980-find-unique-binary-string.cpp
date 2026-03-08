class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int total=1<<nums.size();
        string res="";
        for(int num=0;num<total;num++){
            string temp="";
            for(int i=nums.size()-1;i>=0;i--){
                   temp+=((num>>i)&1)+'0';
            }
       if(find(nums.begin(), nums.end(), temp)==nums.end()) res=temp;
        }
        return res;
    }
};