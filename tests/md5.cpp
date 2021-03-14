#include "../aidsen.hpp"

using namespace aidsen;

void md5(String_View in, String_Buffer *out) {

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
