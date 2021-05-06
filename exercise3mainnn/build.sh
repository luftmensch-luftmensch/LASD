#! /bin/bash

g++ -O3 -o main \
  zlasdtest/exercise1/simpletest.cpp zlasdtest/exercise1/fulltest.cpp \
  zlasdtest/exercise2/simpletest.cpp zlasdtest/exercise2/fulltest.cpp \
  zlasdtest/exercise3/simpletest.cpp zlasdtest/exercise3/fulltest.cpp \
  zlasdtest/container/container.cpp \
  zlasdtest/test.cpp zmytest/test.cpp \
  zmytest/BinaryTree/BinaryTreeVec/BinaryTreeVecInt.cpp \
  zmytest/BinaryTree/BinaryTreeVec/BinaryTreeVecFloat.cpp \
  zmytest/BinaryTree/BinaryTreeVec/BinaryTreeVecString.cpp \
  zmytest/BinaryTree/BinaryTreeVec/OperazioniDaEseguire.cpp \
  zmytest/BinaryTree/BinaryTreeList/BinaryTreeListInt.cpp \
  zmytest/BinaryTree/BinaryTreeList/BinaryTreeListFloat.cpp \
  zmytest/BinaryTree/BinaryTreeList/BinaryTreeListString.cpp \
  main.cpp
