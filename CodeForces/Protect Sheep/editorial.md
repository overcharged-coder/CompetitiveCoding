# Protect Sheep Editorial
This problem has a really simple trick to it. If you think about it, the only way a wolf can access a sheep is that it's right beside it. Therefore, we just need to do a simple check on the original grid to see if any wolf is right next to a sheep, which determines whether or not the current 'meadow' is possible to save. If no wolf is right next to a sheep, and since we have no restrictions on the number of dogs we can place, we can just place a wolf on every empty square (that is always a valid combination and is much easier than figuring out any other combination).

## Time Complexity
There are three double-loops, which each have a time complexity of **O(rc)**. Therefore, the total time complexity is equal to **O(rc)**.