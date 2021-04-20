#include <iostream>
#include <string>
#include <fstream>
#include "colors.h"
#include "TicTacToe.h"
#include "GuessMyNum.h"

#define PURPLE cout << "\033[0;35m" << endl;
#define WHITE cout << "\033[0;37m" << endl;
#define RED cout << "\033[0;31m" << endl;
#define GREEN cout << "\033[0;32m" << endl;

  int menu();

  bool isLoggedIN () {

    string username, password, un, pw;
    
    WHITE
    cout << "Username: ";
    PURPLE
    cin >> username;
    WHITE
    cout << "Password: ";
    PURPLE
    cin >> password;
    WHITE

    ifstream read(username + ".txt");
    getline (read, un);
    getline (read, pw);
    
    if ( un == username && pw == password ) {

      return true;

    } else {

      return false;

    }

  }

int login () {

  int choice;

  cout << "1. Register \n";
  cout << "2. Login \n";
  cin >> choice;

  if ( choice == 1 ) {

    string username, password;
    
    WHITE
    cout << "Username: ";
    PURPLE
    cin >> username;
    WHITE
    cout << "Password: ";
    PURPLE
    cin >> password;
    WHITE

    ofstream file;
    file.open(username + ".txt");

    file << username << endl << password;
    file.close();

    login();

  } else if ( choice == 2 ) {

    bool status = isLoggedIN();

    if ( !status ) {
      
      RED
      cout << "Login Failed! \a \n";
      return 0;

    } else if ( status ) {
      
      GREEN
      cout << "Login Successful! \a \n \n";
      menu();

    }

  }

}

int main() {

  login();


  return 0;
}

int menu() {

  int choice;

  BLUE
  std::cout << "Welcome to Game Player! \n\n";
  std::cout << "1. Tic Tac Toe \n";
  std::cout << "2. Guess My Number \n";
  std::cout << "More coming soon! \n"; 
  PURPLE
  std::cin >> choice;

  if (choice == 1) {

    ticTacToe();

  } else if (choice == 2) {

    guessMyNum();

  } else {

    cout << "Invalid Choice! \a \n";
    menu();

  }

}
