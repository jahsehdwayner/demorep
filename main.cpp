#include <iostream>


bool poweroftwo_loop(int num) {
// incoming on the second loop will be num/2
// an example of what could happen is this 4:
// first check if number is less than or equal to zero,
//next if its equal to 1, returns true because 2^0 is 1
// now returning what happens is it checks if the number is left with zero after %. 4%2 = 0 5%2 = 1 a odd number whill give a false
// also checks recursively goes back: 4->2->1 eventually every power should go down to 1 something like 10 would go
// 10->5 false so the && is not evaluated due to the short circuit.
    if (num <= 0) {
        return false;
    }

    if (num == 1) {
        return true;
    }

    return num%2 == 0 && poweroftwo_loop(num/2);
}

bool poweroftwo_noloop(int n) {
    /* binary representations of power of two
     * 010101010101
     *
     *bitwise function is used, whhat happens during the
     *
     *
     */

    return n > 0 && (n & (n-1)) == 0;
}
int main() {
    // tests power of two with a loop
    bool result = poweroftwo_loop(15);
    std::cout << result << std::endl;

    // tests power of two without a loop
    bool resultnl = poweroftwo_noloop(15);
    std::cout << resultnl << std::endl;

}

