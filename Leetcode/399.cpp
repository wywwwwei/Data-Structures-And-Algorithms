/**
 * 399. 除法求值  Floyd
 * link：https://leetcode-cn.com/problems/evaluate-division/
 */

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        unordered_map<string, int> variables;
        int nums_variable = 0;

        for (int i = 0; i < equations.size(); i++)
        {
            if (variables.find(equations[i][0]) == variables.end())
                variables[equations[i][0]] = nums_variable++;
            if (variables.find(equations[i][1]) == variables.end())
                variables[equations[i][1]] = nums_variable++;
        }

        vector<vector<double>> graph(nums_variable, vector<double>(nums_variable, -1.0));
        for (int i = 0; i < n; i++)
        {
            int node_a = variables[equations[i][0]], node_b = variables[equations[i][1]];
            graph[node_a][node_b] = values[i];
            graph[node_b][node_a] = 1.0 / values[i];
        }

        for (int k = 0; k < nums_variable; k++)
            for (int i = 0; i < nums_variable; i++)
                for (int j = 0; j < nums_variable; j++)
                    if (graph[i][k] > 0 && graph[k][j] > 0)
                        graph[i][j] = graph[i][k] * graph[k][j];

        int m = queries.size();
        vector<double> result(m, 0);
        for (int i = 0; i < m; i++)
        {
            if (variables.find(queries[i][0]) != variables.end() && variables.find(queries[i][1]) != variables.end())
            {
                double cur = graph[variables[queries[i][0]]][variables[queries[i][1]]];
                if (cur > 0)
                {
                    result[i] = cur;
                    continue;
                }
            }
            result[i] = -1.0;
        }

        return result;
    }
};