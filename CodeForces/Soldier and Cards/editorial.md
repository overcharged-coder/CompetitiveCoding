# Soldier and Cards Editorial
The problem is easy if you notice that the contraints for the variables given are unusually low. Notice that the total number of cards is only ten, meaning the way to go with this is brute force. We can simply use a counter to adjust the number of turns we try before we give up and print -1, which let's us try with a few numbers and then perfect a single one. Since we get a lot of operations in 2 seconds (2 * 10^8 roughly), we can use 10,000 with no difficulty.

## Time Complexity
The highest component here is obviously the while loop, which runs 10,000 times at maximum. Therefore, the time complexity is **O(1)**.