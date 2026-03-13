class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0 ;
        string ans ;
        for(auto it : s) {
            if(it == '(') {
                count++ ;
                if(count > 1) ans += it ;
            }
            else if(it == ')') {
                count-- ;
                if(count > 0) ans += it ;
            }
            else {
                ans += it ;
            }
        }
        return ans ;
    }
};