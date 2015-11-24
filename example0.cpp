/// @filename example0.cpp
/// @author Joel D. Rodriguez-Ortiz
/// @brief CS562 Out of Bounds Access Example 0

#include <cstdio>

int main(int, char**)
{
    int len = 377;
    char* payload = (char*) "foo";

    for (int i = 0; i < len; ++i)
        printf("%c", payload[i]);

    printf("\n");

    char* secret = (char*)
    "AAAAB3NzaC1yc2EAAAABIwAAAQEA57Fkg0EJp/hNbwbffYrrE78tuiyezZeBf32YDFOSEJa5hy"
    "tUMjMvo0BQZKRht0SEinCNjuxRNw2SDT6ipjeyCtmIf1KxPefBIgUaFxRGcc+mcAddGEDyLyBZ"
    "nas96PlLzX647kh0Ccajz48YXTHW2lFpkCb0CMA2Ah3k7gKwPeeaLLEFO5VXeRgsxeBmPokW9h"
    "nn4pRV65G+1aSfnwpwJvF2f6L4k5hHG5mnPQXiZr9WVIVzfGKO/uHKW0oj0rgT6+7b2HKjDwN7"
    "aivWdwlPNFHcr3hGGe+s0cuLf3fjUD6Y9zQj2Ayy5GKy+hnAkJxzpVln7QfwoklycDxPh9KILQ"
    ;
}
