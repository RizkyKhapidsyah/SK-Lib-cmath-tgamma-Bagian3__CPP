#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#include <conio.h>

int main() {
    std::cout << "tgamma(10) = " << std::tgamma(10)
        << ", 9! = " << 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 << '\n'
        << "tgamma(0.5) = " << std::tgamma(0.5)
        << ", sqrt(pi) = " << std::sqrt(std::acos(-1)) << '\n';
    
    std::cout << "tgamma(1) = " << std::tgamma(1) << '\n'
        << "tgamma(+Inf) = " << std::tgamma(INFINITY) << '\n';
    
    errno = 0;
    
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "tgamma(-1) = " << std::tgamma(-1) << '\n';
    
    if (errno == EDOM) {
        std::cout << "    errno == EDOM: " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_INVALID)) {
        std::cout << "    FE_INVALID raised\n";
    }
        
    _getch();
    return 0;
}