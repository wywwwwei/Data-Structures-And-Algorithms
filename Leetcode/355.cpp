/**
 * 355. 设计推特
 * link：https://leetcode-cn.com/problems/design-twitter/
 */

/**
 * Everyone can follow and unfollow others -> hash(int)->set -> unfollow -> hash(set)
 * To get the feed, you need to record the tweet time -> list/vector -> tweet:tweetID + tweetTime
 * Everyone can tweet and we can see the followee's push according to the follow list -> hash(int)->list/vector(tweet)
 * 
 * Retrieve the 10 most recent tweet ids -> merge followee's tweet link -> see https://leetcode-cn.com/problems/merge-k-sorted-lists/ 
 * We can achieve it in two ways:
 * 1.Divide and conquer
 * 2.Heap
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

struct TweetNode
{
    Tweet *tweet;
    TweetNode *prev;
    TweetNode *next;
    TweetNode(Tweet *_tweet)
    {
        this->tweet = _tweet;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class List
{
public:
    TweetNode *head;
    TweetNode *tail;
    int count = 0;

    ~List()
    {
        TweetNode *temp = this->head;
        while (temp)
        {
            TweetNode *temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push_front(Tweet *tweet)
    {
        TweetNode *temp = new TweetNode(tweet);
        if (this->head != nullptr)
        {
            this->head->prev = temp;
        }
        else
        {
            this->tail = temp;
        }
        temp->next = this->head;
        this->head = temp;
        count++;
    }

    void pop_back()
    {
        TweetNode *temp = this->tail;
        this->tail = temp->prev;
        this->tail->next = nullptr;
        delete temp;
        count--;
    }
};
class Twitter
{
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, List> tweets;
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
        List &myTweet = tweets[userId];
        myTweet.push_front(new Tweet(tweetId, this->curTime++));
        if (myTweet.count > this->feedCount)
            myTweet.pop_back();
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> tweetID;
        auto cmp = [](TweetNode *a, TweetNode *b) {
            return a->tweet->postTime < b->tweet->postTime;
        };
        priority_queue<TweetNode *, vector<TweetNode *>, decltype(cmp)> pq(cmp);

        List &myTweets = tweets[userId];
        if (myTweets.head != nullptr)
            pq.push(myTweets.head);
        for (auto following : follows[userId])
        {
            if (following == userId)
                continue;
            List &hisTweets = tweets[following];
            if (hisTweets.head != nullptr)
                pq.push(hisTweets.head);
        }

        while (tweetID.size() < this->feedCount && !pq.empty())
        {
            TweetNode *temp = pq.top();
            pq.pop();
            tweetID.push_back(temp->tweet->tweetID);
            temp = temp->next;
            if (temp != nullptr)
                pq.push(temp);
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