// 13. Roman to Integer

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'I') {
                ans += 1;
            }
            if (i > 0 && s[i] == 'V' && s[i-1] == 'I') {
                ans += 4;
                i--;  // skip the previous 'I'
            } else if (s[i] == 'V') {
                ans += 5;
            }
            if (i > 0 && s[i] == 'X' && s[i-1] == 'I') {
                ans += 9;
                i--;  // skip the previous 'I'
            } else if (s[i] == 'X') {
                ans += 10;
            }
            if (i > 0 && s[i] == 'L' && s[i-1] == 'X') {
                ans += 40;
                i--;  // skip the previous 'X'
            } else if (s[i] == 'L') {
                ans += 50;
            }
            if (i > 0 && s[i] == 'C' && s[i-1] == 'X') {
                ans += 90;
                i--;  // skip the previous 'X'
            } else if (s[i] == 'C') {
                ans += 100;
            }
            if (i > 0 && s[i] == 'D' && s[i-1] == 'C') {
                ans += 400;
                i--;  // skip the previous 'C'
            } else if (s[i] == 'D') {
                ans += 500;
            }
            if (i > 0 && s[i] == 'M' && s[i-1] == 'C') {
                ans += 900;
                i--;  // skip the previous 'C'
            } else if (s[i] == 'M') {
                ans += 1000;
            }
        }
        return ans;
    }
};