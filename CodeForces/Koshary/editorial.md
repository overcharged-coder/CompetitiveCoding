# Koshary Editorial
The basic idea of the problem is that we have only two cases where Yousef can get the Koshary: he uses the short step on x/y and gets there or he doesn't need to use the short step and can get there easily. We can check whether he needs the short step to by checking if mod % 2 = 0 and y mod 2 = 0, and if these equations aren't true, then we can check if he can get there with the short step.

## Time Complexity
Each case is done easily in constant time, just a few if conditions, so the time complexity is **O(T)**.