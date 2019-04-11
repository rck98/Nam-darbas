#ifndef MANO_H_INCLUDED
#define MANO_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct mokinys
{
	string var, pav;
	vector<int>nd;
	double egz, vid, med;
};
bool rusiavimas (mokinys a, mokinys b)
{
    return a.var < b.var;
}



#endif // MANO_H_INCLUDED
