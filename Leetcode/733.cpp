/**
 * 733. 图像渲染 dfs
 * link：https://leetcode-cn.com/problems/flood-fill/
 */

class Solution
{
    int m, n;
    int color;
    int newColor;

    void dfs(vector<vector<int>> &image, int sr, int sc)
    {
        if (sr < 0 || sr >= m || sc < 0 || sc >= n)
            return;
        if (image[sr][sc] != color || image[sr][sc] == newColor)
            return;
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc);
        dfs(image, sr - 1, sc);
        dfs(image, sr, sc + 1);
        dfs(image, sr, sc - 1);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        m = image.size();
        n = image[0].size();
        color = image[sr][sc];
        this->newColor = newColor;
        dfs(image, sr, sc);
        return image;
    }
};