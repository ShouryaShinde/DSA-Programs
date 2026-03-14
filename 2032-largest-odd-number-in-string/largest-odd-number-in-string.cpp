class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() ;
        string ans = "";
        for(int i = n-1 ; i >= 0 ; i--) {
            if(int(num[i])%2 == 1) {
                for(int j = 0 ; j <= i ; j++ ) {
                    ans += num[j] ;
                }
                break ;
            }
        }
        return ans ;
    }
};