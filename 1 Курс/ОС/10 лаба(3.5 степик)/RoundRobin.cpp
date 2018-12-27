#include <iostream>
#include <vector>

using namespace std;

int tick_time, thread_time;
vector<int> thread;

void scheduler_setup(int timeslice)
{
    thread = {};
    tick_time = timeslice;
    thread_time = tick_time;
}

void new_thread(int thread_id)
{
    cout << "New thread: " << thread_id << endl;
    thread.push_back(thread_id);
}

void exit_thread()
{
    cout << "Exit thread: " << thread[0] << endl;
    if(!thread.empty()){
        thread.erase(thread.begin());
        thread_time = tick_time;
    }
}

void block_thread()
{
    cout << "Block thread: " << thread[0] << endl;
    if(!thread.empty()){
        thread.erase(thread.begin());
        thread_time = tick_time;
    }
}

void wake_thread(int thread_id)
{
    cout << "Wake thread: " << thread_id << endl;
    thread.push_back(thread_id);
}

void timer_tick()
{

    if(!thread.empty()){
        if(thread_time <= 1){
            thread.push_back(thread[0]);
            thread.erase(thread.begin());
            thread_time = tick_time;
        }
        else{
                cout << "Time: " << thread_time << endl;
            thread_time--;
        cout << "Time: " << thread_time << endl;
        }
    }

}

int current_thread()
{
    if(!thread.empty()){
        return thread[0];
    }
    else{
        return -1;
    }
}

int main()
{
    scheduler_setup(2);
    new_thread(1);
    block_thread();
    timer_tick();
    new_thread(2);
    block_thread();
    timer_tick();
    wake_thread(1);
    new_thread(3);
    block_thread();
    timer_tick();
    wake_thread(1);
    new_thread(4);
    block_thread();
    timer_tick();
    cout << "Current thread: " << current_thread() << endl;
    return 0;
}
