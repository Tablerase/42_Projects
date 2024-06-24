# [Sorting Algorithm](https://www.programiz.com/dsa/sorting-algorithm)

## Quick Sort

Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. This can be done in-place, requiring small additional amounts of memory to perform the sorting.

![Quick Sort Demo](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6a/Sorting_quicksort_anim.gif/220px-Sorting_quicksort_anim.gif)
![Quick Sort example](https://upload.wikimedia.org/wikipedia/commons/thumb/a/af/Quicksort-diagram.svg/200px-Quicksort-diagram.svg.png)

![Quick Sort](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/01/QuickSort2.png)

Complexity:
- Best Case - $\omega(n \log n) $
- Average Case - $\theta(n \log n) $
- Worst Case - $O(n^2) $

Space Complexity: $O(\log n)$

## [Bubble Sort](https://www.programiz.com/dsa/bubble-sort)

Bubble sort is a sorting algorithm that compares two adjacent elements and swaps them until they are in the intended order.

Just like the movement of air bubbles in the water that rise up to the surface, each element of the array move to the end in each iteration. Therefore, it is called a bubble sort.

![Bubble Sort Demo](https://upload.wikimedia.org/wikipedia/commons/5/54/Sorting_bubblesort_anim.gif)
![Bubble Sort Demo](https://upload.wikimedia.org/wikipedia/commons/3/37/Bubble_sort_animation.gif)

![Bubble Sort](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/02/bubble-sort1.png)

## [Counting Sort](https://www.programiz.com/dsa/counting-sort)

Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array. The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.

![Counting Sort Demo](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20210219152324/ezgif.com-gif-maker2.gif)
![Counting Sort Demo](https://upload.wikimedia.org/wikipedia/commons/6/60/Counting_Sort_Animation.gif?20140818011201)

## [Merge Sort](https://www.programiz.com/dsa/merge-sort)

Merge sort is a sorting technique based on divide and conquer technique. With worst-case time complexity being $ Ο(\text{n log n}) $, it is one of the most respected algorithms.

Merge sort first divides the array into equal halves and then combines them in a sorted manner.

![Merge Sort Demo](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)
![Merge Sort Demo](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e6/Merge_sort_algorithm_diagram.svg/300px-Merge_sort_algorithm_diagram.svg.png)

Complexity: $O(n \log n)$

Space Complexity: $O(n)$

## [Insertion Sort](https://www.programiz.com/dsa/insertion-sort)

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

![Insertion Sort Demo](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
![Insertion Sort Demo](https://upload.wikimedia.org/wikipedia/commons/4/42/Insertion_sort.gif)

Complexity: 
- Best Case - $\omega(n) $
- Average Case - $\theta(n^2) $
- Worst Case - $O(n^2) $

Space Complexity: $O(1)$