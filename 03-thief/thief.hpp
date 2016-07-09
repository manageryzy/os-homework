/*
 * thief.hpp
 *
 *  Created on: Jul 8, 2016
 *      Author: manageryzy
 */

#ifndef THIEF_HPP_
#define THIEF_HPP_

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <chrono>

class World{
	std::mutex mu;
	std::condition_variable cv;

	int thief_pos = 0;
	int police_pos = 0;
	int end = 100;

	//police run thread
	void police_run(){
		using namespace std;

		unique_lock<mutex> lck(mu);

		cout << "police thread run" << endl;

		cv.wait(lck);

		while(1){
			police_pos++;
			cout << "police at: "<< police_pos <<endl;

			if(police_pos>end){
				cout << "police win" <<endl;
				cv.notify_all();
				return;
			}

			if(police_pos-thief_pos>=3){
				cout << "police thread sleep" << endl;
				cv.notify_all();
				cv.wait(lck);
				if(thief_pos>end){
					return;
				}
			}
		}
	}

	//thief run thread
	void thief_run(){
		using namespace std;
		unique_lock<mutex> lck(mu);

		cout << "thief thread run" << endl;

		cv.wait(lck);

		while(1){
			thief_pos++;
			cout << "thief at: " << thief_pos << endl;

			if(thief_pos>end){
				cout<<"thief win" <<endl;
				cv.notify_all();
				return;
			}

			if(thief_pos-police_pos>=3){
				cout << "thief thread sleep" << endl;
				cv.notify_all();
				cv.wait(lck);
				if(police_pos>end){
					return;
				}
			}
		}
	}

public:

	void run(){
		using namespace std;

		thread thread_thief(&World::thief_run,this);
		thread thread_police(&World::police_run,this);

		this_thread::sleep_for(1s);
		cv.notify_one();

		thread_police.join();
		thread_thief.join();
	}
};

#endif /* THIEF_HPP_ */
