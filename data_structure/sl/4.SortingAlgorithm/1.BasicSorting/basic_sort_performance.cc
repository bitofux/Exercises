/*
 * PROJECT : EXERCISES
 * FILE    : basic_sort_performance.cc
 * AUTHOR  : bitofux
 * DATE    : 2026-09-18
 * BRIEF   : 基础排序之间的性能对比
 */
#include <array>
#include <iostream>
#include <chrono>
#include <random>

#define COUNT 100000

// bubble_sort
void bubble_sort_func(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int flag = false;
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }
}

// selection_sort
void selection_sort_func(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = arr[i];
        int idx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < min) {
                min = arr[j];
                idx = j;
            }
        }

        if (i != idx) {
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
}

// insertion_sort
void insertion_sort_func(int* arr, int size) {
    for (int i = 1; i < size; ++i) {
        int val = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (arr[j] <= val) {
                break;
            }
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = val;
    }
}

// shell_sort
void shell_sort_func(int* arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int val = arr[i];
            int j = i - gap;
            for (; j >= 0; j -= gap) {
                if (arr[j] <= val) {
                    break;
                }
                arr[j + gap] = arr[j];
            }

            arr[j + gap] = val;
        }
    }
}

class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> start_;

public:
    Timer() { start_ = std::chrono::steady_clock::now(); }
    void mark() noexcept { start_ = std::chrono::steady_clock::now(); }

    double peek() noexcept {
        auto end = std::chrono::steady_clock::now();

        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start_).count();
    }
};

int main() {
    std::random_device rd;
    std::minstd_rand msr{rd()};
    std::uniform_int_distribution<> distrib{1, 100000};
    Timer t1;

    int* bubble_sort = new int[COUNT]{0};
    for (int i = 0; i < COUNT; ++i) {
        bubble_sort[i] = distrib(msr);
    }
    t1.mark();
    bubble_sort_func(bubble_sort, COUNT);
    std::cout << "bubble_sort: " << t1.peek() << "ms\n";
    delete[] bubble_sort;

    int* selection_sort = new int[COUNT]{0};
    for (int i = 0; i < COUNT; ++i) {
        selection_sort[i] = distrib(msr);
    }
    t1.mark();
    selection_sort_func(selection_sort, COUNT);
    std::cout << "selection_sort: " << t1.peek() << "ms\n";
    delete[] selection_sort;

    int* insertion_sort = new int[COUNT]{0};
    for (int i = 0; i < COUNT; ++i) {
        insertion_sort[i] = distrib(msr);
    }
    t1.mark();
    insertion_sort_func(insertion_sort, COUNT);
    std::cout << "insertion_sort: " << t1.peek() << "ms\n";
    delete[] insertion_sort;

    int* shell_sort = new int[COUNT]{0};
    for (int i = 0; i < COUNT; ++i) {
        shell_sort[i] = distrib(msr);
    }
    t1.mark();
    shell_sort_func(shell_sort, COUNT);
    std::cout << "shell_sort: " << t1.peek() << "ms\n";
    delete[] shell_sort;
}
