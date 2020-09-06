#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
  virtual void getdata() = 0;
  virtual void putdata() const = 0;
  virtual ~Person() {}

protected:
  string name;
  int age;
};

class Professor : public Person {
public:
  Professor() {
    cur_id = id;
    ++id;
  }
  void getdata() override { cin >> name >> age >> publications; }
  void putdata() const override {
    cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << '\n';
  }

private:
  int publications;
  int cur_id;

  static int id;
};

class Student : public Person {
public:
  Student() {
    cur_id = id;
    ++id;
  }
  void getdata() override {
    cin >> name >> age;
    int mark;
    for (int i = 0; i != 6; ++i) {
      cin >> mark;
      marks[i] = mark;
    }
  }
  void putdata() const override {
    int sum = 0;
    for (int i = 0; i != 6; ++i) {
      sum += marks[i];
    }
    cout << name << ' ' << age << ' ' << sum << ' ' << cur_id << '\n';
  }

private:
  int marks[6];
  int cur_id;

  static int id;
};

int Student::id = 1;
int Professor::id = 1;

int main() {

  int n, val;
  cin >> n; // The number of objects that is going to be created.
  Person *per[n];

  for (int i = 0; i < n; i++) {

    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else
      per[i] = new Student; // Else the current object is of type Student

    per[i]->getdata(); // Get the data from the user.
  }

  for (int i = 0; i < n; i++) {
    per[i]->putdata();
  } // Print the required output for each object.

  for (int i = 0; i != n; ++i) {
    delete per[i];
  }

  return 0;
}
