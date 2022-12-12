#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

using namespace std;
 
void singal_finalizer( int signum ) { 
  exit(signum); 
}

int main() {
  signal(SIGINT, singal_finalizer);
  for ( int i = 0; i < 256; i++) {
    cout << "\\_ 192.168." << to_string(i) << ".0" << endl;
    for ( int x = 0; x < 256; x++) {
      string ip = "timeout 0.03 ping -c 1 192.168." + to_string(i) + "." + to_string(x) + "  >/dev/null 2>/dev/null";
      const char * c = ip.c_str();
      int cmd = system(c);
      if ( cmd == 0 ) {
        cout << "[+] 192.168." << to_string(i) << "." << to_string(x) << endl;
      };
    };
  };
  return 0;
}
