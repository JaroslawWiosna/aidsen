#include "../aidsen.hpp"

using namespace aidsen;

#define xstr(a) str(a)
#define str(a) #a
#define PRETTY_PRINT_SIZEOF(x) println(stdout, "The size of ", str(x) , " is : \t", sizeof(x), " bytes")  

int main() {
    PRETTY_PRINT_SIZEOF(char);
    PRETTY_PRINT_SIZEOF(short);
    PRETTY_PRINT_SIZEOF(int);
    PRETTY_PRINT_SIZEOF(long);
    PRETTY_PRINT_SIZEOF(long long);
    PRETTY_PRINT_SIZEOF(float);
    PRETTY_PRINT_SIZEOF(double);
    PRETTY_PRINT_SIZEOF(long double);
    PRETTY_PRINT_SIZEOF(bool);
}
