CC=g++
CFLAGS=-g -Wall
export $(CFLAGS) 
input?=
output?=

main:
	g++ -o bin/main src/main.cpp

run:
	./bin/main $(input) $(output)

