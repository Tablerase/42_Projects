# Searching

## [Binary Search](https://www.programiz.com/dsa/binary-search)

In computer science, binary search, also known as **half-interval search**, logarithmic search, or **binary chop**, is a search algorithm that finds the position of a target value within a sorted array.

Binary search **compares the target value** to the **middle element of the array**. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and **repeating this until the target value is found**. 

If the search ends with the remaining half being empty, the target is not in the array. 

![Binary Search](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c1/Binary-search-work.gif/220px-Binary-search-work.gif)
![Binary Search](https://upload.wikimedia.org/wikipedia/commons/8/83/Binary_Search_Depiction.svg)

Complexity:
- Best Case - $\omega(1) $
- Average Case - $\theta(\log n) $
- Worst Case - $O(\log n) $

Space Complexity: $O(1)$