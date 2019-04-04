#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;

struct ir {
	string var, pav;
	vector<int>nd;
	double egz, vid, med;
};

int main()
{
	vector<ir>lentele;
	ir temp;
	int temp_a = 1, temp_b, temp_sum;
	double temp_vid1, temp_med1, temp_med2;
	while (temp_a == 1)
	{
		int temp_paz = 1;
		cout << "Iveskite Varda ir Pavarde ";
		cin >> temp.var >> temp.pav;
		temp.nd.clear();
		temp_sum = 0;
		cout << "Suveskite pazymius norint sustoti iveskite 0: ";
		while (temp_paz != 0 && temp_paz > 0 && temp_paz < 11)
		{
			cin >> temp_paz;
			temp.nd.push_back(temp_paz);
			temp_sum += temp_paz;
		}
		temp_vid1 = temp_sum * 1.0 / (temp.nd.size() - 1);
		cout << "Iveskite egzamino rezultata: ";
		cin >> temp.egz;
		temp.nd.push_back(temp.egz);
		temp.vid = temp_vid1 * 0.4 + temp.egz*0.6;
		sort(temp.nd.begin(), temp.nd.end());
		temp.nd.erase(temp.nd.end() - 1);
		if (temp.nd.size() % 2 == 0)
		{
			temp_med1 = temp.nd.size() / 2;
			temp_med2 = temp.nd.size() / 2 + 1;
			temp.med = (temp.nd[temp_med1] + temp.nd[temp_med2])*1.0 / 2;
		}
		else
		{
			temp_med1 = temp.nd.size() / 2 + 1;
			temp.med = temp.nd[temp_med1];
		}
		lentele.push_back(temp); // i lentele idedam temp
		cout << "Jei norite testi spauskite 1 ";
		cin >> temp_a;
	}
	cout << "Jei norite, kad rodytu vidurki spauskite 1, jei mediana spauskite 2 ";
	cin >> temp_b;
	if (temp_b == 1)
	{
		cout << setw(15) << left << "Vardas " << setw(15) << left << "Pavarde " << setw(20) << right << "Galutinis (Vid.) " << endl;
		cout.fill('-');
		cout.width(50);
		cout << "-" << endl;
		cout.fill(' ');
		for (ir duomenys : lentele)
			cout << setw(15) << left << duomenys.var << setw(15) << left << duomenys.pav << setw(20) << right << duomenys.med << endl;
	}

}
