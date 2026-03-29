# A Simple Sequence Editorial
The main idea to realize in the problem is that if we print the numbers backwards (for example, for n = 3 we have 3 2 1), the sequence will always suffice. This is because all the modulus operations (such as 3 % 2 or 2 % 1) will **always** be equal to one. Therefore, we just need to print the permutation **n, n-1, n-2, n-3...,3, 2, 1**.

## Time Complexity
The time complexity is **O(nt)**, since we just have to print the sequence (of **n** elements) **t** times.