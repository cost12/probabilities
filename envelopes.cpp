#include <vector>
#include <iostream>
#include <ctime>

void pick_envelopes(int* p1, int* p2) {
  std::vector<int> envelopes {0,1,2,3,4,5,6,7,8,90};
  for (int i = 0; i < 10; ++i) {
    int r = rand() % envelopes.size();
    if (i % 2 == 0){
      *p1 += envelopes[r];
    } else {
      *p2 += envelopes[r];
    }
    envelopes.erase(envelopes.begin() + r);
  }
}

int main(int argc, char* argv[]) {
  int loops = 1;
  if (argc == 2) {
    loops = std::stoi(argv[1]);
  }
  srand(time(0));

  int p1 = 0;
  int p2 = 0;

  for (int i = 0; i < loops; ++i){
    pick_envelopes(&p1, &p2);
  }

  std::cout << "P1: " << p1/(126.0*loops) << "\nP2: " << p2/(126.0*loops) << std::endl;

  return 0;
}