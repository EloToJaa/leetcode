#include <bits/stdc++.h>

using namespace std;

class ParkingSystem {
 public:
  int big, medium, small;

  ParkingSystem(int big, int medium, int small) {
    this->big = big;
    this->medium = medium;
    this->small = small;
  }

  bool addCar(int carType) {
    if (carType == 1) {
      big--;
      if (big < 0) return false;
    } else if (carType == 2) {
      medium--;
      if (medium < 0) return false;
    } else if (carType == 3) {
      small--;
      if (small < 0) return false;
    }
    return true;
  }
};

int main() {
  ParkingSystem ps = ParkingSystem(1, 1, 0);
  cout << ps.addCar(1) << " ";
  cout << ps.addCar(2) << " ";
  cout << ps.addCar(3) << " ";
  cout << ps.addCar(1) << "\n";
}
