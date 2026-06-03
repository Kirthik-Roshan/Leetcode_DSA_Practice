class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        auto solve = [&](vector<int>& Astart,
                         vector<int>& Adur,
                         vector<int>& Bstart,
                         vector<int>& Bdur) {

            int m = Bstart.size();

            vector<pair<int,int>> rides;

            for(int i=0;i<m;i++)
                rides.push_back({Bstart[i], Bdur[i]});

            sort(rides.begin(), rides.end());

            vector<int> prefMinDur(m);
            prefMinDur[0] = rides[0].second;

            for(int i=1;i<m;i++)
                prefMinDur[i] =
                    min(prefMinDur[i-1], rides[i].second);

            vector<long long> suffMinFinish(m);

            suffMinFinish[m-1] =
                1LL*rides[m-1].first + rides[m-1].second;

            for(int i=m-2;i>=0;i--)
                suffMinFinish[i] =
                    min(suffMinFinish[i+1],
                        1LL*rides[i].first + rides[i].second);

            vector<int> starts(m);
            for(int i=0;i<m;i++)
                starts[i] = rides[i].first;

            long long best = LLONG_MAX;

            for(int i=0;i<(int)Astart.size();i++) {

                long long finishA =
                    1LL*Astart[i] + Adur[i];

                int pos =
                    upper_bound(starts.begin(),
                                starts.end(),
                                finishA)
                    - starts.begin();

                if(pos > 0) {
                    best = min(
                        best,
                        finishA + prefMinDur[pos-1]
                    );
                }

                if(pos < m) {
                    best = min(
                        best,
                        suffMinFinish[pos]
                    );
                }
            }

            return best;
        };

        ans = min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),

            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        );

        return (int)ans;
    }
};