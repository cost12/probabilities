#include <vector>
#include <iostream>
#include <ctime>

int randomness(std::vector<bool> &a, std::vector<bool> &b) {
  for (unsigned int i = 0; i < a.size(); ++i) {
  	a[i] = rand() % 2;
  }
  for (unsigned int i = 0; i < b.size(); ++i) {
  	b[i] = rand() % 2;
  }
  int count = 0;
  for (unsigned int i = 0; i < a.size(); ++i) {
  	if (a[i] || b[i]) {
  	  ++count;
  	}
  }
  //std::cout << count << std::endl;
  return count;
}

int main(int argc, char* argv[]) {
  int loops = 1;
  int size = 10;
  int goal = 5;
  if (argc >= 2) {
    loops = std::stoi(argv[1]);
  }
  if (argc >= 3) {
  	size = std::stoi(argv[2]);
  }
  if (argc >= 4) {
  	goal = std::stoi(argv[3]);
  }
  srand(time(0));

  std::vector<bool> a(size, false);
  std::vector<bool> b(size, false);
  int c = 0;
  int count = 0;

  for (int i = 0; i < loops; ++i){
    c = randomness(a, b);
    if (c == goal) {
      ++count;
    }
  }

  std::cout << count/float(loops) << std::endl;

  return 0;
}