#include <iostream>

void merge_sort(int *arr, int left_index, int right_index)
{
    if (left_index >= right_index)
    {
        return;
    }
    int middle_index = (left_index + right_index) / 2;
    int middle = arr[middle_index];
    int size = right_index - left_index + 1;

    int smaller_arr[size];
    int smaller_arr_index = 0;
    int larger_arr[size];
    int larger_arr_index = 0;

    // Comparing all elements of arr with middle 
    for (int i = left_index; i <= right_index; i++)
    {
        if (arr[i] < middle)
        {
            smaller_arr[smaller_arr_index] = arr[i];
            smaller_arr_index += 1;
            continue;
        }
        if (arr[i] > middle)
        {
            larger_arr[larger_arr_index] = arr[i];
            larger_arr_index += 1;
        }
    }

    // Write back to arr
    // left
    for (int i = 0; i < smaller_arr_index; i++)
    {
        arr[left_index + i] = smaller_arr[i];
    }
    // middle
    arr[left_index + smaller_arr_index] = middle;
    // right
    for (int j = 0; j < larger_arr_index; j++)
    {
        arr[left_index + smaller_arr_index + j + 1] = larger_arr[j];
    }
    merge_sort(arr, left_index, left_index + smaller_arr_index - 1);
    merge_sort(arr, left_index + smaller_arr_index + 1, right_index);
}
