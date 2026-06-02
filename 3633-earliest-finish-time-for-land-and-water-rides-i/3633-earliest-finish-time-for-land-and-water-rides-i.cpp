class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land -> Water
                long long landFinish =
                    1LL * landStartTime[i] + landDuration[i];

                long long waterBegin =
                    max(landFinish,
                        1LL * waterStartTime[j]);

                ans = min(ans,
                          waterBegin + waterDuration[j]);

                // Water -> Land
                long long waterFinish =
                    1LL * waterStartTime[j] + waterDuration[j];

                long long landBegin =
                    max(waterFinish,
                        1LL * landStartTime[i]);

                ans = min(ans,
                          landBegin + landDuration[i]);
            }
        }

        return (int)ans;
    }
};