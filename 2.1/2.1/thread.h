#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

std::mutex mutex1, mutex2;

void ThreadA() //read only thread
{
	// Creates deadlock problem
	mutex2.lock();
	std::cout << "Thread A \n" << std::endl;
	mutex1.lock();
	mutex2.unlock();
	mutex1.unlock();
}

void ThreadB()
{
	// Creates deadlock problem
	mutex1.lock();
	std::cout << "Thread B \n" << std::endl;
	mutex2.lock();
	mutex1.unlock();
	mutex2.unlock();
}

void ExecuteThreads()
{
	std::thread t1(ThreadA);
	std::thread t2(ThreadB);

	t1.join();
	t2.join();

	std::cout << "Finished" << std::endl;
}
#pragma once