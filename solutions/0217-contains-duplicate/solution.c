void merge(int* nums, int left, int mid, int right, int* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
}

void mergeSort(int* nums, int left, int right, int* temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);
        merge(nums, left, mid, right, temp);
    }
}

_Bool containsDuplicate(int* nums, int size) {
    if (size <= 1) {
        return 0;
    }

    int tempArray[size];
    mergeSort(nums, 0, size - 1, tempArray);

    for (int k = 0; k < size - 1; k++) {
        if (nums[k] == nums[k + 1]) {
            return 1;
        }
    }

    return 0;
}

