#include <iostream>
#include <ctime>

bool flight(int cap, int pass, float p) {
  int boarding = 0;
  for (int i = 0; i < pass; ++i) {
    if ((double) rand() / RAND_MAX < p) {
      boarding += 1;
    }
  }
  return boarding > cap;
}

int main(int argc, char* argv[]) {
  int loops = 1;
  float p = 0.9;
  int cap1 = 9;
  int pass1 = 10;
  int cap2 = 18;
  int pass2 = 20;
  if (argc >= 2) { loops = std::stoi(argv[1]); }
  if (argc >= 3) { p = std::stof(argv[2]); }
  if (argc >= 4) { cap1 = std::stoi(argv[3]); }
  if (argc >= 5) { pass1 = std::stoi(argv[4]); }
  if (argc >= 6) { cap2 = std::stoi(argv[5]); }
  if (argc >= 7) { pass2 = std::stoi(argv[6]); }
  srand(time(0));

  int f1 = 0;
  int f2 = 0;

  for (int i = 0; i < loops; ++i){
    f1 += flight(cap1, pass1, p);
    f2 += flight(cap2, pass2, p);
  }

  std::cout << "FOCS: " << f1/float(loops) << "\nDMC:  " << f2/float(loops) << std::endl;

  return 0;
}