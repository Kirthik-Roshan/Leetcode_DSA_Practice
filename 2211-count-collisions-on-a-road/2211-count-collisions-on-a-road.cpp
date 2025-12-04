class Solution {
public:
    int countCollisions(string directions) {
        int count = 0, right = 0;
        bool stoppedBefore = false;
        for (char ch : directions) {
            if (ch == 'R') {
                right++;
                stoppedBefore = false;
            }
            else if (ch == 'S') {
                count += right;
                right = 0;
                stoppedBefore = true;
            }
            else { 
                if (right > 0) {
                    count += (right + 1);
                    right = 0;
                    stoppedBefore = true;
                } else if (stoppedBefore) {
                    count += 1;
                    stoppedBefore = true;
                }
            }
        }
        return count;
    }
};
