#include <iostream>
#include <chrono>
#include <iomanip>
#include <unordered_map>

using namespace std;
using namespace chrono;

void genValid2Sum(int s[], int indexOfSol1, int indexOfSol2, int input, int size)
{
    //input = the number x that we are trying to find numbers to sum up to it
    //x = solution1, y = solution2
    int x = (input / 2) + 1;
    int y = input - x;
    //cout << x << " " << y;
    srand(time(0));

    cout << "2sum array: ";
    //indexOfSol1/indexOfSol2 = index(s) of where you want to put the solutions
    for (int i = 0; i < size; i++)
    {
        if (i == indexOfSol1)
        {
            s[indexOfSol1] = x;
        }
        else if (i == indexOfSol2)
        {
            s[indexOfSol2] = y;
        }
        else
        {
            s[i] = rand() % size;
        }
        //cout << s[i] << " ";
    }
}

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

// Map used for optimal solution. Index represents the complement value. Bool value represents whether the complement is known to exist in arr[]
// true = complement found in arr[i]
// false = complement not found in arr[i]
void initializeMap(bool map[], int n) {
    for(int i = 0; i < n; i++) {
        map[i] = false;
    }
}

void twoSumOptimal(int arr[], int n, int target, bool map[]) {
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        // Complement must be > 0 and complement must exist in map table
        if ((complement > 0) && (map[complement])) {
            //cout << "Two numbers that add up to " << target << " are " << arr[i] << " and " << complement << endl;
            return;
        }
        // arr[i] found and is marked in the map
        map[arr[i]] = true;
    }
    //cout << "No two numbers add up to " << target << endl;
}

int main() {
    cout << "Average case - brute force" << endl;
    //10 items - brute force
    int nums[10];
    int target = 5;
    int result[2] = { 0, 0 }; // initialize the result array to 0
        genValid2Sum(nums, 4, 5, target, 10);
    auto start = high_resolution_clock::now();
        twoSum(nums, 10, target, result);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for 10: " << duration.count() << " ns" << endl;

    //100 items - brute force
    int nums1[100];
    int target1 = 50;
    int result1[2] = { 0, 0 }; // initialize the result array to 0
    //auto start1 = high_resolution_clock::now();
        genValid2Sum(nums1, 49, 50, target1, 100);
    auto start1 = high_resolution_clock::now();
        twoSum(nums1, 50, target1, result1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "Execution time for 100: " << duration1.count() << " ns" << endl;

    //1000 items - brute force
    int nums2[1000];
    int target2 = 500;
    int result2[2] = { 0, 0 }; // initialize the result array to 0
    //auto start2 = high_resolution_clock::now();
        genValid2Sum(nums2, 499, 500, target2, 1000);
    auto start2 = high_resolution_clock::now();
    //    twoSum(nums2, 1000, target2, result2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "Execution time for 1000: " << duration2.count() << " ns" << endl;


    cout << endl;
    cout << endl;
    
    
    cout << "Average case - Optimal" << endl;
    //10 items - brute force
    int nums_op[10];
    bool map10[10];
    initializeMap(map10, 10);
    int target_op = 5;
        genValid2Sum(nums_op, 4, 5, target_op, 10);
    auto start_op = high_resolution_clock::now();
        twoSumOptimal(nums_op, 10, target_op, map10);
    auto stop_op = high_resolution_clock::now();
    auto duration_op = duration_cast<nanoseconds>(stop_op - start_op);
    cout << "Execution time for 10: " << duration_op.count() << " ns" << endl;

    //100 items - brute force
    int nums_op1[100];
    bool map100[100];
    initializeMap(map10, 10);
    int target_op1 = 57;
        genValid2Sum(nums_op1, 49, 50, target_op1, 100);
    auto start_op1 = high_resolution_clock::now();
        twoSumOptimal(nums_op1, 100, target_op1, map100);
    auto stop_op1 = high_resolution_clock::now();
    auto duration_op1 = duration_cast<nanoseconds>(stop_op1 - start_op1);
    cout << "Execution time for 100: " << duration_op1.count() << " ns" << endl;

    //1000 items - brute force
    int nums_op2[1000];
    bool map1000[1000];
    initializeMap(map10, 10);
    int target_op2 = 500;
        genValid2Sum(nums_op2, 449, 500, target_op2, 1000);
    auto start_op2 = high_resolution_clock::now();
        twoSumOptimal(nums_op2, 1000, target_op2, map1000);
    auto stop_op2 = high_resolution_clock::now();
    auto duration_op2 = duration_cast<nanoseconds>(stop_op2 - start_op2);
    cout << "Execution time for 1000: " << duration_op2.count() << " ns" << endl;
    
}
