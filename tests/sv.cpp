#include "../aidsen.hpp"

using namespace aidsen;

int main() {
    auto sv = "Hello\tworld"_sv;
    println(stdout, "Escape: ", Escape{sv});
    println(stdout, "Caps: ", Caps{sv});
}
