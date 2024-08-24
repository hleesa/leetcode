class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        long long num = stoll(n);

        // Base cases
        if (num == 1)
            return "0";

        // Candidates
        std::vector<long long> candidates;

        // The original mirrored number
        std::string mirrorNum = mirror(n);
        candidates.push_back(stoll(mirrorNum));

        // Decrease the first half and mirror
        std::string prefix = n.substr(0, (len + 1) / 2);
        long long prefixNum = stoll(prefix);

        std::string smallerPrefix = std::to_string(prefixNum - 1);
        std::string smallerMirror =
            mirror(smallerPrefix + n.substr((len + 1) / 2));
        candidates.push_back(stoll(smallerMirror));

        // Increase the first half and mirror
        std::string largerPrefix = std::to_string(prefixNum + 1);
        std::string largerMirror =
            mirror(largerPrefix + n.substr((len + 1) / 2));
        candidates.push_back(stoll(largerMirror));

        // Handle edge cases like 1000 -> 999 and 999 -> 1001
        candidates.push_back(pow(10, len - 1) - 1);
        candidates.push_back(pow(10, len) + 1);

        // Find the closest palindrome
        long long closest = LLONG_MAX;
        for (long long candidate : candidates) {
            if (candidate != num) {
                if (std::abs(candidate - num) < std::abs(closest - num)) {
                    closest = candidate;
                } else if (std::abs(candidate - num) ==
                               std::abs(closest - num) &&
                           candidate < closest) {
                    closest = candidate;
                }
            }
        }

        return std::to_string(closest);
    }

private:
    string mirror(const std::string& s) {
        int n = s.length();
        std::string mirrored = s.substr(0, (n + 1) / 2);
        for (int i = n / 2 - 1; i >= 0; --i) {
            mirrored += mirrored[i];
        }
        return mirrored;
    }
};