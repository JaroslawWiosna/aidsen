#include "../aidsen.hpp"

using namespace aidsen;

int main() {
    auto da = Dynamic_Array<int>{};
    da.push(1, 3, 4, 60);
    assert(4 == da.size);
}
