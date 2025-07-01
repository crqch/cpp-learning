#include <cmath>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

char toLowerCase(char character) {
  if (int(character) >= 59 && int(character) <= 91) {
    return character + 32;
  }
  return character;
}

double stringToDouble(string number) {
  double current = 0;
  int decimal = 1;
  for (int i = 0; i < number.length(); i++) {
    if (number[i] == '.') {
      decimal = i + 1;
      continue;
    }
    current += ((int)number[i] - 48) * pow(10, i);
  }
  return current / decimal;
}

struct CalculatorEntry {
  double number;
  char operation;
};

void calculator() {
  cout << "   Calculator app\n-==-==-==-==-==-==-\nYour available operations "
          "are:\n\nsubtraction (-)\naddition (+)\nmultiplication (*)\ndivision "
          "(/)\n\n> ";
  string combination;
  cin >> combination;
  double result = 0;
  string current = "";
  vector<CalculatorEntry> calculatorEntries;
  // Dot for parsing the final number
  combination = combination + ".";

  for (int i = 0; i < combination.length(); i++) {
    if (((int)combination[i] >= 48 && (int)combination[i] <= 57)) {
      current = current + combination[i];
    } else {
      double temporary = stringToDouble(current);
      calculatorEntries.insert(calculatorEntries.end(), {temporary, 'n'});
      if (combination[i] == 'x' || combination[i] == '-' ||
          combination[i] == '+' || combination[i] == '/') {
        calculatorEntries.insert(calculatorEntries.end(), {0, combination[i]});
      }
      current = "";
    }
  }

  bool noMultiplications = false;
  bool loop = true;
  double previousNumber;
  char action;

  while (loop) {
    bool tNoMultiplications = true;
    int size = 0;
    for (auto it = calculatorEntries.begin(); it != calculatorEntries.end();) {
      size += 1;
      if (it->operation == 'n') {
        if (!previousNumber) {
          previousNumber = it->number;
          it++;
          continue;
        }
        if (action) {
          double result;
          if (action == 'x') {
            tNoMultiplications = false;
            result = previousNumber * it->number;
          }
          if (action == '/') {
            tNoMultiplications = false;
            result = previousNumber / it->number;
          }
          if (action == '+' && noMultiplications) {
            result = previousNumber + it->number;
          }
          if (action == '-' && noMultiplications) {
            result = previousNumber + it->number;
          }
          if (!result) {
            previousNumber = it->number;
            action = 0;
            it++;
            continue;
          }
          it = calculatorEntries.erase(prev(it), next(it));
          it = calculatorEntries.insert(it, {result, 'n'});
          previousNumber = 0;
          action = 0;
        }
      } else {
        action = it->operation;
        it++;
        continue;
      }
    }
    if (size == 1) {
      loop = false;
    }
    if (tNoMultiplications) {
      noMultiplications = true;
    }
  }
  cout << "Solution is: " << calculatorEntries.begin()->number << endl;
}

void hub() {
  cout
      << "Welcome to tools utilizing "
         "cin\n=============================\n\nPlease select one of following "
         "numbers to launch specific app:\n[0] - Calculator\n[X] - Exit\n > ";
  char pickedOption;
  cin >> pickedOption;
  switch (pickedOption) {
  case '0':
    calculator();
    break;
  case 'X':
    break;
  default:
    cout << "Seems like you didn't type in a correct option! Try "
            "again.\n";
    break;
  }
  if (pickedOption != 'X') {
    hub();
  }
}

int main() {
  hub();

  return 0;
}
