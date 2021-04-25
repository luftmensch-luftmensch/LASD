#! /run/current-system/sw/bin/bash

g++ -O3 -o main \
    zlasdtest/exercise1/simpletest.cpp zlasdtest/exercise1/fulltest.cpp \
    zlasdtest/exercise2/simpletest.cpp zlasdtest/exercise2/fulltest.cpp \
    zlasdtest/container/container.cpp \
    zlasdtest/test.cpp zmytest/test.cpp \
    zmytest/Stack/StackVecInt.cpp zmytest/Stack/StackVecDouble.cpp \
    zmytest/Stack/StackVecString.cpp zmytest/Stack/OperazioniDaEseguire.cpp \
    zmytest/Stack/StackListInt.cpp zmytest/Stack/StackListDouble.cpp \
    zmytest/Stack/StackListString.cpp zmytest/Queue/QueueVecInt.cpp \
    zmytest/Queue/OperazioniQueue.cpp zmytest/Queue/QueueVecDouble.cpp \
    zmytest/Queue/QueueVecString.cpp  zmytest/Queue/QueueListInt.cpp  main.cpp
    #zmytest/Queue/QueueVecInt.cpp zmytest/Queue/QueueVecDouble.cpp \
    #zmytest/Queue/QueueVecString.cpp zmytest/Stack/OperazioniQueue.cpp \
