### Two Pointers / Sliding Window — completed (2026-06-21)
Patterns covered: Variable Window, Monotonic Window, Fixed Window, Opposite Ends, Same Direction

#### Struggle Patterns to Watch
- Duplicate skipping in sorted arrays (3Sum — needed scaffolding)
- Pointer order bugs under pressure (`l++` before decrement in Minimum Window Substring)

#### Strengths
- Monotonic window invariant reasoning (independently proved stale-high frequency is safe)
- Last-seen array variant over hash map (space/time awareness)
- Fixed window slide mechanics
- Bottleneck pointer movement reasoning (Container With Most Water)

---

### PRACTICE_PROGRESS

| Problem | Difficulty | Status | TC | SC | Notes |
|---|---|---|---|---|---|
| Longest Substring Without Repeating Chars | Medium | ✅ | O(n) | O(1) | Clean last-seen array variant |
| Longest Repeating Character Replacement | Medium | ✅ | O(n) | O(1) | Independently reasoned monotonic window |
| Container With Most Water | Medium | ✅ | O(n) | O(1) | Clean |
| 3Sum | Medium | ✅ | O(n²) | O(1) | Needed scaffolding on duplicate skipping |
| Remove Duplicates from Sorted Array | Easy | ✅ | O(n) | O(1) | Too easy, skipped |
| Maximum Sum Subarray of Size K | Easy | ✅ | O(n) | O(1) | Minor typo, otherwise clean |
| Minimum Window Substring | Hard | ✅ | O(n) | O(1) | Pointer order bug; `matched` counter optimization noted |
