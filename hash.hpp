#include <cstdint>

template <typename T>
class hash {
public:
	hash() {}

	uint64_t getHash(T &x) {
		throw std::exception("Not Implemented");
	}
private:
};