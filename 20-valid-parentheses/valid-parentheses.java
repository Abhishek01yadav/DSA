class Solution {
    public boolean isValid(String s) {
        Deque<Character> st=new ArrayDeque<>();
        for(char ele : s.toCharArray()){
            if(ele=='(' || ele =='{' || ele=='['){
                st.push(ele);

            }

            else{
                if(st.isEmpty()) return false;

                char ch=st.pop();
                
                if( ele==')'  && ch=='('  || ele=='}'  && ch=='{' || ele==']'  && ch=='[' )
                {

                }

                else return false;


            }
        }
        return st.isEmpty();
        
    }
}