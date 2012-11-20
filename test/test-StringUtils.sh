#!/bin/bash

g++ -std=c++11 -I ../src -Wall -Wextra -Werror -o StringUtils.test StringUtils.test.cpp -lZUtil

LD_LIBRARY_PATH=/home/daniel/Documents/Programming/C++/libZUtil/.libs:$LD_LIBRARY_PATH ./StringUtils.test

exit $?
