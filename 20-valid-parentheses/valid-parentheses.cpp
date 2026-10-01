class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto ele : s) {

            if (ele == '(' || ele == '{' || ele == '[') {
                st.push(ele);
            }

           else  if ((st.size() > 0 && st.top() == '(' && ele == ')') ||
                st.size() > 0 && st.top() == '{' && ele == '}' ||
                st.size() > 0 && st.top() == '[' && ele == ']') {
                st.pop();
            }
            else return false;
        }

        if (st.empty())
            return true;
        return false;
    }
};