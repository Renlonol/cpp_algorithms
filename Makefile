INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
COLLECTION_DIR = ./example/collections_test
UNION_FIND_DIR = ./example/union_find_test
SORT_DIR = ./example/sort_test

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES += $(patsubst  %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))

#collection objs
COLLECTION_FILES := $(wildcard $(COLLECTION_DIR)/*.cpp)
COLLECTION_OBJS += $(patsubst  %.cpp, $(COLLECTION_DIR)/%.o, $(notdir $(COLLECTION_FILES)))
#union_find objs
UNION_FIND_FILES := $(wildcard $(UNION_FIND_DIR)/*.cpp)
UNION_FIND_OBJS += $(patsubst  %.cpp, $(UNION_FIND_DIR)/%.o, $(notdir $(UNION_FIND_FILES)))
#sort objs
SORT_FILES := $(wildcard $(SORT_DIR)/*.cpp)
SORT_OBJS += $(patsubst  %.cpp, $(SORT_DIR)/%.o, $(notdir $(SORT_FILES)))

#bulid test bins 
COLLECTION_TARGET = $(COLLECTION_DIR)/collections_test
UNION_FIND_TARGET = $(UNION_FIND_DIR)/union_find_test
SORT_TARGET       = $(SORT_DIR)/sort_test

CXX = g++
CXXFLAGS = -g -Wall -I$(INC_DIR) --std=c++11

all: help

.PHONY: all_test
all_test: $(COLLECTION_TARGET) $(UNION_FIND_TARGET) $(SORT_TARGET)

$(COLLECTION_TARGET) : $(OBJ_FILES) $(COLLECTION_OBJS)
	$(CXX) $^ -o $@
$(COLLECTION_DIR)/%.o : $(COLLECTION_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(UNION_FIND_TARGET) : $(OBJ_FILES) $(UNION_FIND_OBJS)
	$(CXX) $^ -o $@
$(UNION_FIND_DIR)/%.o : $(UNION_FIND_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SORT_TARGET) : $(OBJ_FILES) $(SORT_OBJS)
	$(CXX) $^ -o $@
$(SORT_DIR)/%.o : $(SORT_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -f $(OBJ_DIR)/*.o
	rm -f $(COLLECTION_TARGET) $(COLLECTION_OBJS)
	rm -f $(UNION_FIND_TARGET) $(UNION_FIND_OBJS)
	rm -f $(SORT_TARGET) $(SORT_OBJS)

.PHONY: help
help:
	@echo "================================= algorithms lean makefile =================================="
	@echo " Usage:"
	@echo "  make [help] | [<target>]"
	@echo "  help                       Help from this Makefile contains only help for generic targets"
	@echo "  all_test                   all bins for test"
	@echo "============================================================================================="