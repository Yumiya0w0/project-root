#include <array>
#include <iostream>
#include <string>
using namespace std ;

int longestSubstrLength(string str)
{
    array<int, 256> lastSeen{-1};
    lastSeen.fill(-1);
    if(str.size() < 2) return str.size();
    int maxLen = 1, len = 1, l = 0;
    lastSeen[static_cast<int>(str[0])] = 0; //!!!!!
    for(int r = 1; r < str.size(); r++)
    {
        // check if last seen index of str[r] is in the window
        int last = lastSeen[static_cast<int>(str[r])];
        cout << "Last:" << last << "\n";
        lastSeen[static_cast<int>(str[r])] = r;
        if(l <= last && last <= r)
        {
            // update l to last+1
            l = last + 1;
        }
        // update len
        len = r - l + 1;
        maxLen = max(maxLen, len);
        cout << "L: " << l << ", R: " << r << ", maxLen: " << maxLen << "\n"; 
    }
    return maxLen;
}

int main()
{
    string str;
    str = "aaaaa";
    cout << longestSubstrLength(str) << endl;
    str = "abcde";
    cout << longestSubstrLength(str) << endl;
    str = "abcda";
    cout << longestSubstrLength(str) << endl;
}