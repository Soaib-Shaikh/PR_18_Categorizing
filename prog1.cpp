#include<iostream>
#include<vector>
using namespace std;

// Function to perform selection sort
// This function sorts the array in ascending order by repeatedly finding the minimum element
void selection_sort(vector<int>& arr)
{
    for(int i = 0; i < arr.size() - 1; i++) // Loop through each element except the last
    {
        int min_index = i; // Assume the current element is the minimum
        for(int j = i + 1; j < arr.size(); j++) // Find the minimum element in the unsorted part
        {
            if (arr[j] < arr[min_index]) // Update the minimum index if a smaller element is found
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]); // Swap the minimum element with the current element
    }
}

// Function to merge two sorted subarrays
// This function merges two sorted halves of the array into a single sorted array
void merge(vector<int>& arr, int left, int mid, int right)
{
    int i = left; // Pointer for the left subarray
    int j = mid + 1; // Pointer for the right subarray
    vector<int> temp; // Temporary array to store merged elements

    // Merge elements from both subarrays in sorted order
    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j]) // If the element in the left subarray is smaller
        {
            temp.push_back(arr[i++]); // Add it to the temporary array
        }
        else // If the element in the right subarray is smaller
        {
            temp.push_back(arr[j++]); // Add it to the temporary array
        }
    }

    // Add remaining elements from the left subarray
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    // Add remaining elements from the right subarray
    while(j <= right)
    {
        temp.push_back(arr[j++]);
    }

    // Copy the merged elements back to the original array
    for(int k = left; k <= right; k++)
    {
        arr[k] = temp[k - left];
    }
}

// Recursive function to perform merge sort
// This function divides the array into halves and sorts them recursively
void merge_sort(vector<int>& arr, int left, int right)
{
    if(left >= right) // Base case: If the array has one or no elements, it is already sorted
        return;

    int mid = left + (right - left) / 2; // Find the middle index
    merge_sort(arr, left, mid); // Recursively sort the left half
    merge_sort(arr, mid + 1, right); // Recursively sort the right half
    merge(arr, left, mid, right); // Merge the two sorted halves
}

// Function to perform linear search
// This function searches for a target value in the array sequentially
int linear_search(vector<int>& arr, int target)
{
    for(int i = 0; i < arr.size(); i++) // Loop through each element in the array
    {
        if(arr[i] == target) // If the target value is found
        {
            return i; // Return the index of the target value
        }
    }
    return -1; // Return -1 if the target value is not found
}

// Function to perform binary search
// This function searches for a target value in a sorted array using the divide-and-conquer approach
int binary_search(vector<int>& arr, int target)
{
    int start = 0; // Start index of the array
    int end = arr.size() - 1; // End index of the array

    while(start <= end) // Continue searching while the start index is less than or equal to the end index
    {
        int mid = (start + end) / 2; // Find the middle index

        if(arr[mid] == target) // If the target value is found at the middle index
        {
            return mid; // Return the index of the target value
        }
        else if(arr[mid] < target) // If the target value is greater than the middle element
        {
            start = mid + 1; // Search in the right half
        }
        else // If the target value is less than the middle element
        {
            end = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if the target value is not found
}


// Function to print the array
// This function displays the elements of the array
void print_array(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) // Loop through each element in the array
    {
        cout<<arr[i]<<" "; // Print each element
    }
    cout<<endl; // Print a newline at the end
}

int main()
{
    int choice, target, result; // Variables for user choice, target value, and search result
    vector<int> arr; // Array to store elements

        // This function allows the user to input elements into the array

        int n;
        cout<<"Enter the size of array: "; // Prompt the user for the size of the array
        cin>>n;
        arr.resize(n); // Resize the array to the specified size
        for (int i = 0; i < arr.size(); i++) // Loop to input each element
        {
            cout<<"Enter element of array ["<< i <<"]: ";
            cin>>arr[i];
        }
        cout<<endl<<"Array is: "; // Print the array after input
        print_array(arr); // Call the function to print the array


    do
    {
        // Display the menu
        cout<<endl;
        cout<<"======= Sorting and Searching Algorithms ======="<<endl;
        cout<<"1. Selection Sort"<<endl;
        cout<<"2. Merge Sort"<<endl;
        cout<<"3. Linear Search"<<endl;
        cout<<"4. Binary Search"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:    
            cout<<endl<<"Array is: ";
            print_array(arr); // Print the array

            selection_sort(arr); // Perform selection sort
            cout<<"Sorted array using Selection Sort: ";
            print_array(arr); // Print the sorted array

            break;

        case 2:
            cout<<endl<<"Array is: ";
            print_array(arr); // Print the array

            merge_sort(arr, 0, arr.size() - 1); // Perform merge sort
            cout<<"Sorted array using Merge Sort: ";
            print_array(arr); // Print the sorted array

            break;

        case 3:

            cout<<"Array is: ";
            print_array(arr); // Print the array

            if(arr.size() != 0) // Check if the array is not empty
            {
                cout<<"Enter the target value to search: ";
                cin>>target; // Input the target value
                result = linear_search(arr, target); // Perform linear search
            }
            else
            {
                cout<<"Array is Empty."<<endl; // Handle empty array case
                break;
            }

            if (result != -1) {
                cout << "Element found at index: " << result << endl;
            } 
            else 
            {
                cout << "Element not found." << endl;
            }
            break;

        case 4:
            selection_sort(arr); // Sort the array before binary search
            cout << "Sorted array: ";
            print_array(arr); // Print the sorted array

            if(arr.size() != 0) // Check if the array is not empty
            {
    
                cout << "Enter the target value to search: ";
                cin >> target;
                result = binary_search(arr, target); // Perform binary search
            }
            else
            {
                cout<<"Array is Empty."<<endl; // Handle empty array case
                break;
            }

            if (result != -1) {
                cout << "Element found at index: " << result << endl;
            } 
            else 
            {
                cout << "Element not found." << endl;
            }
            break;

        case 0:
            cout<<"Exiting the program."<<endl; // Exit the program
            break;

        default:
            cout<<"Invalid choice. Please try again."<<endl; // Handle invalid input
            break;
        }

    } while (choice != 0); // Repeat until the user chooses to exit

    return 0;
}