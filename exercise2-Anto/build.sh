#! /bin/bash

g++ -O3 -o main \
    zlasdtest/exercise1/simpletest.cpp zlasdtest/exercise1/fulltest.cpp \
    zlasdtest/exercise2/simpletest.cpp zlasdtest/exercise2/fulltest.cpp \
    zlasdtest/container/container.cpp \
    zlasdtest/test.cpp zmytest/test.cpp \
    zmytest/StackVec/StackVecInt.cpp zmytest/StackVec/StackVecDouble.cpp \
    zmytest/StackVec/StackVecString.cpp main.cpp
