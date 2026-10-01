class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto ele : s) {

            if (ele == '(' || ele == '{' || ele == '[') {
                st.push(ele);
            }

           else    {
            if(st.empty()) return false;
            char ch=st.top(); 
           
            if(ele==')' && ch=='('   ||  ele=='}' && ch=='{'   ||  ele==']' && ch=='['   ){
                st.pop();
            }
             else  return false;

           }

           
          
        }

       return st.empty();
    }
};