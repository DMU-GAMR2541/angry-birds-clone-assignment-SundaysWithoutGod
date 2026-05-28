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


    void addition() {
        for (int i = 0; i < 30; i++ ) {

        int x;
         x = 30;
        int y;
         y = 10;
        int sum;
        sum = x + y;
        std::cout << "This is multi threading: " << sum << std::endl;
        //the thread that's calling this function
        std::this_thread::sleep_for(std::chrono::milliseconds(120)); //telling the thread to pause for 60 miliseconds/ chrono is the class used to access time

       }

    };

    void Multiply() {
       
        for (int i = 0; i < 30; i++) {

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


protected:
public:

    MultiThreading() {
        //Creating the async thread
        f_isReturned = std::async(std::launch::async, &MultiThreading::addition, this);//Launch is asking the compiler to run this thread as early as possible, making a reference to a function in the class, "this" means this class/object
        t_practise = std::thread(&MultiThreading::Multiply, this);
    };
    ~MultiThreading() {
    
        if (t_practise.joinable()) { t_practise.join(); };
    
    
    };


};