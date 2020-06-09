INCLUDE_DIR = ../../include/
SRC_FILES += ../../src/sort_template.cpp
SRC_FILES += sort_test.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRC_FILES))
BIN = sort_test

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