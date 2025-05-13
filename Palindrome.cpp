#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Convert to lowercase
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return tolower(c); });

        // Remove non-alphabetic characters 
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !isalnum(c); 
        }), s.end());

        // Check palindrome
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string message = sol.isPalindrome("A man, a plan, a canal: Panama") 
                     ? "Yes, a valid palindrome" 
                     : "Not a valid palindrome";
    cout << message << endl;
    return 0;
}
