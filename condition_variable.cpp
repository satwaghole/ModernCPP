/* C++ Program to illustrate the use of Condition Variables
  to demonstrate the asynschronous communication between one sender and 2 receiver
*/
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// mutex to block threads
mutex mtx;
condition_variable cv;

// function to avoid spurios wakeup
bool data_ready = false;

// producer function working as sender
void producer()
{
    // Simulate data production
    this_thread::sleep_for(chrono::seconds(2));

    // lock release
    lock_guard<mutex> lock(mtx);

    // variable to avoid spurious wakeup
    data_ready = true;

    // logging notification to console
    cout << "Data Produced!" << endl;

    // notify consumer when done
    cv.notify_all();
}

// consumer that will consume what producer has produced
// working as reciever
void consumer()
{
    // locking
    unique_lock<mutex> lock(mtx);

    // waiting
    cv.wait(lock, [] { return data_ready; });

    cout << "Data consumed!" << endl;
}

void consumer1()
{
    // locking
    unique_lock<mutex> lock(mtx);

    // waiting
    cv.wait(lock, [] { return data_ready; });

    cout << "Data consumed! from consumer1" << endl;
}

// drive code
int main()
{
    thread consumer_thread(consumer);
    thread consumer_thread1(consumer1);
    
    thread producer_thread(producer);

    consumer_thread.join();
    consumer_thread1.join();
    
    producer_thread.join();

        return 0;
}
