// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>

using namespace std;


void bubblesort_for_for_pointer(int* arr, int n)
{
    int* w1, * w2, temp;

    for (int i = 0; i < n;i++)
    {
        w1 = arr;
        w2 = w1 + 1;
        
        for (int j=0; j < n - 1; j++) {
            if (*w1 > *w2) {
                temp = *w2;
                *w2 = *w1;
                *w1 = temp;

            }
            w1++;
            w2++;
        }
    }
}

void bubblesort_for_for_index(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void bubblesort_for_while_pointer(int* arr, int n) {
    int* w1, * w2, temp;
    for (int i = 0; i < n - 1; i++) {
        w1 = arr;
        w2 = w1 + 1;
        int j = 0;
        while (j < n - i - 1) {
            if (*w1 > *w2) {
                temp = *w2;
                *w2 = *w1;
                *w1 = temp;
                
            }
            w1++;
            w2++;
            j++;
        }
    }
}


void bubblesort_for_while_index(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = 0;
        while (j < n - i - 1) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            j++;
        }
    }
}
void bubblesort_for_short_pointer(int* arr, int n) {

    int* w1, * w2, temp;

    for (int i = 0; i < n - 1; i++) {
        w1 = arr;
        w2 = w1 + 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (*w1 > *w2) {
                temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
        }
    }
}
void bubblesort_for_short_index(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
bool sprawdzanie(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }

    }
    return true;
}

int main() {
    srand(time(0));
    int arr[7];

    int n = 7;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }

    if (sprawdzanie(arr, n) == 0) {
        cout << "nie" << endl;

    }
    else {
        cout << "tak" << endl;

    }
    std::cout << "Sorting using bubbleSortForShorter:\n";
    bubblesort_for_short_index(arr, n);
    for (short i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForFor:\n";
    bubblesort_for_for_index(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForWhile:\n";
    bubblesort_for_while_index(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForPointer:\n";
    bubblesort_for_for_pointer(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForWhilePointer:\n";
    bubblesort_for_while_pointer(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";


    std::cout << "\n\nSorting using bubbleSortForshortPointer:\n\n";
    bubblesort_for_while_pointer(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " " ;
    cout << " \n";
    if (sprawdzanie(arr, n) == 0) {
        cout << "nie" << endl;

    }
    else {
        cout << "tak" << endl;

    }

    return 0;
}
