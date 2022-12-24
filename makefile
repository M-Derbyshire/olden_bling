.DEFAULT_GOAL := build

build:
	gcc *.c $(wildcard engine/*.c) $(wildcard locations/*/*.c)