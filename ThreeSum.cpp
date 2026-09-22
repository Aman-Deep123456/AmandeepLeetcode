//
//  ThreeSum.cpp
//  
//
//  Created by Amandeep on 22/09/26.
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    static int result[2]; // To store the result indices
    int left = 0;
    int right = numbersSize - 1;
    *returnSize=2;

    while (left < right) {
        int current_sum = numbers[left] + numbers[right];

        if (current_sum == target) {
            result[0] = left + 1; // Convert to 1-indexed
            result[1] = right + 1; // Convert to 1-indexed
            return result;
        } else if (current_sum < target) {
            left++; // Move left pointer to the right
        } else {
            right--; // Move right pointer to the left
        }
    }
    
    return NULL; // In case there is no solution, though the problem guarantees one
}
