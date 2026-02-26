class Solution {


    
public:
    int numSteps(string s) {
        int steps = 0;

        while (s != "1") {
            if (s.back() == '0') {
                // even → divide by 2 (right shift)
                s.pop_back();
            } else {
                // odd → +1 (binary addition)
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i < 0)
                    s = "1" + s;
                else
                    s[i] = '1';
            }
            steps++;
        }
        return steps;
    }
};
        
 