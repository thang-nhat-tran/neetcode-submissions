class Twitter {
private: 
    const int MAX_USER = 100;
    vector<vector<int>> following;
    vector<vector<pair<int, int>>> tweets; // userId -> [{time, tweetId}]
    int time;
public:
    Twitter() {
        time = 0;
        following.resize(MAX_USER + 1, vector<int>());
        tweets.resize(MAX_USER + 1, vector<pair<int, int>>());
    }
    
    void postTweet(int userId, int tweetId) {
        ++time;
        tweets[userId].push_back({time, tweetId});        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> res;
        const auto u_tweets = tweets[userId];
        for (int i = u_tweets.size() - 1; i >= 0 && u_tweets.size() - i <= 10; i--) res.push_back(u_tweets[i]);
        for (auto& flw : following[userId]) {
            const auto& tws = tweets[flw];
            for (int i = tws.size() - 1; i >= 0 && tws.size() - i <= 10; i--) res.push_back(tws[i]);
        }
        sort(res.begin(), res.end(), [](const auto& x, const auto& y) {
            return x.first > y.first;
        });
        vector<int> final;
        for (int i = 0; i < res.size() && i < 10; i++) final.push_back(res[i].second);
        return final;
    }

    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        auto& follower = following[followerId];
        
        if (find(follower.begin(), follower.end(), followeeId) != follower.end()) return;
        follower.push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
                if (followerId == followeeId) return;

        auto& follower = following[followerId];
        if (find(follower.begin(), follower.end(), followeeId) == follower.end()) return;

        follower.erase(remove(follower.begin(), follower.end(), followeeId), follower.end());
    }
};
