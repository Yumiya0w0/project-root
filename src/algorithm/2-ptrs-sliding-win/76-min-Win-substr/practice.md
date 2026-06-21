- init `freqT`
- update `freqS`

```cpp
bool includeChars(const array<int, 256> freqT, array<int, 256> freqS)
{
    for(int i = 0; i < 256; i++)
    {
        if(freqT[i] > 0 && freqT[i] > freqS[i])
            return false;
    }
    return true;
}

string minWindow(string s, string t) 
{
    string ans = "";
    array<int, 256> freqT;
    array<int, 256> freqS;
    freqT.fill(0);
    freqS.fill(0);
    int l = 0;
    for(char c: t) freqT[c]++;
    for (int r = 0; r < s.size(); r++)
    {
        char c = s[r];
        freqS[c]++;
        if(freqT[c] > 0 && freqS[c] == freqT[c])
        {
            if(includeChars(freqT, freqS))
            {
                // found candidate, start trimmimg
                for(; l <= r; l++)
                {
                    if(freqT[s[l]] > 0 && freqS[s[l]] == freqT[s[l]])
                    {
                        if(ans == "" || ans.size() > r-l+1 )
                            ans = s.substr(l, r-l+1);
                        freqS[s[l++]]--;
                        break;
                    }
                    freqS[s[l]]--;
                }
            }
        }
    }
    return ans;
}
```