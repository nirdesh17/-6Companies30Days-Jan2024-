class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        // Sort envelopes primarily by width in ascending order
        // and by height in descending order when widths are the same
        std::sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });

        for(auto i:envelopes)
        {
            cout<<i[0]<<" "<<i[1]<<endl;
        }
        
        vector<int> dp;
        for (auto& envelope : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
            if (it == dp.end()) {
                dp.push_back(envelope[1]);
            } else {
                *it = envelope[1];
            }
        }

        return dp.size();
    }
};
