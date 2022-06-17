main:
	g++ src/main.cpp src/levenshtein.cpp -o main

tests:
	g++ test/test_levenshtein.cpp src/levenshtein.cpp -o main