#include <iostream>
#include <ctime>

void weather(int* rain, int* clouds, float p_clouds, float p_cond_rain) {
  for (int i = 0; i < 366; ++i) {
    if ((double) rand() / RAND_MAX < p_clouds) {
      ++*clouds;
      if ((double) rand() / RAND_MAX < p_cond_rain) {
        ++*rain;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  int loops = 1;
  int min_clouds = 50;
  float p_clouds = 0.2;
  float p_cond_rain = 5.0/7;
  if (argc >= 2) { loops = std::stoi(argv[1]); }
  if (argc >= 3) { min_clouds = std::stoi(argv[2]); }
  if (argc >= 4) { p_clouds = std::stof(argv[3]); }
  if (argc >= 5) { p_cond_rain = std::stof(argv[4]); }
  srand(time(0));

  int rain = 0;
  int clouds = 0;

  int cumul_rains = 0;
  int years_w_enough_clouds = 0;

  for (int i = 0; i < loops; ++i){
    weather(&rain, &clouds, p_clouds, p_cond_rain);
    if (clouds >= min_clouds) {
      ++years_w_enough_clouds;
      cumul_rains += rain;
    }
    rain = 0;
    clouds = 0;
  }

  std::cout << "Rainy days avg: " << cumul_rains/float(years_w_enough_clouds) << " (" << years_w_enough_clouds << " trials)" << std::endl;

  return 0;
}