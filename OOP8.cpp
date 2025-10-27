#include <iostream>
using namespace std;

template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int choice;
    char ch;

    do {
        cout << "\nMenu:\n1. Integer Array\n2. Float Array\nEnter your choice: ";
        cin >> choice;

        int n;
        cout << "Enter size of array: ";
        cin >> n;

        switch (choice) {
        case 1: {
            int *intArr = new int[n];
            cout << "Enter " << n << " integers: ";
            for (int i = 0; i < n; i++) {
                cin >> intArr[i];
            }

            cout << "Original integer array: ";
            displayArray(intArr, n);

            selectionSort(intArr, n);

            cout << "Sorted integer array: ";
            displayArray(intArr, n);

            delete[] intArr;
            break;
        }

        case 2: {
            float *floatArr = new float[n];
            cout << "Enter " << n << " floats: ";
            for (int i = 0; i < n; i++) {
                cin >> floatArr[i];
            }

            cout << "Original float array: ";
            displayArray(floatArr, n);

            selectionSort(floatArr, n);

            cout << "Sorted float array: ";
            displayArray(floatArr, n);

            delete[] floatArr;
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
