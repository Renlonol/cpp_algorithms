INCLUDE_DIR = ../../include/
SRC_FILES += ../../src/graph.cpp
SRC_FILES += graph_test.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRC_FILES))
BIN = graph_test

CXX = g++
CXXFLAGS = -O3 -g -Wall -I$(INCLUDE_DIR)

$(BIN): $(OBJS)
	@$(CXX) $^ -o $@

%.o: %.cpp
	@echo "  cc $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean:
	@rm -f $(OBJS)
	@rm -f $(BIN)
	@echo "Clean $(BIN) done"