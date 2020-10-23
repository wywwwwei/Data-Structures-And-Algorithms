/**
 * 1024. 视频拼接  贪心
 * link：https://leetcode-cn.com/problems/video-stitching/
 */

class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int T)
    {
        sort(clips.begin(), clips.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]);
        });

        int cur_record = 0, max_record = 0;
        int result = 0;
        int i = 0, n = clips.size();
        while (i < n)
        {
            if (clips[i][0] > cur_record || cur_record >= T)
                break;
            while (i < n && clips[i][0] <= cur_record)
                max_record = max(max_record, clips[i++][1]);
            cur_record = max_record;
            result++;
        }

        return (cur_record >= T ? result : -1);
    }
};