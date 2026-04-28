# Fence Planning Editorial
The basic idea of the problem is that we can run a DFS on a cow to create a connection to all its neighbors, and continue until we can complete the whole network. Once we have a moo network, we can find its perimeter by subtracting the minimum x coordinate from the maximum x coordinate and adding the maximum y coordinate minus the minimum y coordinate. To make the DFS algorithm more efficient, instead of scanning the moo connections for each cow repeatedly, we can create an adjacency list to store moo connections. We also need a visited vector to prevent infinity loops while identifying moo networks.

## Time Complexity
The part that takes the most time is the DFS. The time complexity is **O(N^2)**, which only passes because N is so small ()