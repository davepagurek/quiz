CXX= g++ -std=c++11
CXXFLAGS = -Wall -O -g
OBJS = main.o quiz/Quiz.cpp
EXEC = exec

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

clean:
	rm $(EXEC) $(OBJS)
