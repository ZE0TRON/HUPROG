#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
class Event {
  public:
    char type; // 'Y' > Yakit Tuketimi, 'H' > hedef, 'D' > delik , 'B' > benzin istasyonu, 'T' tamirci
    int time;
    double data;
    Event(char t, int ti, double d): type(t), time(ti), data(d) {}
    Event() {}
    Event(char t, int ti): type(t), time(ti) {}
};

bool can(vector<Event>& events, double tank) {
  double consumption = 0;
  double leak = 0;
  int last_time = 0;
  double curtank = tank;
  for(int i=0; i<events.size(); i++) {
    Event& event = events[i];
    curtank -= (event.time-last_time) * (consumption+leak);
    if(curtank < 0) return false;
    last_time = event.time;
    if(event.type == 'Y') {
      consumption = event.data;
    } else if (event.type == 'H') {
      return true;
    } else if (event.type == 'D') {
      leak += 1;
    } else if (event.type == 'T') {
      leak = 0;
    } else if (event.type == 'B') {
      curtank = tank;
    }
  }
}

int main() {
  while(true) {
    int time;
    string hold;
    double data;
    vector<Event> events;
    bool end = false;
    while(true) {
      cin >> time >> hold;
      if(hold == string("Yakit")) {
        cin >> hold >> data;
        events.push_back(Event('Y', time, data/100));
        if(data == 0 && events.size() == 1) {
          end = true;
          break;
        }
      } else if(hold == string("Hedef")) {
        events.push_back(Event('H', time));
        break;
      } else if(hold == string("Delik")) {
        events.push_back(Event('D', time));
      } else if(hold == string("Benzin")) {
        cin >> hold;
        events.push_back(Event('B', time));
      } else if(hold == string("Tamirci")) {
        events.push_back(Event('T', time));
      }
    }
    if(end) break;

    double lo = 0;
    double hi = 1058709437979123;
    while(abs(hi-lo) > 1e-9) {
      double mid = (hi + lo) / 2;
      if(can(events, mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    printf("%.3f\n",(hi+lo)/2);

  }  
}
