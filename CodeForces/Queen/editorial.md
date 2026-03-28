# Queen Editorial
The main idea is that we can check the children of each node with c[i] = 1, and, if the children all have c[i] = 1, then that node passes for deletion. We can build an adjacency list (compared to the slow tree that the problem recommends). We can then check every node using this list, and then check the children. We can then push the ones that pass to a vector that we can print.

## Time Complexity
Sorting takes the most time complexity here, which is known to be **O(n log n)**. This is because the outer loop that runs n times and the inner one runs over children[i] isn't actually O(n^2) since the total number of child iterations across all nodes is at most n − 1, as each node has exactly one parent.