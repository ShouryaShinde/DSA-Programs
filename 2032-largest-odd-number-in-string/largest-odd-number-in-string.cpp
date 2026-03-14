class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() ;
        string ans = "";
        int index = -1 ;
        for(int i = n-1 ; i >= 0 ; i--) {
            if(int(num[i])%2 == 1) {
                index = i ;
                break ;
            }
        }
        for(int i = 0 ; i <= index ; i++ ) {
            ans += num[i] ;
        }

        return ans ;
    }
};