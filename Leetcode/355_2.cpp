/**
 * 355. 设计推特
 * link：https://leetcode-cn.com/problems/design-twitter/
 */

struct Tweet
{
    int tweetID;
    int postTime;
    Tweet(int _tweetID, int _postTime)
    {
        this->tweetID = _tweetID;
        this->postTime = _postTime;
    }
};

class Twitter
{
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, list<Tweet>> tweets;
    int curTime;
    int feedCount;

public:
    /** Initialize your data structure here. */
    Twitter()
    {
        this->curTime = 0;
        this->feedCount = 10;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        list<Tweet> &myTweet = tweets[userId];
        myTweet.push_front(Tweet(tweetId, this->curTime++));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> tweetID;
        auto cmp = [](Tweet &a, Tweet &b) {
            return a.postTime > b.postTime;
        };
        priority_queue<Tweet, vector<Tweet>, decltype(cmp)> pq(cmp);

        list<Tweet> &myTweets = tweets[userId];
        for (auto &tweet : myTweets)
        {
            pq.push(tweet);
            if (pq.size() == this->feedCount)
                break;
        }

        for (auto &following : follows[userId])
        {
            if (following == userId)
                continue;
            list<Tweet> &hisTweets = tweets[following];
            for (auto &tweet : hisTweets)
            {
                if (pq.size() < this->feedCount)
                    pq.push(tweet);
                else if (pq.top().postTime < tweet.postTime)
                {
                    pq.pop();
                    pq.push(tweet);
                }
            }
        }

        while (!pq.empty())
        {
            tweetID.insert(tweetID.begin(),pq.top().tweetID);
            pq.pop();
        }

        return tweetID;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        follows[followerId].emplace(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */