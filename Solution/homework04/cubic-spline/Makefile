source = $(wildcard *.cpp)
object = $(patsubst %.cpp, %.o, $(source))

main: $(object)
	g++ -o $@ $(object) -llapacke

%.o : %.cpp
	g++ -c $<

debug: $(source)
	g++ -o main $(source) -g -llapacke

clean:
	rm *.o main test *.exe html latex -fr
