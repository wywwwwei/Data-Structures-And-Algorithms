/**
 * 841. 钥匙和房间
 * link：https://leetcode-cn.com/problems/keys-and-rooms/
 */

class Solution
{
    vector<bool> visited;
    int count = 0;

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        visited.resize(rooms.size());
        dfs(rooms, 0);
        return count == rooms.size();
    }

    void dfs(vector<vector<int>> &room, int cur_room)
    {
        visited[cur_room] = true;
        count++;
        for (const auto &r : room[cur_room])
        {
            if (!visited[r])
                dfs(room, r);
        }
    }
};