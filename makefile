CXX = g++
CXXFLAGS += -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g#

OBJS = board.o ant.o inputValidation.o langtonsMenu.o langtonsAntMain.o

SRCS = board.cpp ant.cpp inputValidation.cpp langtonsMenu.cpp langtonsAntMain.cpp

HEADERS = Ant.h Board.h inputValidation.h langtonsMenu.h

langtonsAnt: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o langtonsAnt

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
