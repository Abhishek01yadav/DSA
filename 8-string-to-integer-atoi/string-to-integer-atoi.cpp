class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        if (s.empty())
            return 0;

        int mx = INT_MAX, mn = INT_MIN;

// jab tak leading space mile skip krte jao
        int i = 0;
        while (i < n && isspace(s[i])) {
            i++;
        }


        if (i == n)
            return 0;


        int sign = 1;


// ab jis i pe mai hoon  
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }


//calculating ans
        long long ans = 0;

        while (i < n) {
            if (!isdigit(s[i]))
                break;

            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            if (sign * ans <= mn)
                return mn;
            if (sign * ans >= mx)
                return mx;

            i++;
        }
        return (sign * ans);
    }
};