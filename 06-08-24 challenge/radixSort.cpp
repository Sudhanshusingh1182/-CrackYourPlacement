void countSort(int arr[], int n, int exp) {
    vector<int> output(n);
    vector<int> count(10, 0);

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Compute cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxi = *max_element(arr, arr + n);

    // Apply counting sort to sort elements based on place value
    for (int exp = 1; maxi / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}