int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high) {
        int mid=(low+high)/2;
        int k=countStudents(arr, mid);
        if (k <= m) {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}


