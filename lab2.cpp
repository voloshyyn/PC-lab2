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

void worker_mutex(const vector<int> &arr, int start_idx, int end_idx)
{
    for (int i = start_idx; i < end_idx; i++)
    {
        if (arr[i] % 3 == 0)
        {
            mtx.lock();
            total_count_mutex++;
            if (arr[i] > max_val_mutex)
            {
                max_val_mutex = arr[i];
            }
            mtx.unlock();
        }
    }
}

double test_mutex(const vector<int> &arr, int threads_num)
{
    total_count_mutex = 0;
    max_val_mutex = -1;
    vector<thread> ths;
    int chunk = arr.size() / threads_num;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < threads_num; i++)
    {
        int start_idx = i * chunk;
        int end_idx = (i == threads_num - 1) ? arr.size() : (i + 1) * chunk;
        ths.push_back(thread(worker_mutex, ref(arr), start_idx, end_idx));
    }

    for (int i = 0; i < threads_num; i++)
    {
        ths[i].join();
    }

    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}