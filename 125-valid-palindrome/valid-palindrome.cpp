class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        
        // Filter only alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        // Use two pointers to check palindrome
        int left = 0, right = filtered.size() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};