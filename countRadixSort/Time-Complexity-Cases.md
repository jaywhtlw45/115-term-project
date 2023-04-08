> Counting Sort:
---
- Best - Input values are integers in small range, e.g. range is O(n).
- Worst - Input values are very large/unbounded (increased aux. array size)
- Avg - Input values w/ large number of elements, small range of values (i.e. large number of duplicates)

> Radix Sort:
---
- Best - Uniform distribution of input values, fixed number of digits/bits
- Worst - Input values have large number of digits/bits, or skewed distribution of input values (many empty buckets/parts)
- Avg - Input values w/ fixed number of digits/bits, e.g. all 32-bit or 64-bit integers