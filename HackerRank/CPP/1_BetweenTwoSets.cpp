#include <iostream>
#include <vector>

using namespace std;

bool areAllFactors(vector<int> a, int n) {
    for (auto const& value : a) {
        if (n % value != 0) {
            return false;
        }
    }
    return true;
}

bool isAFactorOfAll(int n, vector<int> b) {
  for (auto const &value : b) {
    if (value % n != 0) {
      return false;
    }
  }
  return true;
}

int getTotalX(vector<int> a, vector<int> b) {
    int count = 0;
    for (int i = a.back(); i <= b.front(); i++) {
        if (areAllFactors(a, i)) {
            if (isAFactorOfAll(i, b)) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<int> a;
    vector<int> b;

    a.push_back(2);
    a.push_back(4);

    b.push_back(16);
    b.push_back(32);
    b.push_back(96);

    cout<<getTotalX(a, b);

    return 0;
}
