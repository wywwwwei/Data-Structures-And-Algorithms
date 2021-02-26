/**
 * 1178. 猜字谜
 * link：https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/
 */

/**
 * Train of thought:
 * how to represent a word in words     ->      26 char array   ->  dont need count     ->  26 bits
 * how to represent a valid word for a puzzle   ->  contains the first letter and other letter
 *                                              ->  combination of other letters    ->  subset of bits 
 */
class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        unordered_map<int, int> wordCount;

        for (const string &word : words)
        {
            int binaryWord = 0;
            for (char c : word)
                binaryWord |= (1 << (c - 'a'));

            if (__builtin_popcount(binaryWord) <= 7)
                ++wordCount[binaryWord];
        }

        int n = puzzles.size();
        vector<int> result(n);
        for (int i = 0; i < n; ++i)
        {
            string &puzzle = puzzles[i];

            int binaryPuzzle = 0;   
            for (int i = 1; i < 7; ++i)
                binaryPuzzle |= (1 << (puzzle[i] - 'a'));   
                // The first letter must exist and does not need to participate in the subset traversal

            int subset = binaryPuzzle;
            int cur = 0;

            do
            {
                int sub = subset | (1 << (puzzle[0] - 'a'));
                if (wordCount.find(sub) != wordCount.end())
                    cur += wordCount[sub];

                subset = (subset - 1) & binaryPuzzle;
            } while (subset != binaryPuzzle);   // 000001 -> 000000 -> 111111   a round

            result[i] = cur;
        }

        return result;
    }
};