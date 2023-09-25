0x1B. C - Sorting algorithms & Big O
Learning Objectives
1.At least four different sorting algorithms
2.What is the Big O notation, and how to evaluate the time complexity of an algorithm
3.How to select the best sorting algorithm for a given input
4.What is a stable sorting algorithm (https://youtu.be/EItdcGhSLf4?si=e_i8myGiTvPiX-6I)

Evaluating the time complexity of an algorithm or code is a bit complex. In general terms these steps are observed:
1.Identify the basic operations in the algorithm such as loops conditionals and arithmetic operations
2.Determine the Big O of each basic operation for example the Big O of a loop is O(n) if the loop iterates over the entire input set
3. Sum the Big O of all the basic operations in the algorithm.
4. Remove the constant factors
5. Identify the highest-order term.

Questions
What is the time complexity accessing the nth element in an unsorted Python 3 list?
The time complexity of accessing the nth element in an unsorted Python 3 list is O(1) on average and O(n) in the worst case. If the list is not hashed, or if the index is not found in the list, the time complexity of the nth element would be O(n). In the worst case, you will have to traverse the entire list to find the nth element.

What is the time complexity of a function containing a for loop with nested if - else conditions which each contain a for loop?
The time complexity of a function containing a for loop with nested if-else conditions which each contain a for loop will depend on the specific implementation of the function. If the inner for loops are always the same length, then the time complexity of the function will be O(n). However, if the inner loops can vary in length, then the time complexity will be O(n^2) or worse.

Question: What is the time complexity of a recursive function?
The time complexity of a recursive function can vary widely depending on the nature of the function and the input data. For example, the time complexity of the factorial function is O(n), as the number of recursive calls is directly proportional to the input size. On the other hand, some recursive functions can have exponential time complexity, such as the Fibonacci sequence, which has the time complexity of O(2^n)

What is the time complexity of a function with a for loop that increments its counter by a multiple of 2?
The time complexity of the function is O(log(n)). The loop in the function iterates until the value of i becomes greater than or equal to n, the terminating value. The value of i is initialized to 1 and is multiplied by 2 in each iteration of the loop. Therefore, the loop will execute log_2(n) times before the value of i becomes greater than or equal to n.

Tasks
0. Bubble sort
Write a function “void bubble_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Bubble sort algorithm. 
Requirement
You are expected to print the array after each time you swap two elements.

Algorithm
1. Start with the unsorted array of integers
2. Initialize variables i, j and check to 0 
3. Set the check to 0 and loop through the array from beginning to end, incrementing i by 1 each iteration.
4. Compare the elements at array[i] and array[i + 1]
5. If the element at array[i] is greater than the element at array[i + 1], swap the two elements.
6. If the elements were swapped set the flag to true
7. Repeat the steps 3 - 6 until the check flag returns as false.
8. Return the sorted array.


1. Insertion sort
Write a function “void insertion_sort_list(listint_t **list)” that sorts a doubly linked list of integers in ascending order using the insertion sort algorithm. 
Requirements
You are not allowed to modify the integer n of a node. You have to swap the nodes themselves
You are expected to print the list after each time you swap two elements.

Algorithm
1. Start with the unsorted doubly linked list of integers
2. Create a new sorted doubly linked list with a single node, which is the head of the original list.
3. Traverse the original list from the second node to the last node
4. For each node, traverse the sorted list from the last node to the first node
5. Compare the value of the current node with the value of the sorted node
6. If the value of the current node is less than the value of the sorted node, insert the current node before the sorted node.
7. If the value of the current node is greater than or equal to the value of the sorted node, insert the current node after the sorted node
8. Repeat steps 4-7 until all nodes in the original list have been inserted into the sorted list.
9. Update the head of the original list to point to the head of the sorted list.
10. Return the sorted doubly linked list.


2. Selection sort
Write a function “void selection_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Selection sort algorithm.
Requirement
You are expected to print the array after each time you swap two elements

Algorithm
1. Initialize five variables;
a. i to loop through the array
b. j to loop through the array for minimum index 
c. min_idx to store the index with minimum value
d. temp to store the temporal value for swapping
e. a to loop through the array in order to print the elements
2. Iterate over the array from the first element to the second-to-last element
3. For each element, find the smallest element in the unsorted portion of the array, starting from the current element to the end of the array.
4. If the minimum index is not the same as the starting value then there was a swap. Swap the current element with the smallest element found in step 3
5. Repeat steps 2-4 until the entire array is sorted in ascending order
6. Return the sorted array.


3. Quick sort
Write a function “void quick_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Quick sort algorithm.
Requirement
You must implement the Lomuto partition scheme
The pivot should always be the last element of the partition being sorted.
You are expected to print the array after each time you swap two elements


Algorithm
1. Start with the unsorted array of integers
a. Initialize the pivot_indx variable to track the pivot index
b. Initialize the i variable to -1
c. Initialize the j variable to 0
d. Initialize the a variable for printing
2. Choose a pivot element from the array. The pivot can be any element in the array, but it is often chosen as the last element in the array.
3. Iterate through the array with the j variable, where the value of the array at index j is less than the value of the array at the pivot index, increase the i variable by 1 and swap the value at the index of the i variable with the value at the index of the j variable
4. Swap the value of the element at the pivot index with the value of the element at the pivot index.
5. Create two subarrays. One subarray starting from the beginning of the array until one less than the new pivot index. Another subarray starting from one more than the new pivot index until the end
6. Recursively apply steps 2-3 to the subarrays until the entire array is sorted in ascending order.
7. Return the sorted array.


4. Shell sort - Knuth Sequence
Write a function “void shell_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequence.
Requirement
You must use the following sequence of intervals (the Knuth sequence);
n+1 = n*3 + 1 i.e. 1, 4, 13, 40, 121, …
You are expected to print the array each time you decrease the interval

Algorithm
1.Start with an unsorted array of integers
2.Choose the Knuth sequence as gap sequence.
a. Determine the gap value using the stopping criteria of size / 3. While increasing the gap value using the gap sequence, the final value should be less than size / 3 inorder to ensure feasibility.
3. Iterate over the gap sequence from the largest gap to the smallest gap as long as the gap is greater than 0.
4. For each gap, iterate over the array from the gap-th element to the last element
5. For each element in the subarray from the gap element, compare it with the element ‘gap’ positions before it
6. If the element gap positions before it is greater than the current element, swap the two 
elements
7. Repeat steps 4-6 until all elements in the array have been compared and swapped
8. Repeat steps 3-7 until the gap sequence is exhausted
9. Return the sorted array


5. Cocktail shaker sort
Write a function “void cocktail_sort_list(listint_t **list)” that sorts a doubly linked list of integers in ascending order using the Cocktail shaker sort algorithm.
Requirement
You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.
You’re expected to print the list after each time you swap the two elements

Algorithm
1. Start with an unsorted doubly linked list of integers
2. Set two pointers, one at the beginning of the list and one at the end of the list
3. Repeat the following steps until the two pointers meet in the middle
Iterate over the list from the beginning pointer to the end pointer
Compare each adjacent pair of elements
If the left element is greater than the right element, swap them
Move the beginning pointer one position to the right
Iterate over the list from the end pointer to the beginning pointer
Compare each adjacent pair of elements
If the left element is greater than the right element, swap them
Move the end pointer one position to the left


6. Counting sort
Write a function “void counting_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Counting sort algorithm.
Requirement
You can assume that the array will contain only numbers >= 0
You are allowed to use malloc and free for this task
You are expected to print your counting array once it is set up. This array is of size k+1 where k is the largest number in array

Algorithm
1. Find the maximum element in the array.
2. Create a count array of size ‘max_element + 1’ and initialize all elements to 0.
3. Traverse the array and count the number of occurrences of each element in the count array.
4. Traverse the count array and update each element with the sum of the previous elements.
5. Create a temporary array of size ‘size’ and initialize all elements to 0
6. Traverse the original array from the right to left and place each element in the temporary array at the index given by the count array.
7. Return the sorted array


7. Merge sort
Write a function “void merge_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Merge sort algorithm.
Requirements
1. You must implement the top-down merge sort algorithm. When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array i.e. {1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}. Sort the left array before the right array
2. You are allowed to use printf
3. You are allowed to use malloc and free only once(only one call)

Algorithm
1. If the size of the array is less than or equal to 1, then the array is already sorted.
2. Divide the array into two halves.
3. Recursively apply the merge sort algorithm to each half of the array until each half contains only one element.
4. Merge the two sorted halves by comparing the values of the left and values of the right until a single sorted array is generated.
5. Return the sorted array


8. Heap sort
Write a function “void heap_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Heap sort algorithm. 
Requirements
1. You must implement the sift-down heap sort algorithm
2. You are expected to print the array after each time you swap two elements.

Algorithm
0. Check the input values for integrity
1. Build a max heap from the array. Building the max heap considers the binary tree equation 2 * n + 1 for finding the index of the child nodes, where n is the index of the parent node. We build the heap from the parent node therefore inverting the equation.
2. Iterate through the array from the top and swap the root element (which is the maximum element in the heap) with the last element in the heap
3. Reduce the heap size by 1.
4. Call the sift-down function to sift the first element to its appropriate index in the list.
5. Repeat steps 2-4 until the heap size is 1
6. Return the sorted array


9. Radix sort
Write a function “void radix_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Radix sort algorithm.
Requirements
1. You must implement the LSD radix sort algorithm
2. You can assume that the array will contain only numbers “>= 0”
3. You are allowed to use malloc and free for this task
4. You’re expected to print the array each time you increase your “significant digit”

Algorithm
1. Find the maximum element in the array
2. Initialize a count array of size 10, initialized to 0
3. Iterate over the array and count the number of occurrences of each digit in the count array.
4. Modify the count array to contain the cumulative sum of the counts.
5. Create a temporary array of the same size as the input array.
6. Iterate over the input array from the least significant digit to the most significant digit.
7. Use the count array to determine the correct position of the current element in the temporary array.
8. Decrement the count of the current digit in the count array
9. Copy the elements from the temporary array back to the input array
10. Repeat steps 7-10 for each digit in the input elements.
11. Return the sorted array


10. Bitonic sort
Write a function “void bitonic_sort(int *array, size_t size)” that sorts an array of integers in ascending order using the Bitonic sort algorithm
Requirements
1. You can assume that size will be equal to 2^k, where k >= 0 (when “array” is not “NULL” …)
2. You are allowed to use printf
3. You’re expected to print the array each time you swap two elements

Algorithm
1. Check if the size of the array is a power of 2. If not, pad the array with 0s to the nearest power of 2.
2. Call the bitonic_sort_recursive function on the array with ascending order and the size of the array
a. If the size of the array is 1, return
b. Divide the array into two halves
c. Recursively call the bitonic_sort_recursive function on the first half of the array in ascending order.
d. Recursively call the bitonic_sort_recursive function on the second half of the array with descending order
e. Call the bitonic_merge function on the entire array with the specified direction
3. The bitonic_merge function works in this manner
a. If the size of the array is 1, return.
b. divide the array into two halves
c. reverse the second half of the array if the specified direction is descending
d. iterate over the two halves of the array in parallel and compare the corresponding elements.
e. Swap the elements if they are in the wrong order according to the specified direction.
f. Recursively call the bitonic_merge function on the first half of the array with the specified direction
g. Recursively call the bitonic_merge function on the second half of the array with the specified direction
4. Return the sorted array


11. Quick Sort - Hoare Partition scheme
Write a function “void quick_sort_hoare(int *array, size_t size)” that sorts an array of integers in ascending order using the quick sort algorithm.
Requirements
1. You must implement the Hoare partition scheme
2. The pivot should always be the last element of the partition being sorted
3. You’re expected to print the array after each time you swap two elements

Algorithm
1. Choose a pivot element from the array
2. Partition the array into two sub-arrays: one with elements less than or equal to the pivot, and one with elements greater than the pivot.
3. Recursively apply the quick sort algorithm to each sub-array
4. Return the sorted array


12. Dealer
Write a function “sort_deck(deck_node_t **deck” that sorts a deck of cards.
Requirements
1. You are allowed to use the C standard library function qsort

