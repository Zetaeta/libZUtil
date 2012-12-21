
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libZUtil.la

CXXFLAGS=
AM_CXXFLAGS=

TESTS = test/test-all.sh

libZUtil_la_includedir = $(includedir)/Util

libZUtil_la_CXXFLAGS = -g -fPIC -std=c++11 -Wall

libZUtil_la_LDFLAGS =
libZUtil_la_LIBADD = -lz -lrt

libZUtil_la_SOURCES = src/Endian.cpp src/Unicode.cpp src/StringUtils.cpp \
    src/ErrorHandler.cpp src/Time.cpp

libZUtil_la_include_HEADERS = src/Endian.h src/Unicode.hpp src/MaybePointer.hpp \
    src/StringUtils.hpp src/stlfwd.hpp src/ErrorHandler.hpp src/ErrorType.hpp \
    src/InvalidFileDescriptor.hpp src/InvalidIOOperation.hpp src/IOError.hpp \
    src/IOException.hpp src/InvalidArgument.hpp src/Rounding.hpp src/Time.hpp \
    src/Throw.hpp src/EOFException.hpp
