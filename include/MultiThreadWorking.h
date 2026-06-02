#pragma once
#include<iostream>
#include<thread>
#include<memory>
#include<mutex>
#include<future>

class MultiThreading {
private:
    
    //mutex locks data from threads while one thread is activly using it
    std::mutex m_locks;
    std::thread t_practise;

    //a returned value for a type 
    std::future<void> f_isReturned;
    std::future<void> f_asyncLoading;
    int percentage = 0;

    int i_loadingValue = 0;


    //Async is a thread that's wrapped in a helper-- it does not need to use .joinable or .join but has limited 

    void asyncAddition() {
        for (int i = 0; i < 50; i++ ) {

        
            m_locks.lock();
            i_loadingValue++;
        std::cout << "This is multi threading: "<< i_loadingValue << std::endl;
        //the thread that's calling this function
        std::this_thread::sleep_for(std::chrono::milliseconds(120)); //telling the thread to pause for 60 miliseconds/ chrono is the class used to access time

        m_locks.unlock();//unlock after i've done the owrk in the for loop
       }


    };

    void threadMultiply() {
       
        for (int i = 0; i < 50; i++) {

        int a;
        a = 10;
        int b;
        b = 5;
        int product;
        product = a + b;
        std::cout << "I'm working in SECONDS: " << product << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        }

    };

    void loading() {
        //value that increments verytime you go back through
        for (int i = 0; i < 50; i++) {
        
        m_locks.lock();//STEP 1---Lock AFTER the loop because if you don't it keeps locking and unlocking in the loop which is inefficient 
            i_loadingValue++;
        std::cout << "LOADING: " << i_loadingValue << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
        
        m_locks.unlock();
        }
    
    
    
    };



protected:
public:

    MultiThreading() {
        //Creating the async thread
        f_isReturned = std::async(std::launch::async, &MultiThreading::asyncAddition, this);//Launch is asking the compiler to run this thread as early as possible, making a reference to a function in the class, "this" means this class/object
        t_practise = std::thread(&MultiThreading::threadMultiply, this);
        f_asyncLoading = std::async(std::launch::async, &MultiThreading::loading, this);
    };
    ~MultiThreading() {
    
        if (t_practise.joinable()) { t_practise.join(); };
    
    }
    
    int Ready() {

       // m_locks.lock();
        return i_loadingValue;
        //m_locks.unlock();
    };
        


};