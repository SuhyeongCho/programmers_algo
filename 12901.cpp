#include <string>
#include <vector>

using namespace std;

int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

string getDay(int day) {
  switch (day) {
    case 0: return "SUN";
    case 1: return "MON";
    case 2: return "TUE";
    case 3: return "WED";
    case 4: return "THU";
    case 5: return "FRI";
    case 6: return "SAT";
  }
}

string solution(int a, int b) {
  int day = 5;
  for (int i = 0 ; i < a - 1 ; i++) {
    day += months[i];
  }
  day += b - 1;
  return getDay(day % 7);
}