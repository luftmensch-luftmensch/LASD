
#ifndef STACKTEST_HPP
#define STACKTEST_HPP

#include "../../stack/stack.hpp"

/* ************************************************************************** */

template <typename Data>
void PushC(unsigned int& testnum, unsigned int& testerr, lasd::Stack<Data>& stk, const Data& val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Push on the stack of the value \"" << val << "\": ";
    stk.Push(val);
    std::cout << "Correct!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
    tst = false;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void PushM(unsigned int& testnum, unsigned int& testerr, lasd::Stack<Data>& stk, Data val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Push on the stack of the value \"" << val << "\": ";
    stk.Push(std::move(val));
    std::cout << "Correct!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
    tst = false;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void Top(unsigned int& testnum, unsigned int& testerr, lasd::Stack<Data>& stk, bool chk, const Data& val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " Top of the stack with value \"" << stk.Top() << "\": ";
    std::cout << ((tst = ((stk.Top() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void Pop(unsigned int& testnum, unsigned int& testerr, lasd::Stack<Data>& stk, bool chk) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " Pop from the stack: ";
    stk.Pop();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void TopNPop(unsigned int& testnum, unsigned int& testerr, lasd::Stack<Data>& stk, bool chk, const Data& val) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " TopNPop from the stack with value \"" << stk.Top() << "\": ";
    std::cout << ((tst = ((stk.TopNPop() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Stk>
void EqualStack(unsigned int& testnum, unsigned int& testerr, const Stk& stk1, const Stk& stk2, bool chk) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " The two stacks are " << ((tst = (stk1 == stk2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Stk>
void NonEqualStack(unsigned int& testnum, unsigned int& testerr, const Stk& stk1, const Stk& stk2, bool chk) {
  testnum++;
  bool tst;
  try {
    std::cout << " " << testnum << " The two stacks are " << ((tst = (stk1 != stk2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

#endif
