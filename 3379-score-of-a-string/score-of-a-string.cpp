class Solution {
public:
    int scoreOfString(string s) {
        int score = 0 ;
        for(int i = 0 ; i < s.size()-1 ; i++) {
            int s2 = int(s[i+1]) ;
            int s1 = int(s[i]) ;
            int sc = s1 - s2 ;
            sc = sc > 0 ? sc : -sc ;
            score += sc ; 
        }
        return score ;
    }
};