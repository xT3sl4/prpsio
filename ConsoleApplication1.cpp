#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iomanip>

using namespace std;

template <typename T>
void bubblesort(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void bubblesort_for_for_pointer(T* arr, size_t n) {
    T* w1, * w2, temp;

    for (size_t i = 0; i < n; i++) {
        w1 = arr;
        w2 = w1 + 1;

        for (size_t j = 0; j < n - 1; j++) {
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

template <typename T>
void bubblesort_for_for_index(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void bubblesort_for_while_pointer(T* arr, size_t n) {
    T* w1, * w2, temp;
    for (size_t i = 0; i < n - 1; i++) {
        w1 = arr;
        w2 = w1 + 1;
        size_t j = 0;
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

template <typename T>
void bubblesort_for_while_index(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t j = 0;
        while (j < n - i - 1) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            j++;
        }
    }
}

template <typename T>
void bubblesort_for_short_pointer(T* arr, size_t n) {
    T* w1, * w2, temp;

    for (size_t i = 0; i < n - 1; i++) {
        w1 = arr;
        w2 = w1 + 1;
        for (size_t j = 0; j < n - i - 1; j++) {
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

template <typename T>
void bubblesort_for_short_index(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename Func, typename T>
double measure_time(Func func, T arr[], size_t n) {
    auto start = chrono::high_resolution_clock::now();
    func(arr, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

void run_and_measure(int n, ofstream& file) {
    int* arr_int = new int[n];
    float* arr_float = new float[n];

    for (int i = 0; i < n; i++) {
        arr_int[i] = rand() % 1000 + 1;
        arr_float[i] = static_cast<float>(arr_int[i]);
    }

    file << "| " << setw(18) << n << " | "
        << setw(18) << measure_time(bubblesort<int>, arr_int, n) << " | "
        << setw(19) << measure_time(bubblesort<float>, arr_float, n) << " | "
        << setw(22) << measure_time(bubblesort_for_for_index<int>, arr_int, n) << " | "
        << setw(24) << measure_time(bubblesort_for_for_index<float>, arr_float, n) << " | "
        << setw(24) << measure_time(bubblesort_for_while_index<int>, arr_int, n) << " | "
        << setw(26) << measure_time(bubblesort_for_while_index<float>, arr_float, n) << " | "
        << setw(24) << measure_time(bubblesort_for_short_index<int>, arr_int, n) << " | "
        << setw(26) << measure_time(bubblesort_for_short_index<float>, arr_float, n) << " | "
        << setw(24) << measure_time(bubblesort_for_for_pointer<int>, arr_int, n) << " | "
        << setw(26) << measure_time(bubblesort_for_for_pointer<float>, arr_float, n) << " | "
        << setw(26) << measure_time(bubblesort_for_while_pointer<int>, arr_int, n) << " | "
        << setw(28) << measure_time(bubblesort_for_while_pointer<float>, arr_float, n) << " | "
        << setw(26) << measure_time(bubblesort_for_short_pointer<int>, arr_int, n) << " | "
        << setw(28) << measure_time(bubblesort_for_short_pointer<float>, arr_float, n) << " |" << endl;

    delete[] arr_int;
    delete[] arr_float;
}

int main() {
    srand(time(0));

    ofstream file("results.txt");

    if (file.is_open()) {
        file << "| Number of Elements | Template Int (ms)  | Template Float (ms) | For-For Index Int (ms) | For-For Index Float (ms) | For-While Index Int (ms) | For-While Index Float (ms) | For-Short Index Int (ms) | For-Short Index Float (ms) | For-For Pointer Int (ms) | For-For Pointer Float (ms) | For-While Pointer Int (ms) | For-While Pointer Float (ms) | For-Short Pointer Int (ms) | For-Short Pointer Float (ms) |" << endl;
        file << "|--------------------|--------------------|---------------------|------------------------|--------------------------|--------------------------|----------------------------|--------------------------|----------------------------|--------------------------|----------------------------|----------------------------|------------------------------|----------------------------|------------------------------|" << endl;

        run_and_measure(100, file);
        run_and_measure(1000, file);
        run_and_measure(10000, file);



        file.close();
    }
    else {
        cerr << "Nie moge otworzyc pliku";
    }

    return 0;
}
