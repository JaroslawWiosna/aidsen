#include "../aidsen.hpp"

using namespace aidsen;

// rfc1321
void md5(String_View in, String_Buffer *out) {
    constexpr uint32_t A = 0x67452301;
    constexpr uint32_t B = 0xefcdab89;
    constexpr uint32_t C = 0x98badcfe;
    constexpr uint32_t D = 0x10325476;

    // F(X,Y,Z) = XY v not(X) Z
    // G(X,Y,Z) = XZ v Y not(Z)
    // H(X,Y,Z) = X xor Y xor Z
    // I(X,Y,Z) = Y xor (X v not(Z))
     
    constexpr auto F = [](uint32_t X, uint32_t Y, uint32_t Z){return (X & Y) | ((~X) & Z);};  
    constexpr auto G = [](uint32_t X, uint32_t Y, uint32_t Z){return (X & Z) | (Y & (~Z));};  
    constexpr auto H = [](uint32_t X, uint32_t Y, uint32_t Z){return X ^ Y ^ Z;};  
    constexpr auto I = [](uint32_t X, uint32_t Y, uint32_t Z){return Y ^ (X | (~Z));};  

    panic("Not implemented. Yet.");
}

int main() {
    {
        char output_buf[32];
        String_Buffer sb_out{sizeof(output_buf), output_buf};
        md5("The quick brown fox jumps over the lazy dog"_sv, &sb_out);
        assert("9e107d9d372bb6826bd81d3542a419d6"_sv == sb_out.view());
    }
    {
        char output_buf[32];
        String_Buffer sb_out{sizeof(output_buf), output_buf};
        md5("The quick brown fox jumps over the lazy dog."_sv, &sb_out);
        assert("e4d909c290d0fb1ca068ffaddf22cbd0"_sv == sb_out.view());
    }
    {
        char output_buf[32];
        String_Buffer sb_out{sizeof(output_buf), output_buf};
        md5(""_sv, &sb_out);
        assert("d41d8cd98f00b204e9800998ecf8427e"_sv == sb_out.view());
    }
}
