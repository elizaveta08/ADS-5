// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
std::string infx2pstfx(std::string inf) {
  // Функция infx2pstfx должна преобразовывать входную строку,
  // содержащую выражение в инфиксной форме в выходную строку,
  // которая содержит то же выражение в постфиксной фоме.
  // Для отделения операндов друг от друга нужно использовать пробелы.
  std::string resultat;
  char probel = ' ';
  TStack <char, 100> stack;
  for (int i = 0; i < inf.size(); i++) {
    if (prior(inf[i]) == 4) {
      resultat.push_back(inf[i]);
      resultat.push_back(probel);
    } else {
      if (prior(inf[i]) == 0) {
        stack.push(inf[i]);
      } else if (stack.isEmpty()) {
          stack.push(inf[i]);
      } else if ((priority(inf[i]) > prioy(stack.get()))) {
          stack.push(inf[i]);
      } else if (prior(inf[i]) == 1) {
        while (prior(stack.get()) != 0) {
          resultat.push_back(stack.get());
          resultat.push_back(probel);
          stack.pop();
        }
        stack.pop();
      } else {
        char a = prior(inf[i]);
        char b = prior(stack.get());
        while ((a <= b) && (!stack.isEmpty())) {
          resultat.push_back(stack.get());
          resultat.push_back(probel);
          stack.pop();
        }
        stack.push(inf[i]);
      }
    }
  }
  while (!stack.isEmpty()) {
    resultat.push_back(stack.get());
    resultat.push_back(probel);
    stack.pop();
  }
  for (int i = 0; i < resultat.size(); i++) {
    if (resultat[resultat.size() - 1] == ' ')
      resultat.erase(resultat.size() - 1);
  }
  return resultat;
  int calculating(char operation, int x, int y) {
  switch (operation) {
    case '+':
      return x + y;
      break;
    case '-':
      return x - y;
      break;
    case '*':
      return x * y;
      break;
    case '/':
      return x / y;
      break;
  }
  return 0;
  int prior(char op) {
    if (op == '(') {
        return 1;
    }
    if (op == '+' || op == '-') {
        return 2;
    }
    if (op == '*' || op == '/') {
        return 3;
    }
    return -1;
}
  return std::string("");
}
int eval(std::string pref) {
  // Функция eval должна вычислять выражение,
  // записанное в постфиксном виде и выдавать целое значение.
  // Все расчеты ведутся в целых числах!
  TStack <int, 100> stack2;
  int zeloeznachenie = 0;
  for (int i = 0; i < pref.size(); i++) {
    if (prior(pref[i]) == -1) {
      stack2.push(pref[i] - '0');
    } else if (prior(pref[i]) <= 3) {
      int x = stack2.get();
      stack2.pop();
      int y = stack2.get();
      stack2.pop();
      stack2.push(calculating(pref[i], x, y));
    }
  }
  int zeloeznachenie = stack2.get();
  return zeloeznachenie;
  return 0;
}
