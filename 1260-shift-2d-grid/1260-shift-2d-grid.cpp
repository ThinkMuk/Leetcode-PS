class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total;

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j; //1차원 배열로 펼치기
                int newIdx = (idx + k) % total; //1차원 배열에서 k번 이동시
                result[newIdx / n][newIdx % n] = grid[i][j]; //다시 2차원 배열로 되돌리기
            }
        }
        return result;
    }
};