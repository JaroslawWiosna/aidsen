#include "../aidsen.hpp"

using namespace aidsen;

char buf[200];
int main() {
    String_Buffer sb = {sizeof(buf), buf};
    sprint(&sb, "Hello"_sv,
            ' ',
            "e = ",
            2.18f,
            ' ',
            10ull,
            11u,
            12ul,
            13l,
            14,
            true,
            false,
            some(":-)"),
            Maybe<float>{},
            Pad{4, '-'},
            Caps{"small letters"_sv}
            );

    char another[4];
    String_Buffer another_string_buffer = {sizeof(another), another};
    sprint(&another_string_buffer, 3.14152f);
    sprint(&sb, another_string_buffer);

    println(stdout, sb);
}
