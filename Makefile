# Makefile
# $Id: Makefile,v 1.2 2003/11/07 06:59:32 fusion Exp fusion $

all: tc

timetest: timetest.o time.o
	$(CXX) -o timetest timetest.o time.o

toktest: toktest.o timetok.o time.o
	$(CXX) -o toktest time.o toktest.o timetok.o

tc: timegram.o timetok.o time.o tc.o
	$(CXX) -o $@ timegram.o timetok.o time.o tc.o

timegram.cpp timegram.h: timegram.ypp
	bison -dvy timegram.ypp
	mv y.tab.h timegram.h
	mv y.tab.c timegram.cpp

timetok.cpp: timetok.lpp
	flex timetok.lpp
	mv lex.yy.c timetok.cpp

clean:
	rm -f *.o toktest timetest tc timegram.cpp timegram.h timetok.cpp y.output

timetest.o: timetest.cpp time.h
time.o: time.cpp time.h
timetok.o: timetok.cpp timegram.h time.h
