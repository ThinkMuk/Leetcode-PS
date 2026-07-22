class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        string t = "1" + s + "1";
        int m = t.size();

        int base = 0;
        for (char c : s) if (c == '1') base++;

        // t를 그룹 단위로 분해
        vector<pair<char,int>> runs;
        int i = 0;
        while (i < m) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int best = 0;
        int r = runs.size();
        for (int k = 1; k + 1 < r; k++) {
            // 양옆이 0인 1 그룹들만
            if (runs[k].first == '1' && runs[k-1].first == '0' && runs[k+1].first == '0') {
                int gain = runs[k-1].second + runs[k+1].second; // R2는 base에 포함
                best = max(best, gain);
            }
        }

        return base + best;
    }
};