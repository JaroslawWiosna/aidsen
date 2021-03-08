#include "../aidsen.hpp"

using namespace aidsen;

struct Rpn {
    Stack<String_View> stack{};

};

float evaluate(Rpn *rpn) {
    while (not rpn->stack.empty()) {
        auto curr = rpn->stack.pop();
        auto as_float = curr.as_float();
        if (as_float.has_value) {
            return as_float.unwrap;
        } else {
            auto fst = evaluate(rpn);
            auto snd = evaluate(rpn);
            if ("+"_sv == curr) {
                return snd + fst;
            } else if ("-"_sv == curr) {
                return snd - fst;
            } else if ("*"_sv == curr) {
                return snd * fst;
            } else if ("/"_sv == curr) {
                return snd / fst;
            }
        }
    }
    unreachable();
}

Rpn sv_to_rpn(String_View sv) {
    Rpn result{};
    sv = sv.trim();
    while (sv.count > 0) {
        auto word = sv.chop_word();
        result.stack.push(word);
    }
    return result;
}

// reverse polish notation calculator
int main(int argc, char *argv[]) {
    {
        auto rpn = sv_to_rpn("1 1 +"_sv);
        assert(2.0f == evaluate(&rpn));
    }
    {
        auto rpn = sv_to_rpn("7 2 -"_sv);
        assert(5.0f == evaluate(&rpn));
    }
    {
        auto rpn = sv_to_rpn("7 2 - 10 2 / +"_sv);
        assert(10.0f == evaluate(&rpn));
    }

    Args args{argc, argv};
    args.shift(); // skip the program name

    auto calculator = Rpn{};
    defer(destroy(calculator.stack));
    while (not args.empty()) {
        auto arg = cstr_as_string_view(args.shift());
        arg = arg.trim();
        while (arg.count > 0) {
            auto word = arg.chop_word();
            calculator.stack.push(word);
        }
    }

    println(stdout, evaluate(&calculator));
}
