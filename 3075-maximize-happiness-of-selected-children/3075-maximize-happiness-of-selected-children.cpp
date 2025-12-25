class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;

        // Index of the last (maximum) element after sorting
        int n = happiness.size() - 1;

        // Sort happiness values so we can pick the largest first
        sort(happiness.begin(), happiness.end());

        // Pick k people greedily from the largest happiness values
        for(int i = 0; i < k; i++) {

            // After picking i people, happiness reduces by i
            int currentHappiness = happiness[n - i] - i;

            // Add only if the reduced happiness is positive
            if(currentHappiness > 0)
                ans += currentHappiness;
            else
                // Further picks will only reduce happiness more
                break;
        }

        return ans;
    }
};