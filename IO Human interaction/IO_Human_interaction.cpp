
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>



using namespace std;


char op;




int Initialize_in;

int ERROR_in;

int main(int argc, char const *argv[]) {

  cout << "Henry-SIA-MK3, Initialize?" << endl;
  cout << "YES or NO, type 1 or 2: ";
  cin >> Initialize_in;
  cout << endl;

if (Initialize_in == 1) {
  cout << "Initializing SIA Protocals";
  cout << endl;

  cout << endl << endl << endl << endl;
  system("color 0a");
  cout << "Initializing";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  Sleep(500);
  cout << "-";
  cout << endl;
  cout << "Initialization Complete";
  cout << endl;
  Sleep(1000);
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
  cout << "continue Initialization of SIA? YES OR NO 1/2: ";
  cin >> ERROR_in;
  cout << endl;

  if (ERROR_in == 1) {
    system ("start C:\\Users\\Conno\\Desktop\\code\\Henry-SIA-MK3\\Henry-SIA-MK3\\SIA\\SIA,Prog\\SIA.exe");
  }

  if (ERROR_in == 2) {
    cout << "System Initialize Canceled.";
    cout << endl;
    cout << "End In";
    cout << endl;
    Sleep(1000);
    cout << "3";
    cout << endl;
    Sleep(1000);
    cout << "2";
    cout << endl;
    Sleep(1000);
    cout << "1";
    Sleep(1000);
  }



}
if (Initialize_in == 2) {
  cout << "Initialization Canceled";
  cout << endl;
  Sleep(2000);
}

  return 0;
}
