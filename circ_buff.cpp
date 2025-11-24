/*
 * Translation of my circular buffer in C to C++
 */

#include <iostream>
#include <array>

constexpr int size = 64;

class Buffer {
  private:
    int ipush;
    int ipop;
    std::array<int, size> data;
  public:
    Buffer() {
      ipush = 0;
      ipop = 0;
    }
    bool isempty() {
      return ipush == ipop;
    }
    bool isfull() {
      return (ipush + 1)%size == ipop;
    }
    bool push(int val) {
      if (isfull()) {
        return false;
      }
      data[ipush] = val;
      ipush = (ipush + 1)%size;
      return true;
    }
    bool pop(int& val) {
      if (isempty()) {
        return false;
      }
      val = data[ipop];
      ipop = (ipop + 1)%size;
      return true;
    }
};

int main() {
  Buffer b;
  int val;

  for (int i = 0; i < size -1; ++i) {
    b.push(i);
  }
  for (int i = 0; i < size -1; ++i) {
    b.pop(val);
    std::cout << val << '\n';
  }

  return 0;
}
