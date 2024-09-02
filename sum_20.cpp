#include <iostream>

int main(){
  int x1[2] = {-2, 10};
  int x2[2] = { 2,  8};
  int x3[2] = { 0, 15};

  int success = 0;

  for (int i = x1[0]; i <= x1[1]; ++i) {
  	for (int j = x2[0]; j <= x2[1]; ++j) {
  	  for (int k = x3[0]; k <= x3[1]; ++k) {
  	  	if (i + j + k == 20) {
  	  	  success += 1;
  	  	}
  	  }
  	}
  }

  std::cout << success << std::endl;

  return 0;
}