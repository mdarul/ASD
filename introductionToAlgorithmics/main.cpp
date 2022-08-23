#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <string>

bool tasks1_1_1();
bool is_value_prime_number(int value);
int tasks1_1_2();
void print_array(int *arr, int n);
std::string tasks1_2_1(int x, int y);

int main() {
    std::cout << tasks1_2_1(6, 3);
    return 0;
}


/*****************************************************************************************************/

//1) Proszę napisać program, który wczytuje liczbę naturalną A i odpowiada na pytanie: ,,czy w którymkolwiek
//z systemów o podstawie 2-16, wszystkie cyfry liczby A zapisanej w tym systemie, są liczbami pierwszymi?"

bool tasks1_1_1() {
    int A;
    std::cout << "Proszę podać liczbę naturalną A: ";
    std::cin >> A;

    for(int i=2; i<=16; i++) {
        int tmp = A;

        while(tmp != 0) {
            int digit_in_system = tmp % i;
            tmp /= i;

            if(!is_value_prime_number(digit_in_system)) {
                break;
            }

            if(tmp == 0) {
                std::cout << "Liczba odpowiada zadanym warunkom w systemie o podstawie " << i << "\n";
                return true;
            }
        }
    }

    std::cout << "Liczba nie odpowiada zadanym warunkom w żadnym z systemów 2-16\n";
    return false;
}

bool is_value_prime_number(int value) {
    int prime_digits[] = { 2, 3, 5, 7, 11, 13 };

    for(int i=0; i < std::size(prime_digits) && value >= prime_digits[i]; i++) {
        if(prime_digits[i] == value) {
            return true;
        }
    }

    return false;
}

/*****************************************************************************************************/

/* Proszę napisać program, który wypełnia tablicę t[N] pseudolosowymi liczbami nieparzystymi z zakresu [1..99],
a następnie Wyznacza i wypisuje różnicę pomiędzy długością najdłuższego znajdującego się w niej ciągu
arytmetycznego o dodatniej różnicy, a długością najdłuższego ciągu arytmetycznego o ujemnej różnicy, przy
założeniu, że kolejnymi wyrazami ciągu są elementy tablicy o kolejnych indeksach. */

int tasks1_1_2() {
    std::cout << "Proszę podać rozmiar tablicy: ";
    int N;
    std::cin >> N;
    int *t = new int[N];
    int longest_increasing_subsequence = 1, longest_decreasing_subsequence = 1, current_difference = 0, current_longest = 0;

    if(N > 2) {
        srand((unsigned int)time(NULL));
        for(int i=0; i < N; i++) {
            t[i] = rand()%49 * 2 + 1;
        }

        int i=1;
        while(i < N) {
            if(t[i] != t[i-1]) {
                current_difference = t[i] - t[i-1];
                current_longest = 1;

                while(i < N && t[i] - t[i-1] == current_difference) {
                    current_longest += 1;
                    i++;
                };

                if(current_difference > 0 && current_longest > longest_increasing_subsequence) {
                    longest_increasing_subsequence = current_longest;
                }
                else if(current_difference < 0 && current_longest >longest_decreasing_subsequence) {
                    longest_decreasing_subsequence = current_longest;
                }
            }
            else {
                i++;
            }
        }
    }

    std::cout << "Długość najdłuższego rosnącego ciągu: " << longest_increasing_subsequence << "\n";
    std::cout << "Długość najdłuższego malejącego ciągu: " << longest_decreasing_subsequence << "\n";

    return longest_increasing_subsequence - longest_decreasing_subsequence;
}

/*****************************************************************************************************/

void print_array(int *arr, int n) {
    for(int i=0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

/*****************************************************************************************************/

/* Dane są trzy operacje na liczbach naturalnych oznaczone literami A, B, C.
A. jeżeli liczba posiada co najmniej 2 cyfry zamienia miejscami dwie ostatnie cyfry w liczbie;
B. mnoży liczbę przez 3;
c. jeżeli liczba posiada co najmniej 2 cyfry usuwa pierwszą cyfrę z liczby.
Proszę napisać funkcję, która szuka sekwencji operacji przekształcającej liczbę naturalną x na y (x!=y) o długości nie większej niż 7. Do funkcji
należy przekazać liczby x, y. Funkcja powinna zwrócić napis złożony z liter ABC realizujący przekształcenie albo łańcuch pustyjeżeli
przekształcenie nie istnieje. Na przykład dla liczb 6,3 funkcja powinna zwrócić napis "BACB". */

int A(int value) {
    if(value < 10) {
        return value;
    }

    int last_digit = value % 10;
    value /= 10;
    int penultimate_digit = value % 10;
    value /= 10;

    return value * 100 + last_digit * 10 + penultimate_digit;
}

int B(int value) {
    return value * 3;
}

int C(int value) {
    if(value < 10) {
        return value;
    }

    int comparing_number = 10;
    while(value > comparing_number * 10) {
        comparing_number *= 10;
    }

    return value % comparing_number;
}

bool task1_2_1_recursive(int x, int y, std::string operations, std::string &outcome) {
    if(x == y) {
        if(outcome.length() == 0 || operations.length() < outcome.length()) {
            outcome = operations;
            return true;
        }

        return false;
    }

    if(operations.length() == 7) return false;

    if(x > 10) task1_2_1_recursive(A(x), y, operations + 'A', outcome);
    if(x > 10) task1_2_1_recursive(C(x), y, operations + 'C', outcome);
    task1_2_1_recursive(B(x), y, operations + 'B', outcome);

    return false;
}

std::string tasks1_2_1(int x, int y) {
    std::string outcome = "";
    task1_2_1_recursive(x, y, "", outcome);
    std::cout << "Found sequence: " << outcome << "\n";
    return outcome;
}
