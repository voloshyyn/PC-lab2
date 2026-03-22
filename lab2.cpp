#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <cstdlib>
#include <windows.h>

using namespace std;

int total_count_seq = 0;
int max_val_seq = -1;

mutex mtx;
int total_count_mutex = 0;
int max_val_mutex = -1;

atomic<int> total_count_cas(0);
atomic<int> max_val_cas(-1);

double test_seq(const vector<int> &arr)
{
    total_count_seq = 0;
    max_val_seq = -1;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 3 == 0)
        {
            total_count_seq++;
            if (arr[i] > max_val_seq)
                max_val_seq = arr[i];
        }
    }

    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}