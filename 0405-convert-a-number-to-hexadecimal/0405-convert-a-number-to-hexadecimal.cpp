class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        unordered_map<int,char>mp={{10,'a'},{11,'b'},{12,'c'},{13,'d'},{14,'e'},{15,'f'},{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'}};
        unsigned int temp=num;
        string res="";
        while(temp>0){
            int q=temp%16;
            res.push_back(mp[q]);
            temp/=16;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};