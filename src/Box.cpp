#include <bits/stdc++.h>

using namespace std;
// Implement the class Box
// l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

// Overload operator < as specified
// bool operator<(Box& b)

// Overload operator << as specified
// ostream& operator<<(ostream& out, Box& B)

class Box {
  friend ostream &operator<<(ostream &, const Box &);

public:
  Box() {
    length = 0;
    breadth = 0;
    height = 0;
  }
  Box(int l, int b, int h) : length(l), breadth(b), height(h) {}
  Box(const Box &b) : length(b.length), breadth(b.breadth), height(b.height) {}

  const int getLength() const { return length; }
  const int getBreadth() const { return breadth; }
  const int getHeight() const { return height; }
  const long long CalculateVolume() const {
    return 1LL * length * breadth * height;
  }

  bool operator<(const Box &);

private:
  int length, breadth, height;
};

bool Box::operator<(const Box &b) {
  if (length < b.length) {
    return true;
  } else if (breadth < b.breadth && length == b.length) {
    return true;
  } else if (height < b.height && breadth == b.breadth && length == b.length) {
    return true;
  } else {
    return false;
  }
}

ostream &operator<<(ostream &os, const Box &b) {
  os << b.length << ' ' << b.breadth << ' ' << b.height;
  return os;
}

void check2() {
  int n;
  cin >> n;
  Box temp;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      cout << temp << endl;
    }
    if (type == 2) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      temp = NewBox;
      cout << temp << endl;
    }
    if (type == 3) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      if (NewBox < temp) {
        cout << "Lesser\n";
      } else {
        cout << "Greater\n";
      }
    }
    if (type == 4) {
      cout << temp.CalculateVolume() << endl;
    }
    if (type == 5) {
      Box NewBox(temp);
      cout << NewBox << endl;
    }
  }
}

int main() { check2(); }