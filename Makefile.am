
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libZUtil.la

TESTS = test/test-all.sh

libZUtil_la_includedir = $(includedir)/Util

libZUtil_la_CXXFLAGS = -g -fPIC -std=c++11 -Wall -pg

libZUtil_la_LDFLAGS = -pg
libZUtil_la_LIBADD = -lendian -lIOStream -lz

libZUtil_la_SOURCES = src/Endian.cpp src/Unicode.cpp src/StringUtils.cpp \
    src/ErrorHandler.cpp

libZUtil_la_include_HEADERS = src/Endian.h src/Unicode.hpp src/MaybePointer.hpp \
    src/StringUtils.hpp src/stlfwd.hpp src/ErrorHandler.hpp src/ErrorType.hpp \
    src/InvalidFileDescriptor.hpp src/InvalidIOOperation.hpp src/IOError.hpp \
    src/IOException.hpp src/InvalidArgument.hpp src/Rounding.hpp
