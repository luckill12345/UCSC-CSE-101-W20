# WARNING   = -Wall -Wextra -Wpedantic -Wshadow -Wold-style-cast
# CXX       = g++ -std=c++11 -g -O0
# CXXWARN   = ${CXX} ${WARNING} -fdiagnostics-color=never

# MODULES 	= graph
# CPPSRC    = ${MODULES:=.cpp} # main.cpp
# HDRSRC    = ${MODULES:=.h}
# OBJECTS   = ${CPPSRC:.cpp=.o}
# EXECBIN   = sixdegrees
# MODSRC    = ${foreach MOD, ${MODULES}, ${MOD}.h ${MOD}.cpp}
# MISCSRC   = ${filter-out ${MODSRC}, ${HDRSRC} ${CPPSRC}}


# all : ${EXECBIN}

# ${EXECBIN} : ${OBJECTS}
# 	${CXXWARN} -o${EXECBIN} ${OBJECTS}

# clean:
# 	-rm -f ${OBJECTS} ${EXECBIN}


CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = graph.o sixdegrees.o

sixdegrees: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ $^

clean: 
	rm -f *.o sixdegrees
$(OBJECTS): graph.h
