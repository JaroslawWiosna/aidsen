#include "../aidsen.hpp"

using namespace aidsen;

int main() {
    const uint32_t UNICODE_LOW = 0x0000;
    const uint32_t UNICODE_HIGH = 0x10FFFF;

    for (uint32_t code = UNICODE_LOW; code <= UNICODE_HIGH; ++code) {
        size_t size{};
        assert(code == utf8_get_code(code_to_utf8(code).view(), &size).unwrap); 
    }
    
}
