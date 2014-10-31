class Solution {
public:
    int atoi(const char *str) {
        if (str == 0)
            return 0;
        while (*str == ' ') {
            str++;
        }
        int limit = -INT_MAX;
        bool negative = false;
        if (*str == '-') {
            negative = true;
            limit = INT_MIN;
            str++;
        } else if (*str == '+') {
            str++;
        }
        if (*str == '\0') 
            return 0;
        int result = 0;
        int digit, multmin = limit / 10;
        while (*str != '\0') {
            digit = *str - '0';
            if (digit < 0 || digit > 9) {
                break;
            } else {
                if (result < multmin) {
                    if (negative)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }
                result *= 10;
                if (result < limit + digit) {
                    if (negative)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }
                result -= digit;
                str++;
            }
        }
        return negative ? result : -result;
    }
};
