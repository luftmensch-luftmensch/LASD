#! /bin/bash

g++ -O3 -o main zlasdtest/exercise1/simpletest.cpp zlasdtest/exercise1/fulltest.cpp
\ zlasdtest/exercise2/simpletest.cpp zlasdtest/exercise2/fulltest.cpp zlasdtest/container/container.cpp
\ zlasdtest/test.cpp zmytest/test.cpp zmytest/Stack/stack.cpp zmytest/Queue/queue.cpp
\ zmytest/Queue/QueueList/queuelist.cpp
\ zmytest/Stack\StackList\stacklist.cpp zmytest/Queue/QueueVec/queuevec.cpp 
\ zmytest/Stack/StackVec/stackvec.cpp main.cpp
