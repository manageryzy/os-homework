/*
 * phi.hpp
 *
 *  Created on: Jul 9, 2016
 *      Author: manageryzy
 */

#ifndef PHI_HPP_
#define PHI_HPP_

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>
#include <vector>


class World{
public:
	class Phi{
	public:
		Phi(int id,World & parent):id(id),w(parent){
		}

		void phi_thread(){
			using namespace std;

			while(1){
				this_thread::sleep_for(chrono::seconds(rand()%10));
				cout << "phi "<<id<<" want to eat" << endl;
				take();
				eat();
				put();
			}
		}
	private:
		int id;
		World & w;

		void eat(){
			using namespace std;
			cout << "phi "<<id<<" is eating" << endl;
		}

		void take(){
			using namespace std;
			unique_lock<mutex> lock(w.cv_mutex);

			while(1){
				w.take_folk_mutex.lock();
				if(w.folk[w.getID(id-1)]==false &&
						w.folk[w.getID(id+1)]==false){
					//succeed take folk
					w.folk[w.getID(id-1)]=true;
					w.folk[w.getID(id+1)]=true;
					w.take_folk_mutex.unlock();
					return;
				}else{
					//wait
					w.take_folk_mutex.unlock();
					w.cv.wait(lock);
				}
			}

		}

		void put(){
			using namespace  std;

			w.take_folk_mutex.lock();
			w.folk[w.getID(id-1)]=false;
			w.folk[w.getID(id+1)]=false;
			w.take_folk_mutex.unlock();

			w.cv.notify_all();
		}
	};
protected:
	std::mutex take_folk_mutex;
	std::mutex cv_mutex;
	std::condition_variable cv;
	std::vector<Phi> phi;
	std::vector<bool> folk;
	std::vector<std::thread> threads;
	int size;

	int getID(int id){
		return id % size;
	}

public:

	World(int size):size(size){
	}

	void init(){
		for(int i=0;i<size;i++){
			phi[i] = Phi(i,*this);
			folk[i] = false;
		}
	}

	void eat(){
		using namespace std;

		for(auto & p : phi){
			threads.push_back(thread(&Phi::phi_thread,p));
		}

		for(auto & t : threads){
			t.join();
		}
	}


};






#endif /* PHI_HPP_ */
