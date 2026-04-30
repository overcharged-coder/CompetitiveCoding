# Party Monster Editorial
The basic idea of the problem is that if we have the same number of ')'s and '('s we always can make a regular bracket sequence. The substring constraint doesn't matter: you can even take the whole string as a substring of itself or only leave one element behind if that's not possible. Therefore, the question is simply asking if you can re-order the string's characters in such a way we get a regular bracket sequence, and a regular bracket sequence is only possible when we have the same number of ')'s and '('s.

## Time Complexity
Every test case is N, since we traverse the string once to ocunt the parenthetical values. The trick is that N can't be maximum per test case (the sum of N is capped to 2 * 10^5), so the time complexity is **O(T + N)**.