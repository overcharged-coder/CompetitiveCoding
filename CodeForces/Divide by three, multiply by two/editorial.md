# Divide by three, multiply by two editorial
The interesting main idea here is that you can only perform a limited number of /3 operations on any number. As the sequence goes on, the potential[^1] naturally decreases. Therefore, if we get the potential[^1] of each number in an array and sort in (descending), we get very close to the solution. Now, the key observation to make is that in each group[^2], you can only conduct *2 operations. That means that in every group[^2] the numbers would naturally be ascending. So, we can derive that we need to sort descending based on the potential[^1], and then sort ascending in each group[^2]. 

## Time Complexity
The time complexity is **O(n log n)** because the most expending part is sorting. The other two loops only loop upto O(n), so they are not considered.


[^1]: The number of /3 operations you can do on any number
[^2]: The numbers with the same potential value are grouped together