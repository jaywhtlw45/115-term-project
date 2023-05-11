#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;


//this function creates the data set
void placeNumbers(int arr[], int size, int num1, int index1, int num2, int index2, int target) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate random elements for the array
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10; // Generate random number between 0 and 9
    }

    // Check if indexes are within bounds
    if (index1 >= size || index2 >= size) {
        cout << "Error: Index out of bounds!" << endl;
        return;
    }
    // Place the two numbers at their respective indexes
    arr[index1] = num1;
    arr[index2] = num2;
}

//brute force function
void twoSum(int nums[], int size, int target, int result[]) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = nums[i];
                result[1] = nums[j];
                return;
            }
        }
    }
}

//initializes "map" that will be used for the optimal function
void initializeMap(bool map[], int n) {
    for (int i = 0; i < n; i++) {
        map[i] = false;
    }
}

//optimal twoSum function
void twoSumOptimal(int arr[], int n, int target, bool map[]) {
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];

        if ((complement > 0) && (map[complement])) {
            return;
        }
        map[arr[i]] = true;
    }
}

int main() {
    cout << "Best case - brute force" << endl;
    //10 items - brute force
    int nums_b[10];
    int target_b = 3;
    int result_b[2] = { 0, 0 }; // initialize the result array to 0
    //genValid2Sum(nums, 4, 5, target, 10);
        placeNumbers(nums_b, 10, 1, 0, 2, 1, target_b);
    auto start_b = high_resolution_clock::now();
        twoSum(nums_b, 10, target_b, result_b);
    auto stop_b = high_resolution_clock::now();
    auto duration_b = duration_cast<nanoseconds>(stop_b - start_b);
    cout << "Execution time for 10: " << duration_b.count() << " ns" << endl;

    //100 items - brute force
    int nums1_b[100];
    int target1_b = 3;
    int result1_b[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums1_b, 100, 1, 0, 2, 1, target1_b);
    auto start1_b = high_resolution_clock::now();
        twoSum(nums1_b, 100, target1_b, result1_b);
    auto stop1_b = high_resolution_clock::now();
    auto duration1_b = duration_cast<nanoseconds>(stop1_b - start1_b);
    cout << "Execution time for 100: " << duration1_b.count() << " ns" << endl;

    //1000 items - brute force
    int nums2_b[1000];
    int target2_b = 3;
    int result2_b[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums2_b, 1000, 1, 0, 2, 1, target2_b);
    auto start2_b = high_resolution_clock::now();
        twoSum(nums2_b, 1000, target2_b, result2_b);
    auto stop2_b = high_resolution_clock::now();
    auto duration2_b = duration_cast<nanoseconds>(stop2_b - start2_b);
    cout << "Execution time for 1000: " << duration2_b.count() << " ns" << endl;

    //10000 items - brute force
    int nums3_b[10000];
    int target3_b = 3;
    int result3_b[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums3_b, 10000, 1, 0, 2, 1, target3_b);
    auto start3_b = high_resolution_clock::now();
        twoSum(nums3_b, 10000, target3_b, result3_b);
    auto stop3_b = high_resolution_clock::now();
    auto duration3_b = duration_cast<nanoseconds>(stop3_b - start3_b);
    cout << "Execution time for 10000: " << duration3_b.count() << " ns" << endl;

    //50000 items - brute force
    int nums4_b[50000];
    int target4_b = 3;
    int result4_b[2] = { 0, 0 }; // initialize the result array to 0;
        placeNumbers(nums4_b, 50000, 1, 0, 2, 1, target4_b);
    auto start4_b = high_resolution_clock::now();
        twoSum(nums4_b, 50000, target4_b, result4_b);
    auto stop4_b = high_resolution_clock::now();
    auto duration4_b = duration_cast<nanoseconds>(stop4_b - start4_b);
    cout << "Execution time for 50000: " << duration4_b.count() << " ns" << endl;

    cout << endl;
    cout << endl;



    cout << "Best case - Optimal" << endl;
    //10 items - optimal
    int nums_opb[10];
    bool map_b[10];
    int target_opb = 3;
        placeNumbers(nums_opb, 10, 1, 0, 2, 1, target_opb);
        initializeMap(map_b, 10);
    auto start_opb = high_resolution_clock::now();
        twoSumOptimal(nums_opb, 10, target_opb, map_b);
    auto stop_opb = high_resolution_clock::now();
    auto duration_opb = duration_cast<nanoseconds>(stop_opb - start_opb);
    cout << "Execution time for 10: " << duration_opb.count() << " ns" << endl;

    //100 items - brute force
    int nums1_opb[100];
    bool map_b1[100];
    int target1_opb = 3;
    int result1_opb[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums1_opb, 100, 1, 0, 2, 1, target1_opb);
        initializeMap(map_b1, 100);
    auto start1_opb = high_resolution_clock::now();
        twoSumOptimal(nums1_opb, 100, target1_opb, map_b1);
    auto stop1_opb = high_resolution_clock::now();
    auto duration1_opb = duration_cast<nanoseconds>(stop1_opb - start1_opb);
    cout << "Execution time for 100: " << duration1_opb.count() << " ns" << endl;

    //1000 items - brute force
    int nums2_opb[1000];
    bool map_b2[1000];
    int target2_opb = 3;
    int result2_opb[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums2_opb, 1000, 1, 0, 2, 1, target2_opb);
        initializeMap(map_b2, 1000);
    auto start2_opb = high_resolution_clock::now();
        twoSumOptimal(nums2_opb, 1000, target2_opb, map_b2);
    auto stop2_opb = high_resolution_clock::now();
    auto duration2_opb = duration_cast<nanoseconds>(stop2_opb - start2_opb);
    cout << "Execution time for 1000: " << duration2_opb.count() << " ns" << endl;

    //10000 items - brute force
    int nums3_opb[10000];
    bool map_b3[10000];
    int target3_opb = 3;
    int result3_opb[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums3_opb, 10000, 1, 0, 2, 1, target3_opb);
        initializeMap(map_b3, 10000);
    auto start3_opb = high_resolution_clock::now();
        twoSumOptimal(nums3_opb, 10000, target3_opb, map_b3);
    auto stop3_opb = high_resolution_clock::now();
    auto duration3_opb = duration_cast<nanoseconds>(stop3_opb - start3_opb);
    cout << "Execution time for 10000: " << duration3_opb.count() << " ns" << endl;

    //50000 items - brute force
    int nums4_opb[50000];
    bool map_b4[50000];
    int target4_opb = 3;
    int result4_opb[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums4_opb, 50000, 1, 0, 2, 1, target4_opb);
        initializeMap(map_b4, 50000);
    auto start4_opb = high_resolution_clock::now();
        twoSumOptimal(nums4_opb, 50000, target4_opb, map_b4);
    auto stop4_opb = high_resolution_clock::now();
    auto duration4_opb = duration_cast<nanoseconds>(stop4_opb - start4_opb);
    cout << "Execution time for 50000: " << duration4_opb.count() << " ns" << endl;


    cout << endl;
    cout << endl;


    cout << "Worst case - brute force" << endl;
    //10 items - brute force
    int nums_w[10];
    int target_w = 212;
    int result_w[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums_w, 10, 10, 9, 11, 8, target_w);
    auto start_w = high_resolution_clock::now();
        twoSum(nums_w, 10, target_w, result_w);
    auto stop_w = high_resolution_clock::now();
    auto duration_w = duration_cast<nanoseconds>(stop_w - start_w);
    cout << "Execution time for 10: " << duration_w.count() << " ns" << endl;

    //100 items - brute force
    int nums1_w[100];
    int target1_w = 500;
    int result1_w[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums1_w, 100, 200, 99, 200, 98, target1_w);
    auto start1_w = high_resolution_clock::now();
        twoSum(nums1_w, 100, target1_w, result1_w);
    auto stop1_w = high_resolution_clock::now();
    auto duration1_w = duration_cast<nanoseconds>(stop1_w - start1_w);
    cout << "Execution time for 100: " << duration1_w.count() << " ns" << endl;

    //1000 items - brute force
    int nums2_w[1000];
    int target2_w = 3000;
    int result2_w[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums2_w, 1000, 999, 999, 998, 998, target2_w);
    auto start2_w = high_resolution_clock::now();
        twoSum(nums2_w, 1000, target2_w, result2_w);
    auto stop2_w = high_resolution_clock::now();
    auto duration2_w = duration_cast<nanoseconds>(stop2_w - start2_w);
    cout << "Execution time for 1000: " << duration2_w.count() << " ns" << endl;

    //10000 items - brute force
    int nums3_w[10000];
    int target3_w = 30000;
    int result3_w[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums3_w, 10000, 9999, 9999, 9998, 9998, target3_w);
    auto start3_w = high_resolution_clock::now();
        twoSum(nums3_w, 10000, target3_w, result3_w);
    auto stop3_w = high_resolution_clock::now();
    auto duration3_w = duration_cast<nanoseconds>(stop3_w - start3_w);
    cout << "Execution time for 10000: " << duration3_w.count() << " ns" << endl;

    //50000 items - brute force
    int nums4_w[50000];
    int target4_w = 150000;
    int result4_w[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums4_w, 50000, 49999, 49999, 49998, 49998, target4_w);
    auto start4_w = high_resolution_clock::now();
        twoSum(nums4_w, 50000, target4_w, result4_w);
    auto stop4_w = high_resolution_clock::now();
    auto duration4_w = duration_cast<nanoseconds>(stop4_w - start4_w);
    cout << "Execution time for 50000: " << duration4_w.count() << " ns" << endl;

    
    cout << endl;
    cout << endl;

    
    cout << "Worst case - Optimal" << endl;
    //10 items - optimal
    int nums_opw[10];
    bool map_w[10];
    int target_opw = 25;
        placeNumbers(nums_opw, 10, 9, 9, 8, 8, target_opw);
    auto start_opw = high_resolution_clock::now();
        initializeMap(map_w, 10);
        twoSumOptimal(nums_opw, 10, target_opw, map_w);
    auto stop_opw = high_resolution_clock::now();
    auto duration_opw = duration_cast<nanoseconds>(stop_opw - start_opw);
    cout << "Execution time for 10: " << duration_opw.count() << " ns" << endl;

    //100 items - brute force
    int nums1_opw[100];
    bool map_w1[100];
    int target1_opw = 500;
    int result1_opw[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums1_opw, 100, 200, 99, 200, 98, target1_opw);
    auto start1_opw = high_resolution_clock::now();
        initializeMap(map_w1, 100);
        twoSumOptimal(nums1_opw, 100, target1_opw, map_w1);
    auto stop1_opw = high_resolution_clock::now();
    auto duration1_opw = duration_cast<nanoseconds>(stop1_opw - start1_opw);
    cout << "Execution time for 100: " << duration1_opw.count() << " ns" << endl;

    //1000 items - brute force
    int nums2_opw[1000];
    bool map_w2[1000];
    int target2_opw = 3000;
    int result2_opw[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums2_opw, 1000, 999, 999, 998, 998, target2_opw);
    auto start2_opw = high_resolution_clock::now();
        initializeMap(map_w2, 1000);
        twoSumOptimal(nums2_opw, 1000, target2_opw, map_w2);
    auto stop2_opw = high_resolution_clock::now();
    auto duration2_opw = duration_cast<nanoseconds>(stop2_opw - start2_opw);
    cout << "Execution time for 1000: " << duration2_opw.count() << " ns" << endl;

    //10000 items - brute force
    int nums3_opw[10000];
    bool map_w3[10000];
    int target3_opw = 30000;
    int result3_opw[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums3_opw, 10000, 9999, 9999, 9998, 9998, target3_opw);
    auto start3_opw = high_resolution_clock::now();
        initializeMap(map_w3, 10000);
        twoSumOptimal(nums3_opw, 10000, target3_opw, map_w3);
    auto stop3_opw = high_resolution_clock::now();
    auto duration3_opw = duration_cast<nanoseconds>(stop3_opw - start3_opw);
    cout << "Execution time for 10000: " << duration3_opw.count() << " ns" << endl;

    //50000 items - brute force
    int nums4_opw[50000];
    bool map_w4[50000];
    int target4_opw = 150000;
    int result4_opw[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums4_opw, 50000, 49999, 49999, 49998, 49998, target4_opw);
    auto start4_opw = high_resolution_clock::now();
        initializeMap(map_w4, 50000);
        twoSumOptimal(nums4_opw, 50000, target4_opw, map_w4);
    auto stop4_opw = high_resolution_clock::now();
    auto duration4_opw = duration_cast<nanoseconds>(stop4_opw - start4_opw);
    cout << "Execution time for 50000: " << duration4_opw.count() << " ns" << endl;

    cout << endl;
    cout << endl;
    

    cout << "Average case - brute force" << endl;
    //10 items - brute force
    int nums[10];
    int target = 5;
    int result[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums, 10, 2, 4, 3, 5, target);
    auto start = high_resolution_clock::now();
        twoSum(nums, 10, target, result);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for 10: " << duration.count() << " ns" << endl;

    //100 items - brute force
    int nums1[100];
    int target1 = 49;
    int result1[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums1, 100, 25, 25, 24, 26, target1);
    auto start1 = high_resolution_clock::now();
        twoSum(nums1, 100, target1, result1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "Execution time for 100: " << duration1.count() << " ns" << endl;

    //1000 items - brute force
    int nums2[1000];
    int target2 = 500;
    int result2[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums2, 1000, 249, 250, 251, 249, target2);
    auto start2 = high_resolution_clock::now();
        twoSum(nums2, 1000, target2, result2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "Execution time for 1000: " << duration2.count() << " ns" << endl;

    //10000 items - brute force
    int nums3[10000];
    int target3 = 5000;
    int result3[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums3, 10000, 2499, 2499, 2501, 2501, target3);
    auto start3 = high_resolution_clock::now();
        twoSum(nums3, 10000, target3, result3);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
    cout << "Execution time for 10000: " << duration3.count() << " ns" << endl;

    //50000 items - brute force
    int nums4[50000];
    int target4 = 25000;
    int result4[2] = { 0, 0 }; // initialize the result array to 0
        placeNumbers(nums4, 50000,12499, 12499, 12501, 12501, target3);
    auto start4 = high_resolution_clock::now();
        twoSum(nums4, 50000, target4, result4);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<nanoseconds>(stop4 - start4);
    cout << "Execution time for 50000: " << duration4.count() << " ns" << endl;

    
    cout << endl;
    cout << endl;


    cout << "Average case - Optimal" << endl;
    //10 items - optimal
    int nums_op[10];
    bool map[10];
    int target_op = 5;
        placeNumbers(nums_op, 10, 2, 4, 3, 5, target_op);
    auto start_op = high_resolution_clock::now();
        initializeMap(map, 10);
        twoSumOptimal(nums_op, 10, target_op, map);
    auto stop_op = high_resolution_clock::now();
    auto duration_op = duration_cast<nanoseconds>(stop_op - start_op);
    cout << "Execution time for 10: " << duration_op.count() << " ns" << endl;

    //100 items - optimal
    int nums_op1[100];
    bool map1[100];
    int target_op1 = 49;
        placeNumbers(nums1, 100, 25, 25, 24, 26, target1);
    auto start_op1 = high_resolution_clock::now();
        initializeMap(map1, 100);
        twoSumOptimal(nums_op1, 100, target_op1, map1);
    auto stop_op1 = high_resolution_clock::now();
    auto duration_op1 = duration_cast<nanoseconds>(stop_op1 - start_op1);
    cout << "Execution time for 100: " << duration_op1.count() << " ns" << endl;

    //1000 items - optimal
    int nums_op2[1000];
    bool map2[1000];
    int target_op2 = 500;
        placeNumbers(nums_op2, 1000, 249, 249, 251, 251, target_op2);
    auto start_op2 = high_resolution_clock::now();
        initializeMap(map2, 1000);
        twoSumOptimal(nums_op2, 1000, target_op2, map2);
    auto stop_op2 = high_resolution_clock::now();
    auto duration_op2 = duration_cast<nanoseconds>(stop_op2 - start_op2);
    cout << "Execution time for 1000: " << duration_op2.count() << " ns" << endl;

    //10000 items - optimal
    int nums_op3[10000];
    bool map3[10000];
    int target_op3 = 5000;
        placeNumbers(nums_op3, 10000, 2499, 2499, 2501, 2501, target_op3);
    auto start_op3 = high_resolution_clock::now();
        initializeMap(map3, 10000);
        twoSumOptimal(nums_op3, 10000, target_op3, map3);
    auto stop_op3 = high_resolution_clock::now();
    auto duration_op3 = duration_cast<nanoseconds>(stop_op3 - start_op3);
    cout << "Execution time for 10000: " << duration_op3.count() << " ns" << endl;

    //50000 items - optimal
    int nums_op4[50000];
    bool map4[50000];
    int target_op4 = 25000;
        placeNumbers(nums_op4, 50000,12499, 12499, 12501, 12501, target_op4);
    auto start_op4 = high_resolution_clock::now();
        initializeMap(map4, 50000);
        twoSumOptimal(nums_op4, 50000, target_op4, map4);
    auto stop_op4 = high_resolution_clock::now();
    auto duration_op4 = duration_cast<nanoseconds>(stop_op4 - start_op4);
    cout << "Execution time for 10000: " << duration_op4.count() << " ns" << endl;


}
