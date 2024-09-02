#include <iostream>
#include <ctime>

int roll() {
  return (rand() % 6) + 1;
}

bool flip(){
  return rand() % 2;
}

int main(int argc, char* argv[]) {
  int loops = 1;
  if (argc >= 2) { loops = std::stoi(argv[1]); }
  srand(time(0));

  int sixes = 0;

  for (int i = 0; i < loops; ++i){
    if (flip()) {
      for (int j = 0; j < 6; ++j) {
        if (roll() == 6) { ++sixes; }
      }
    }
    if (flip()) {
      for (int j = 0; j < 6; ++j) {
        if (roll() == 6) { ++sixes; }
      }
    }
  }

  std::cout << sixes/float(loops) << std::endl;

  return 0;
}