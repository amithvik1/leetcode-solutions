/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Iterate from the end of the array towards the beginning
    for (int i = digitsSize - 1; i >= 0; i--) {
        // If the current digit is less than 9, we can just increment it
        // and there is no carry-over to the next digit.
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize; // The size of the array remains the same
            return digits;           // Return the modified input array
        }

        // If the digit is 9, it becomes 0 and the loop continues to carry 1 to the left
        digits[i] = 0;
    }

    // If the code reaches this point, it means all digits were 9 (e.g., 999 -> 1000)
    // We need a new array that is one element larger.
    *returnSize = digitsSize + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));

    // Set the first digit to 1 and all others to 0
    result[0] = 1;
    for (int i = 1; i < *returnSize; i++) {
        result[i] = 0;
    }

    return result;
}
