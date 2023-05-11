# CSCI-115 Term Project (SP 2023)
### Part 1 - Comparison of Sorting Algorithms
The goal here is to implement and analyze various sorting algorithms, and how they compare with their theoretical analyses. The following sorting algorithms are used:

+ Insertion sort
+ Selection sort
+ Bubble sort
+ Merge sort
+ Quicksort 
+ Heapsort
+ Counting sort
+ Radix sort

---
### Running Application
To use, navigate to home directory of the project and then compile with the following command:
> make

Then, navigate to desired sorting algorithm folder, and execute file. 

###### Executable Shortcuts

To ensure ease of use, here are the executable names per folder:

| Sort        | Filename                 |
| ----------- | ------------------------ |
| Insertion   | ./insertionSortMergeSort |
| Selection   | ./selectionSort          |
| Bubble      | ./heapSortBubbleSort     |
| Merge       | ./insertionSortMergeSort |
| Quick       | ./quickSort              |
| Heap        | ./heapSortBubbleSort     |
| Counting    | ./countSort              |
| Radix       | ./radixSort              |
* Note: add ".exe" to executables if using Windows 10/11

In order to remove executables, use the following command:
> make clean

Note that the experiments were done using Linux, which is the preferred operating system for running the algorithms. We noticed that Quick Sort and Couting Sort tend to hang after testing 10,000 elements specificially on Windows, but runs well on both Linux and MacOS.

---
### Directories
Within the home directory are folders for the sorting algorithms. Each folder contains two sorting algorithms, as contributed by a given group member. 

Data is specific to each algorithm, and is located within each sort's folder. There are six datasets, representative of n = 10, 100, 1000, 10000, 50000, and 100000. 

Within each data file are three datasets: best, worst, and average, respectively (in terms of time complexity). 

---
### Contributors
[George Larres](https://github.com/Nerdeee)

[Chris Mckie](https://github.com/chrismckie19)

[Mauricio Romero](https://github.com/MauRome55)

[Cody Valley](https://github.com/cdvcodes)

[Jason Whitlow](https://github.com/jaywhtlw45)



