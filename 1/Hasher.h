#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Hasher
{
private:
	fstream* file;
	bool metod_;
	uint32_t out_;
public:
	Hasher(fstream* name, bool metod);
	void Sum64();
	void Adler32();
	uint64_t Hash();

};

