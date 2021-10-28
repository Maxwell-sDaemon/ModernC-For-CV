#include <cstdlib>
#include <iostream>
#include <random>

#define MAX_NUMBER 5
#define MIN_NUMBER 0

int main() {
  std::random_device rd;
  std::uniform_int_distribution<int> dist(MIN_NUMBER, MAX_NUMBER);
  bool game_end;
  int program_guess = dist(rd);
  int guess;

  while (true) {
    std::cin >> guess;
    if (std::cin.fail()) {
      std::cout << "[WARNING] : Number must be between 0 and 99" << std::endl;
    } else if (guess == program_guess) {
      std::cout << "congrat lad" << std::endl;
      return EXIT_SUCCESS;
    } else if (guess < program_guess) {
      std::cout << "your guess is smaller. " << std::endl;
    } else if (guess > program_guess) {
      std::cout << "your guess is largee." << std::endl;
    } else {
      return EXIT_FAILURE;
    }
  }
}