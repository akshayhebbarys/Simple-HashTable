#include "hashtable.hpp"

#include <cassert>
#include <chrono>
#include <ctime>
#include <iostream>
#include <unordered_map>

void sequencialOpCustomHT1(int rep) {
	hashtable<int, std::string> ht;
	int num = 48908;
	for (int i = num; i < rep + num; ++i) {
		assert(ht.contains(i) == false);
		ht.put(i, "some_text" + std::to_string(i));
		assert(ht.contains(i) == true);
	}

	for (int i = num; i < rep + num; ++i) {
		assert(ht.get(i) ==  ("some_text" + std::to_string(i)));
		ht.erase(i);
		assert(ht.contains(i) == false);
	}
	assert(ht.size() == 0);
}

void sequencialOpSTLHT1(int rep) {
	std::unordered_map<int, std::string> ht;
	int num = 3495;
	for (int i = num; i < rep + num; ++i) {
		assert(ht.count(i) == 0);
		ht[i] = "some_text" + std::to_string(i);
		assert(ht.count(i) == 1);
	}

	for (int i = num; i < rep + num; ++i) {
		assert(ht.at(i) ==  ("some_text" + std::to_string(i)));
		ht.erase(i);
		assert(ht.count(i) == 0);
	}
	assert(ht.size() == 0);
}

void sequencialOpCustomHT2(int rep) {
	hashtable<std::string, std::string> ht;
	for (int i = 0; i < rep; ++i) {
		std::string key = std::to_string(i);
		assert(ht.contains(key) == false);
		ht.put(key, "some_text" + key);
		assert(ht.contains(key) == true);
	}

	for (int i = 0; i < rep; ++i) {
		std::string key = std::to_string(i);
		assert(ht.get(key) ==  ("some_text" + key));
		ht.erase(key);
		assert(ht.contains(key) == false);
	}
	assert(ht.size() == 0);
}

void sequencialOpSTLHT2(int rep) {
	std::unordered_map<std::string, std::string> ht;
	for (int i = 0; i < rep; ++i) {
		std::string key = std::to_string(i);
		assert(ht.count(key) == 0);
		ht[key] = "some_text" + key;
		assert(ht.count(key) == 1);
	}

	for (int i = 0; i < rep; ++i) {
		std::string key = std::to_string(i);
		assert(ht.at(key) ==  ("some_text" + key));
		ht.erase(key);
		assert(ht.count(key) == 0);
	}
	assert(ht.size() == 0);
}

void compareWithSTLMap() {
	using namespace std::chrono;
	high_resolution_clock::time_point t1, t2;
	duration<double> time_span;

	int totalOps = 100000;

	t1 = high_resolution_clock::now();
	sequencialOpCustomHT1(totalOps);
	sequencialOpCustomHT2(totalOps);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>> (t2 - t1);
	std::cout << "Custom hashtable       : " << time_span.count() << std::endl;

	t1 = high_resolution_clock::now();
	sequencialOpSTLHT1(totalOps);
	sequencialOpSTLHT2(totalOps);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>> (t2 - t1);
	std::cout << "Standard STL hashtable : " << time_span.count() << std::endl;
}
