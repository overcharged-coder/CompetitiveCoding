# Exams Editorial
The basic idea of the problem is that the exams dates can be sorted by the late date, because they are written in the grade book on that date. Then, we can use a trick: if we traverse the dates, then we should go for the early date, if it's higher or equal to the previous date, else we can fall back to the later date, since it'll always be in chronological order.

## Time Complexity
The part that takes the most time is the sorting, which is N log N. The only other time-comsuming part that comes to mind is the traversal, but that is only N since that is a regular traversal. Therefore, the time complexity is **O(N log N)**.