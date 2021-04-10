#! /bin/bash

g++ -O3 -o main \
    zlasdtest/test.cpp  zlasdtest/exercise1/fulltest.cpp  zlasdtest/exercise1/simpletest.cpp  zlasdtest/container/container.cpp \
    zmytest/list/testlist.cpp  zmytest/vector/testvector.cpp  zmytest/menu.cpp \
    main.cpp 
