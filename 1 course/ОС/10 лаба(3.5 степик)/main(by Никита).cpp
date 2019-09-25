#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

 int timeSlice, remainingTime, nRunningThreads;
 vector<int> threadQueue;
 vector<int> addQueue;


void scheduler_setup(int timeslice) {

    timeSlice = timeslice;
    remainingTime = timeSlice;

    threadQueue = {};

    nRunningThreads = 0;
}

void new_thread(int thread_id) {
    threadQueue.push_back(thread_id);
    nRunningThreads++;
}

void exit_thread() {

    if (nRunningThreads == 0) return;

    threadQueue.erase(threadQueue.begin());

    nRunningThreads--;
    remainingTime = timeSlice;
}

void block_thread() {
    exit_thread();
}

void wake_thread(int thread_id) {
    new_thread(thread_id);
}

void timer_tick() {

    if (nRunningThreads == 0) return;

    if (remainingTime > 1) {
        remainingTime--;
        return;
    }

    int temp = threadQueue.at(0);
    threadQueue.erase(threadQueue.begin());
    threadQueue.push_back(temp);

    remainingTime = timeSlice;
}

int current_thread() {

    if (nRunningThreads == 0) {
        return -1;
    } else {
        return threadQueue.at(0);
    }
}

int main() {

  scheduler_setup(2);
    new_thread(0);
    block_thread();
    timer_tick();
    new_thread(1);
    block_thread();
    timer_tick();
    wake_thread(0);
    new_thread(2);
    block_thread();
    timer_tick();
    wake_thread(1);
    new_thread(3);
    block_thread();
    timer_tick();
    std::cout << current_thread() << std::endl;
}
