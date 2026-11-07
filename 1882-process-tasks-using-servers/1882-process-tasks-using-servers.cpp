 #include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyServers;

        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }

        long long currentTime = 0;

        for (int j = 0; j < m; ++j) {
            currentTime = max(currentTime, (long long)j);

            if (freeServers.empty() && !busyServers.empty()) {
                currentTime = max(currentTime, get<0>(busyServers.top()));
            }

            while (!busyServers.empty() && get<0>(busyServers.top()) <= currentTime) {
                auto [time, weight, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({weight, idx});
            }

            auto [weight, idx] = freeServers.top();
            freeServers.pop();

            ans[j] = idx;
            busyServers.push({currentTime + tasks[j], weight, idx});
        }

        return ans;
    }
};