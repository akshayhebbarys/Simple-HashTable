#include "hashtable.hpp"
#include "unit_tests.hpp"

#include <cassert>
using namespace std;

int main() {
	hashtable<string, string> ht;
	assert(ht.capacity() == 1);
	ht.put("10", "abc");

	assert(ht.get("10") == "abc");
	assert(ht.size() == 1);

	ht.put("20", "def");
	assert(ht.get("10") == "abc");
	assert(ht.get("20") == "def");
	assert(ht.size() == 2);

	ht.put("20", "abd");
	ht.erase("10");
	assert(ht.get("10") == "");
	assert(ht.get("20") == "abd");
	assert(ht.size() == 1);

	compareWithSTLMap();
}