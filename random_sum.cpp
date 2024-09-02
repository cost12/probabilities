#include <iostream>
#include <ctime>

int sum(int max) {
  int tries = 0;
  int sum = 0;
  while (sum <= max) {
    sum += (rand() % max) + 1;
    ++tries;
  }
  return tries;
}

int main(int argc, char* argv[]) {
  int loops = 1;
  int max = 100;
  if (argc >= 2) { loops = std::stoi(argv[1]); }
  if (argc >= 3) { max = std::stoi(argv[2]); }
  srand(time(0));

  int tries = 0;

  for (int i = 0; i < loops; ++i){
    tries += sum(max);
  }

  std::cout << tries/float(loops) << std::endl;

  return 0;
}