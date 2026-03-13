class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans ;
        stack<char> st ;
        for(auto it : s) {
            if(st.empty()) {
                st.push(it) ;
            } else {
                if(it == '(') {
                    ans += it ;
                    st.push(it) ;
                }
                else if (it == ')') {
                    while(st.top() != '(') st.pop() ;
                    st.pop() ;
                    if(!st.empty()) ans += it ;
                }
                else {
                    ans += it ;
                }
            }
        }
        return ans ;
    }
};