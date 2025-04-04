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

    // ( this set of Comments produced by ChatGPT)
    /* Check if n is positive
    * Powers of two must be greater than zero
    * (Zero and negative numbers are not powers of two)

    * Check if n has exactly one bit set in its binary form
    * If n is a power of two:
    * Example: n = 4 (0100), n - 1 = 3 (0011)
    * (n & (n - 1)) = 0100 & 0011 = 0000 -> means it's power of two

    * For non-power of two numbers:
    * Example: n = 5 (0101), n - 1 = 4 (0100)
    * (n & (n - 1)) = 0101 & 0100 = 0100 (non-zero), so it's not a power of two
    */

    return n > 0 && (n & (n-1)) == 0;
}

int gcd(int a, int b) {

    /* using Euclidean algorithm we get
     * the greatest common denominator from this function
     * NOTES ON THE EA: the Euclidean algorithm finds the greatest common divisor (GCD) of two numbers by repeatedly replacing the larger number with the
     * remainder when divided by the smaller number, until the remainder is zero, at which point the GCD is the non-zero number.
     */
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    /*
     * if the function starts at 2 then the input is tested and compared
     * to input divided by 2
     */
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void testPowerOfTwo() {
    // use an array to both have a input and a expected outcome

    int inputs[] = {1, 16, 35};
    bool expected[] = {true, true, false};
    int totalTests = 3;

    // loop goes through checks if each of the inputs returns the expected passed means it returned the correct
    for (int i = 0; i < totalTests; ++i) {
      bool result = poweroftwo_loop(inputs[i]);

    //uncheck the comment to test the no loop version make sure to comment the other one out
    //  bool result = poweroftwo_noloop(inputs[i]);

        if (result == expected[i]) {
            std::cout << "PASSED" << std::endl;
        } else {
            std::cout << "FAILED" << std::endl;
        }
    }
}

//when using this code the & symbol makes sure that we are passing by reference to change the values later on
void reduce(int& numerator, int& denominator) {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

// using a struct for code readability a changing
struct FractionTest {
    int numerator;
    int denominator;
    int expectedNumerator;
    int expectedDenominator;
};

void testReduceFraction() {
    // array of all the tests
    // each of the arrays value is assigned in order of how the struct has it EX. 4 Numerator, 8 Denominator, 1 expectedNumerator, 2 expectedDenominator
    FractionTest tests[] = {
        {4, 8, 1, 2},
        {10, 20, 1, 2},
        {3, 9, 1, 3},
        {8, 12, 2, 3}
    };


    // loops through each test
    for (auto& test : tests) {

        // save the num and denom variables
        int num = test.numerator;
        int denom = test.denominator;

        reduce(num, denom);


        // check if the result matches the expected reduced form
        if (num == test.expectedNumerator && denom == test.expectedDenominator) {
            std::cout << "PASSED" << std::endl;
        } else {
            std::cout << "FAILED" << std::endl;
        }
    }
}


void testIsPrime() {

    // following the same format for my test for the poweroftwo methods
    int inputs[] = {5, 7, 16};
    bool expected[] = {true, true, false};
    int totalTests = 3;

    // loop goes through checks if each of the inputs returns the expected passed means it returned the correct
    for (int i = 0; i < totalTests; ++i) {
        bool result = isPrime(inputs[i]);

        if (result == expected[i]) {
            std::cout << "PASSED" << std::endl;
        } else {
            std::cout << "FAILED" << std::endl;
        }
    }
}





int main() {
    // tests power of two with a loop and without check the test to configure for which
    // testPowerOfTwo();

    // testReduceFraction();
    testIsPrime();
}

