class Twitter {
public:
    unordered_map<int, unordered_set<int>> followMap; // userId -> {}
    unordered_map<int, vector<pair<int, int>>> tweetsMap; // userId -> [{time, tweetId}]
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        ++time;
        auto& tweets = tweetsMap[userId];
        tweets.push_back({time, tweetId});
        if (tweets.size() > 10) tweets.erase(tweets.begin());        
    } 
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (const auto& tweet : tweetsMap[userId]) min_heap.push(tweet);
        // cout << userId << ":\n";
        for (const auto& follower : followMap[userId]) {
            // cout << " " << follower << "\n";
            const auto& tweets = tweetsMap[follower];
            for (auto& tweet : tweets) {
                min_heap.push(tweet);
                // cout << "  " << tweet.first << " " << tweet.second << "\n";
                if (min_heap.size() > 10) min_heap.pop();
            }
            // cout << "\n";
        }
        // cout << "in heap:\n";
        vector<int> res;
        while(!min_heap.empty()) {
            auto& tweet = min_heap.top();
            // cout << " " << tweet.first << " " << tweet.second << "\n";
            res.push_back(tweet.second);
            min_heap.pop();
        }
        // cout << "\n";
        // cout << "res: ";
        // for (int x : res) cout << x << " ";
        // cout << "\n";
        reverse(res.begin(), res.end());
        return res;
    }

    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (followMap[followerId].count(followeeId)) 
            followMap[followerId].erase(followeeId);
    }
};
