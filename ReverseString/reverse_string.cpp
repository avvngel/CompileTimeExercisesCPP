// Must compile with -std=C++20
#include <utility>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <array>
#include <cstddef>
#include <string>

// Fixed struct
template <char... Chars>
struct fixed_string
{
    static constexpr std::size_t size = sizeof...(Chars);
    static constexpr std::array<char, size> data{Chars...};
};

// User-defined literal
template <typename T, T... Chars>
consteval fixed_string<Chars...> operator""_fs(){ return {}; };


// Do work
template <fixed_string input>
consteval std::string reverse_string(){
    std::array<char, input.size> reversed{};
    std::copy(input.data.rbegin(), input.data.rend(), reversed.begin());
    return std::string(reversed.begin(), input.size);

}

int main(){
    constexpr static auto s = "Hello World"_fs;
    constexpr static auto rev_s = reverse_string<s>();
    for (auto& elem : rev_s){
        std::cout << elem;
    }
    std::cout << std::endl;
    

    return 0;
}
