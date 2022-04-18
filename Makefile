CXX = g++ -std=c++17 -Wall -O3
OBJECTS = MatchingEngine.o Engine.o Order.o OrderType.o

MatchingEngine: $(OBJECTS)
	@$(CXX) $^ -o $@
	@rm *.o
	@rm *.gch
	@rm Engine/*.gch
	@rm Order/*.gch
	@rm CustomTypes/*.gch
	
MatchingEngine.o: MatchingEngine.cpp MatchingEngine.hpp
	@$(CXX) -c $^

Engine.o: Engine/Engine.cpp Engine/Engine.hpp
	@$(CXX) -c $^

Order.o: Order/Order.cpp Order/Order.hpp
	@$(CXX) -c $^

OrderType.o: CustomTypes/OrderType.cpp CustomTypes/OrderType.hpp
	@$(CXX) -c $^

run: MatchingEngine
	@./MatchingEngine

clean:
	@rm *.o
	@rm *.gch
	@rm Engine/*.gch
	@rm Order/*.gch
	@rm MatchingEngine