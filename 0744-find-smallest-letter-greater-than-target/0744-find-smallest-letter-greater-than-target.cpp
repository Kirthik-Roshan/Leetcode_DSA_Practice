class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int goal = target;
        char res;
        for (char ch : letters) {
            int temp = ch;
            if (goal < temp) {
                res = ch;
                break;
            } else
                res = letters[0];
        }
        return res;
    }
};