// 43. Multiply Strings

// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // Handle zero case.

        int n = num1.size(), m = num2.size();
        vector<int> result(n + m, 0); // Result array to store products.

        // Multiply each digit and add to the result.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + result[i + j + 1];
                result[i + j + 1] = sum % 10; // Store the single digit.
                result[i + j] += sum / 10; // Add the carry to the next position.
            }
        }

        // Convert result array to a string, skipping leading zeros.
        string ans;
        for (int num : result) {
            if (!(ans.empty() && num == 0)) { // Skip leading zeros.
                ans += to_string(num);
            }
        }

        return ans.empty() ? "0" : ans; // Handle the edge case of all zeros.
    }
};