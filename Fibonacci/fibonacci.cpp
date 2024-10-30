// This solution must be compiled with -std=c++20

#include <iostream>
#include <array>
#include <cstddef>

using Int = unsigned long long;

template <std::size_t N>
consteval auto fib(){
    std::array<Int, N> dp{};
    Int prev1{1}, prev2{0};
    for (std::size_t i = 0; i < dp.size(); ++i){
        dp[i] = prev1 + prev2;
        prev2 = prev1;
        prev1 = dp[i];
    }
    return dp;
}

int main(){

    constexpr static Int N = 70;
    constexpr static auto res = fib<N>();
    
    std::cout << res[N-1] << std::endl;
    return 0;
}
