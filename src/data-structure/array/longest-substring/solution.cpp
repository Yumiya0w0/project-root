#include <array>
#include <iostream>
#include <string>
using namespace std ;

int longestSubstrLength(string str)
{
    array<int, 256> lastSeen;
    lastSeen.fill(-1);
    int maxLen = 0, len = 0, l = 0;
    for(int r = 0; r < str.size(); r++) {
        int last = lastSeen[static_cast<unsigned char>(str[r])];
        if (last >= l) l = last + 1;
        lastSeen[static_cast<unsigned char>(str[r])] = r;
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}
int main()
{
    string str;
    cout << longestSubstrLength(str) << endl;
    str = "aaaaa";
    cout << longestSubstrLength(str) << endl;
    str = "abcde";
    cout << longestSubstrLength(str) << endl;
    str = "abcda";
    cout << longestSubstrLength(str) << endl;
}