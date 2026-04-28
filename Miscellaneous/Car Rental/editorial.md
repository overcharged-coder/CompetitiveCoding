# Car Rental Editorial
The basic idea of the problem is that we can track major events and change the car count from there. Notice that we only need the maximum number of cars needed at one time, because those cars can be reused in cases where we need a lesser number of maximum cars. We can track major events (when an interval starts and ends), and track the maximum number of cars needed at one time (increment one car when any interval starts, and decrememnt one when it ends). We also need to sort the events by event time to make sure they are in chronological order.

## Time Complexity
Here, sorting takes the most time, which is **O(N log N)**. The other two loops, reading the input and doing the car math, only take N, so sorting is the highest order.