#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cout << "Case " << t << ": ";
    vector<unsigned char> memory;
    memory.resize(100, 0);
    string comm;
    cin >> comm;
    char pointer = 0;

    for(int i=0; i<comm.size(); i++) {
      if(comm[i] == '+')
        memory[pointer]++;
      else if(comm[i] == '-')
        memory[pointer]--;
      else if(comm[i] == '>') {
        pointer++; pointer%=100;
      }
      else if(comm[i] == '<') {
        pointer--; pointer = (pointer+100)%100;
      }
    }

    for(int i=0; i<99; i++) {
      printf("%.2X ", memory[i]);
    }
    printf("%.2X\n", memory[99]);
    
  }
  return 0;
}
