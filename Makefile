make:
	g++ -O2 countSortRadixSort/countSort/countSort.cpp -o countSortRadixSort/countSort/countSort
	g++ -O2 countSortRadixSort/radixSort/radixSort.cpp -o countSortRadixSort/radixSort/radixSort
	g++ -O2 heapSortBubbleSort/heapSortBubbleSort.cpp -o heapSortBubbleSort/heapSortBubbleSort
	g++ -O2 insertionSortMergeSort/insertionSortMergeSort.cpp -o insertionSortMergeSort/insertionSortMergeSort
	g++ -O2 quickSortSelectionSort/quickSort.cpp -o quickSortSelectionSort/quickSort
	g++ -O2 quickSortSelectionSort/selectionSort.cpp -o quickSortSelectionSort/selectionSort

clean: 
	rm insertionSortMergeSort/insertionSortMergeSort
	rm heapSortBubbleSort/heapSortBubbleSort
	rm quickSortSelectionSort/quickSort
	rm quickSortSelectionSort/selectionSort
	rm countSortRadixSort/countSort/countSort
	rm countSortRadixSort/radixSort/radixSort




