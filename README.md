# Sorting algorithms
-----
💻
- Its an algorithm that puts elements of a list into an order 
- sorting is important for optimizing efficiency of other algorithms e.g. `search` and `merge`
- sorting algorithm output must satisfy
	1. Output is monotonic (no smaller/larger than the previous element according to the sorting)
	2. Output is a permutation (maintains all original elements)
- sorting algorithms classified by:
- __`computational complexity`__:
	-  `Best` , `worst` and `average case `. typical serial sorting algorithm , good behaviour is `O(n log n)` parallel sort `O(log^2 n)`  and bad behavior `O(n^2)` 
- __`memory`__
- __`recursion`__

#### __`Stable sort algorithm`__ 
- sort equal element in the same order they appear in the input. i.e. if one comes before the other in the input, it will come before the other in the output.
- e.g sorting a list using a primary and secondary key 🔑. 

#### __`Popular sorting algorithms`__ 😉
- for smaller data set, __`insertion sort`__ is widely used 
- For larger dataset __`heap sort`__ , __`merge sort`__, __`quick sort`__ are used
- Hybrid algorithm - combining two or more other algorithms that solves the same problem.
- Efficient implementations generally use a `hybrid algorithm` combining an asymptotically efficient algorithm for the overall sort with insertion sort for small lists at the bottom of a recursion.

#### __`Simple sorts`__
1. __`insertion sort`__
2. __`selection sort`__
- `Insertion sort` is generally faster than `selection sort` due to fewer comparison and good performance on almost-sorted-data.
- `Selection sort` uses fewer writes and thus used when writing performance is a limiting factor.
__`1. Insertion sort`__
	![in](https://upload.wikimedia.org/wikipedia/commons/4/42/Insertion_sort.gif)
- simple sorting algorithm that is relatively efficient for small list and mostly sorted lists oftenly used as part of more sophisticated algorithms.
- works by taking elements in a list one by one and inserting them into their correct position into a new sorted list
- It is  quite expensive requiring shifting elements over one by one.
- It __iterates__ , consuming one input element each repetition  and grows a sorted output list., At each iteration , insertion sort removes one element from the input data , find the location it belongs within the sorted list , and inserts it there. It repeats until no input elements remain.
- __sorting__ typically done in place, by iterating up the array , growing the sorted list behind it. At each array position, it checks if the value there against the largest value in the sorted list (next to it) . If larger, it leaves the element in place and moves to the next. If smaller, it finds its correct position within the sorted lists, shifts all the larger values up to make a space , and inserts into that correct position. 
-  resulting array after k iterations has the property where the first k+1 entries are sorted  ( +1 because first entry is skipped). 
  __`best case`__: array that is already sorted , has a linear running time __`O(n)`__ 
  __`worst case`__  : Array sorted in reverse order, quadratic running time __`O(n^2)`__ 
  __`Average case `__ : Quadratic 
  - These makes it impractical for sorting large arrays but faster for smaller arrays even than quick sort.
```python
"""🐍
Simple insertion sort implementation 😉
big O: O(n^2) quadratic
"""
def insertion(arr):
	for i in range(1, len(arr)):
		temp = arr[i]
		j = i - 1
		while j >=0 and arr[j] > temp:
			arr[j + 1] = arr[j]
			arr[j] = temp
			j -= 1
			arr[j + 1] = temp
	return arr

arr = [10, 7, 5, 4, 1]
print("Original array: ", arr)
print(insertion(arr))
```
[insertion_sort.py]

__`2. Selection sort`__
		![](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)
- In place comparison sort with a quadratic (`O(n^2)`) time complexity
- Inefficient for large list and performs worse than insertion sort
- It finds the minimum value, swaps it with the value in the first position, and repeats these steps for the remainder of the list.
- It does no more than n swaps and thus useful where swapping is expensive.
- It divides an input size into two parts: a sorted sublist of item built from lefft to right and a sublist of the remaining unsorted items 
- Initially the sorted sublist is empty and the unsorted sublist is the entire input list
- The algorithm proceeds by finding the smallest/largest element in the unsorted sublist and exchanging it with the outmost element (putting it in sorted order), and moving the sublist boundaries one element to the right.
```python
"""🐍
selection sort implementation
big O: O(n^2) (quadratic)
"""
def selection(arr):
while arr != []:
	min_ = 0
	for i in range(1, len(arr)):
		if arr[i] < arr[min_]
			min_ = i
	sub.append(arr.pop(min_) if len(arr) > 0 else arr[0])
return sub

if __name__ == "__main__":
		arr = [int(i) for i in input().split()]
		print("original arr:", arr)
		print(selection(arr))
	
```
[selection_sort.py]
#### __`Efficient sorts`__
__`1. Merge sort`__ 
	![merge sort](https://upload.wikimedia.org/wikipedia/commons/thumb/c/cc/Merge-sort-example-300px.gif/220px-Merge-sort-example-300px.gif)
- Takes advantage of ease sorting already sorted lists into a new sorted list.
- It start by comparing every two elements and swapping them if the first should come after the second
- It then merges each of the resulting lists into two list of four then merges those lists of four , and so on; until at last two lists are merged into the final sorted list.
1. Divide the unsorted list into n sublists, each containing one element
2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

- __`worstcase`__: `O(n log n)`
- __`space complexity`__: `O(n)`
```python
"""🐍
Merge sort implementation
big O: O(n log n)
space complexity O(n)
"""
def merge_sort(arr):
"""
pass in an unsorted arrar
returns a sorted array 
"""
	if len(arr) > 1:
		mid = len(arr) // 2 # calculate midpoint of array
		left = arr[:mid]
		right = arr[mid:]
		merge_sort(left) # recursively call merge sort on both left and right
		merge_sort(right)
		i = j= k = 0 # pointers, i for left half, j for right half and k for main
		while i < len(left) and j < len(right):
			if left[i] < right[j]:
				arr[k] = left[i]
				i += 1
			else:
				arr[k] = right[j]
				j += 1
			k += 1
		while i < len(left): # add any remaining left element to aray
			arr[k] = left[i]
			i += 1
			k += 1
		while j < len(right): # add any remaining element to right 
			arr[k] = right[j]
			j+=1
			k+=1
	return arr
if __name__ == "__main__":
	arr = [int(i) for i in input().split()]
	print("original array is: ", arr)
	print("merge sort array: ", merge_sort(arr))
		
```
[merge_sort.py]

__`2. Heap sort`__
![heap sort](https://upload.wikimedia.org/wikipedia/commons/1/1b/Sorting_heapsort_anim.gif)
- An efficient version of selection sort .
- Determines the largest (smallest) element of the list and place it at the end or beginning of the list and the continuing with the rest of the list , but accomplishes this task efficiently using a __heap__.
- Once the data list has been made into a heap, the root node is guaranteed to be the largest or smallest element . When it is removed and placed at the end of the list , the heap is rearranged so the largest element remaining moves to the root. Using the heap, finding largest element takes `O(log n)` instead of `O(n)` as in selection sort.
- Time complexity `O(n log n)`
----
### Heap
if a node is at index `i`
left child is at `2 * i`
right child `2 * i + 1`
parent  `i / 2`
full binary tree : 2 ^ (h + 1)
max heap - complete binary tree with the root greater than or equal to its descendants
min heap : complete binary tree with the root smaller than or equal to all its descendants

----
__`3. Quicksort`__
![quick sort](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6a/Sorting_quicksort_anim.gif/220px-Sorting_quicksort_anim.gif)
- Its a divide and conquer algorithm that relies on partition operation.
- To partition an array a element called a _pivot_ is selected and all  elements smaller than the pivot are moved before it and all greater elements are moved after it.
- This can be done efficiently in linear time and in-place .
- The lesser and greater sub lists are then recursively sorted.
This yields __average time complexity:__  __`O(n log n)`__
__worst case performance:__ __`O(n ^ 2)`__ (rare)
- The most complex issue is choosing a pivot point, good pivot points yields `O(n log n)` while bad yields `O(n^2)`
```python
"""🐍
	Quick sort implementation
	worst case: O(n ^ 2)
	Average case: O(n log n)
"""
def quicksort(arr)
"""
function to sort an array using quick sort
"""
mid =  len(arr) // 2
if len(arr) < 2: 
	return arr
else:
	pivot = arr[mid]
	left = [x for x in arr if x < pivot]
	right = [x for x in arr if x > pivot]
	middle = [x for x in arr if x == pivot]
	return quicksort(left) + middle + quicksort(right)

if __name__ == "__main__"
arr = [int(i) for i in input().split()]
print("Original arr: ", arr)
print("Array after quick sort: ", quicksort(arr))
```
[quicksort.py]

__`4. Bubble sort`__
![Bubble sort](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)
- It is a simple sorting algorithm.
- It starts at the beginning of the data set , compares the first two elements , and if the first is greater than the second, it swaps them,
- It continues doing this for each pair of adjacent elements to the end of the data set
- It then starts again with the first two elements , repeating  until no swap have occurred on the last pass
- __Average case:  `O(n ^ 2)`__
- __Worst case: `O(n ^ 2)`__
- Hence rarely used for large unordered data sets
```python
"""
bubble sort array implementation
average case : O(n ^ 2)
worst case: O(n ^ 2)
best case: O(n)
"""
def bubblesort(arr):
	"""
	sort array by comparing adjacent 2 elements 
	"""
	for i in range(len(arr)):
		for j in range(len(arr) - 1):
			if arr[j] > arr[j + 1]:
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
	return arr

if __main__ == "__name__":
	arr = [int(i) for i in input().split()]
	print("original array: ", arr)
	print("Array after bubble sort: ", bubblesort(arr))
```
[bubblesort.py]
