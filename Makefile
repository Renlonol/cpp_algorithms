start: help

all: sort_test collections_test union_find_test
clean-all: sort_test_clean collections_test_clean union_find_test_clean

.PHONY: sort_test
sort_test:
	@make -C ./example/sort_test -j
	@echo "== Build $@ done"

.PHONY: sort_test_clean
sort_test_clean:
	@make -C ./example/sort_test clean

.PHONY: collections_test
collections_test:
	@make -C ./example/collections_test -j
	@echo "== Build $@ done"

.PHONY: collections_test_clean
collections_test_clean:
	@make -C ./example/collections_test clean

.PHONY: union_find_test
union_find_test:
	@make -C ./example/union_find_test -j
	@echo "== Build $@ done"

.PHONY: union_find_test_clean
union_find_test_clean:
	@make -C ./example/union_find_test clean

.PHONY: help
 help:
	@echo "================================= cpp algorithms lean makefile ========================================================"
	@echo " Usage:"
	@echo "  make [help] | [<target>]"
	@echo "  help                                                 Help from this Makefile contains only help for generic targets"
	@echo "  all               |   clean-all                      Build and clean all test"
	@echo "  sort_test         |   sort_test_clean                Build and clean stuffs for sort"
	@echo "  collections_test  |   collections_test_clean         Build and clean stuffs for collections"
	@echo "  union_find_test   |   union_find_test_clean          Build and clean stuffs for union_find"
	@echo "========================================================================================================================"