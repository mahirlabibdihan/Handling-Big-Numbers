all: big

big: BigDecimal.o Add.o Mul.o Sub.o Div.o Tri.o Calc.o Bit.o Util.o Math.o
	g++  BigDecimal.o Add.o Mul.o Sub.o Div.o Tri.o Calc.o Bit.o Util.o Math.o -o big

BigDecimal.o: BigDecimal.cpp
	g++ -c BigDecimal.cpp

Add.o: Add.cpp
	g++ -c Add.cpp

Mul.o: Mul.cpp
	g++ -c Mul.cpp

Sub.o: Sub.cpp
	g++ -c Sub.cpp

Div.o: Div.cpp
	g++ -c Div.cpp

Tri.o: Tri.cpp
	g++ -c Tri.cpp

Calc.o: Calc.cpp
	g++ -c Calc.cpp

Bit.o: Bit.cpp
	g++ -c Bit.cpp

Util.o: Util.cpp
	g++ -c Util.cpp

Math.o: Math.cpp
	g++ -c Math.cpp

run: big
	./big

clean:
	rm -rf *o
