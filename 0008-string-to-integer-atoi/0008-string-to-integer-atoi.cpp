class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;
        long long res = 0;

        // 1. Skip spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits directly
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            res = res * 10 + digit;

            // Overflow check
            if (sign == 1 && res > INT_MAX) return INT_MAX;
            if (sign == -1 && -res < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(res * sign);
    }
};
