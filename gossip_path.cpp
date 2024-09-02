#include <ctime>
#include <iostream>

bool gossip(){
  bool friends[4][4];

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < i; ++j) {
      int r = rand() % 2;
      friends[i][j] = r;
      friends[j][i] = r;
    }
  }
  return (friends[0][1] || (friends[0][2] && friends[2][1]) || (friends[0][3] && friends[3][1]) || 
         (friends[0][2] &&  friends[2][3] && friends[3][1]) || (friends[0][3] &&  friends[3][2] && friends[2][1]));
}

int main(int argc, char* argv[]) {
  int loops = 1;
  if (argc == 2) {
    loops = std::stoi(argv[1]);
  }
  srand(time(0));

  int success = 0;
  for (int i = 0; i < loops; ++i){
    if (gossip()){
      success += 1;
    }
  }

  std::cout << success / (loops + 0.0) << std::endl;

  return 0;
}