// 12. Integer to Roman

// Seven different symbols represent Roman numerals with the following values:

// Symbol	Value
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000
// Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

// If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
// If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
// Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
// Given an integer, convert it to a Roman numeral.

class Solution {
public:
    string intToRoman(int num) {
         string ans;
        
        while (num > 0) {
            while (num >= 1000) {
                ans += "M";
                num -= 1000;
            }
            if (num >= 900) {
                ans += "CM";
                num -= 900;
            }
            while (num >= 500) {
                ans += "D";
                num -= 500;
            }
            if (num >= 400) {
                ans += "CD";
                num -= 400;
            }
            while (num >= 100) {
                ans += "C";
                num -= 100;
            }
            if (num >= 90) {
                ans += "XC";
                num -= 90;
            }
            while (num >= 50) {
                ans += "L";
                num -= 50;
            }
            if (num >= 40) {
                ans += "XL";
                num -= 40;
            }
            while (num >= 10) {
                ans += "X";
                num -= 10;
            }
            if (num == 9) {
                ans += "IX";
                num -= 9;
            }
            if (num >= 5) {
                ans += "V";
                num -= 5;
            }
            if (num == 4) {
                ans += "IV";
                num -= 4;
            }
            while (num > 0) {
                ans += "I";
                num -= 1;
            }
        }
        return ans;
    }
};