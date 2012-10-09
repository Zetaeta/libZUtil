
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libZUtil.la

libZUtil_la_includedir = $(includedir)/Util

libZUtil_la_CXXFLAGS = -g -fPIC -std=c++11 -Wall -pg

libZUtil_la_LDFLAGS = -pg
libZUtil_la_LIBADD = -lendian -lIOStream -lz

libZUtil_la_SOURCES = src/Endian.cpp src/Unicode.cpp

libZUtil_la_include_HEADERS = src/Endian.h src/Unicode.h src/stlfwd.hpp
