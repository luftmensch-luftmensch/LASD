#! /bin/bash

g++ -O3 -o main \
  zlasdtest/exercise1/simpletest.cpp zlasdtest/exercise1/fulltest.cpp \
  zlasdtest/exercise2/simpletest.cpp zlasdtest/exercise2/fulltest.cpp \
  zlasdtest/exercise3/simpletest.cpp zlasdtest/exercise3/fulltest.cpp \
  zlasdtest/container/container.cpp \
  zlasdtest/test.cpp zmytest/test.cpp \
  zmytest/BinaryTreeVec/binarytreevec.cpp zmytest/BinaryTreeLst/binarytreelst.cpp \
  zmytest/BinaryTreeVec/BinaryTreeVecInt/binarytreevecint.cpp \
  zmytest/BinaryTreeVec/BinaryTreeVecFloat/binarytreevecfloat.cpp \
  zmytest/BinaryTreeVec/BinaryTreeVecString/binarytreevecstring.cpp \
  zmytest/BinaryTreeLst/BinaryTreeLstInt/binarytreelstint.cpp \
  zmytest/BinaryTreeLst/BinaryTreeLstFloat/binarytreelstfloat.cpp \
  zmytest/BinaryTreeLst/BinaryTreeLstString/binarytreelststring.cpp \
  main.cpp
