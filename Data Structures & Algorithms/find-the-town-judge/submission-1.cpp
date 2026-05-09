class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

        for (auto &i : trust) {
            grid[i[0]][i[1]] = 1;
        }

        for (int i = 1; i <= n; i++) {

            bool everyoneTrusts = true;

            // everyone trusts i
            for (int j = 1; j <= n; j++) {
                if (i != j && !grid[j][i]) {
                    everyoneTrusts = false;
                    break;
                }
            }

            if (everyoneTrusts) {

                bool trustsNobody = true;

                // i trusts nobody
                for (int j = 1; j <= n; j++) {
                    if (i != j && grid[i][j]) {
                        trustsNobody = false;
                        break;
                    }
                }

                if (trustsNobody) {
                    return i;
                }
            }
        }

        return -1;
    }
};