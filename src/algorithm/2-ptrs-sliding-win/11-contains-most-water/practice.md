```cpp
l=0, r=height.size-1
maxWater=0
while(l<r)
{
    maxWater=max((r-l)*min(height[l], height[r]), maxWater)
    if height[l] < height[r]
        l++
    else r--
}
return maxWater