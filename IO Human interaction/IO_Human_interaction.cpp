
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>



using namespace std;


char op;




int Initialize_in;

int main(int argc, char const *argv[]) {

  cout << "Henry-SIA-MK3, Initialize?" << endl;
  cout << "YES or NO, type 1 or 2:";
  cin >> Initialize_in;
  cout << endl;

if (Initialize_in == 1) {
  cout << "Initializing SIA Protocals";
  cout << endl;

  cout << endl << endl << endl << endl;
  system("color 0a");
  cout << "Initializing";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  Sleep(1000);
  cout << "-";
  cout << endl;
  cout << "Initialization Complete";
  cout << endl;
  Sleep(3000);
  system("color c7");
  Sleep(300);
  system("color 07");
  Sleep(300);
  system("color c7");
  Sleep(300);
  system("color 07");
  Sleep(300);
  system("color c7");
  Sleep(300);
  system("color 07");
  Sleep(300);
  system("color 0c");

  cout << "WARNING, HENRY/ROBOTIC ARM NOT DETECTED";
  cout << endl;
  Sleep(2000);
  cout << "end in";
  cout << endl;
  Sleep(1000);
  cout << "3";
  cout << endl;
  Sleep(1000);
  cout << "2";
  cout << endl;
  Sleep(1000);
  cout << "1";
  cout << endl;
  Sleep(1000);


}
if (Initialize_in == 2) {
  cout << "Initialization Canceled";
  cout << endl;
  Sleep(2000);
}

  return 0;
}
