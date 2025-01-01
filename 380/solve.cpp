#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
 private:
  unordered_set<int> us;

 public:
  RandomizedSet() { srand(static_cast<int>(time(nullptr))); }

  bool find(int val) { return us.find(val) != us.end(); }

  bool insert(int val) {
    if (find(val)) return false;
    us.insert(val);
    return true;
  }

  bool remove(int val) {
    if (!find(val)) return false;
    us.erase(val);
    return true;
  }

  int getRandom() {
    int randomIndex = rand() % us.size();
    auto it = us.begin();
    advance(it, randomIndex);
    return *it;
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
