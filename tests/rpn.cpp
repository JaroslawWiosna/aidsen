#include "../aidsen.hpp"

using namespace aidsen;

// reverse polish notation calculator
int main(int argc, char *argv[]) {
    Args args{argc, argv};
    args.shift(); // skip the program name

    auto stack = Stack<String_View>{};
    defer(destroy(stack));
    while (not args.empty()) {
        auto arg = cstr_as_string_view(args.shift());
        arg = arg.trim();
        while (arg.count > 0) {
            auto word = arg.chop_word();
            println(stdout, word);
            stack.push(word);
        }
    }

    while (not stack.empty()) {
        println(stdout, '\t', stack.pop());
    }
}
