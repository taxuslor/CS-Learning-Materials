/* CS106B Assign1: Getting Your C++ Legs
 * Part1: Perfect Numbers
 *
 * Definition of a Perfect Number:
 * A perfect number is an integer that is equal to the sum of its proper divisors.
 * A number's proper divisors are all positive numbers that evenly divide it, excluding itself.
 * The first perfect number is 6 = 1 + 2 + 3. The next one is 28 = 1 + 2 + 4 + 7 + 14.
 */

#include <iostream>

using namespace std;

// First Trial: An Exhaustive Algorithm

/* This function takes in a number n and calculates the sum
 * of all proper divisors of n, excluding itself.
 *
 * Note: `long` is a C++ type that allows for a larger range of values than the
 * `int` type. It is a variant of the int type, and for all intents and purposes,
 * you can treat it like you would an int.
 */
long divisorSum(long n) {
    long total = 0;
    for (long divisor = 1; divisor < n; divisor++) {
        if (n % divisor == 0) {
            total += divisor;
        }
    }
    return total;
}

/* This function is provided a number n and returns a boolean
 * (true/false) value representing whether or not the number is
 * perfect. A perfect number is a non-zero positive number whose
 * sum of its proper divisors is equal to itself.
 */
bool isPerfect(long n) {
    return (n != 0) && (n == divisorSum(n));
}

/* This function performs an exhaustive search for perfect numbers.
 * It takes as input a number called `stop` and searches for perfect
 * numbers between 1 and `stop`. Any perfect numbers that are found will
 * be printed out to the console.
 */
void findPerfects(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfect(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush;
    }
    cout << "Done searching up to " << stop << endl;
}

/*
 * For case0: 2.26s;
 *     case1: 6.69s;
 *     case2: 26.36s;
 *     case3: 105.08s;
 */
void observingRuntime() {
    int testcase[4] = {40000, 80000, 160000, 320000};
    for (int i = 0; i < 4; ++i) {
        cout << "Testcase" << i << ": " << endl;
        findPerfects(testcase[i]);
        cout << endl;
    }
}

// Second Trial: SmarterWay

/* We can take advantage of the fact that each divisor that is less than
 * the square root is paired up with a divisor that is greater than the square root.
 */
long smarterSum(long n) {
    long total = 0;
    for (long divisor = 1; divisor * divisor <= n; divisor++) {
        if (n % divisor == 0) {
            total += divisor;
            if (divisor * divisor != n && divisor > 1) {
                total += n / divisor;
            }
            if (total > n) {
                return total;
            }
        }
    }
    return total;
}

bool isPerfectSmarter(long n) {
    return (n != 0) && (n != 1) && (n == smarterSum(n));
}

void findPerfectsSmarter(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfectSmarter(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush;
    }
    cout << "Done searching up to " << stop << endl;
}

/*
 * For all 4 cases: less than 2s.
 */
void observingRuntimeSmarter() {
    int testcase[4] = {40000, 80000, 160000, 320000};
    for (int i = 0; i < 4; ++i) {
        cout << "Testcase" << i << ": " << endl;
        findPerfectsSmarter(testcase[i]);
        cout << endl;
    }
}

// Third Trial: Turbo-charging with Euclid

/* A Mersenne prime is a prime number that is one less than a power of two.
 * In other words, it takes the form 2^n - 1 for some integer n.
 * For example, the prime number 31 can be expressed as 2^5 - 1, and thus is a Mersenne prime.
 *
 * An intriguing relationship between perfect numbers and the Mersenne primes:
 * Specifically, if 2^k - 1 is prime, then 2^(k-1)*(2^k - 1) is a perfect number
 *
 * In writing this function, you should implement Euclid's method (described below) to find the nth perfect number:
 * 1.Start by setting k = 1.
 * 2.Calculate m = 2^k - 1 (use the C++ library function pow)
 * 3.Determine whether m is prime or composite. (a simple isPrime helper that uses an exhaustive loop is just fine)
 * 4.If m is prime, then calculate 2^(k-1) * (2^k - 1). This is the associated perfect number.
 * 5.Increment k and repeat until you have found the nth perfect number.
 * The call findNthPerfectEuclid(n) should return the nth perfect number.
 */

bool isPrime(long n) {
    if (n == 1) return false;
    for (long i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/* Takes less than 1s to find the first five Perfect Number.
 */
long findNthPerfectEuclid(long n) {
    long k = 1, perfectNumber, order = 0;
    while (order < n) {
        long m = ::pow(2, k) - 1;
        if (isPrime(m)) {
            order++;
            perfectNumber = m * ::pow(2, k - 1);
            cout << "The " << order << "th Perfect Number: " << perfectNumber << endl;
        }
        k++;
    }
    return perfectNumber;
}

int main() {
    //observingRuntime();
    //observingRuntimeSmarter();
    //findNthPerfectEuclid(5);
    return 0;
}
