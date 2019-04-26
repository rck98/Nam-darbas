#include "mano.h"
#include "ivedimasIsFailo.h"
bool rusiavimas (mokinys a, mokinys b)
{
    return a.var < b.var;
}

int main()
{
	vector<mokinys>lentele;
	vector<mokinys>a;
	mokinys temp;
	int temp_a = 1, temp_b, temp_sum = 0;
	double temp_vid1, temp_med1, temp_med2;
	int patsArFailas;
	cout << "Jei norite ivesti duomenis patys, iveskite 1, jeigu nuskaityti is failo 2 ";
	cin >> patsArFailas;
	if (patsArFailas == 1) {
		while (temp_a == 1)
		{
			int temp_paz = 1;
			cout << "Iveskite Varda ir Pavarde ";
			cin >> temp.var >> temp.pav;
			temp.nd.clear();
			temp_sum = 0;
			int yesno;
			cout << "Jei norite ivesti pazymius patys spauskite 1, kitu atveju iveskite bet koki kita skaiciu ";
			cin >> yesno;
			if (yesno == 1)
			{
				cout << "Suveskite pazymius norint sustoti iveskite 0: ";
				while (temp_paz != 0 && temp_paz > 0 && temp_paz < 11)
				{
					cin >> temp_paz;
					temp.nd.push_back(temp_paz);
					temp_sum += temp_paz;
				}
				temp.nd.erase(temp.nd.end() - 1);
				temp_vid1 = temp_sum * 1.0 / (temp.nd.size());
				cout << "Iveskite egzamino rezultata: ";
				cin >> temp.egz;
				temp.nd.push_back(temp.egz);
			}
			else
			{
				cout << "Kiek noresite pazymiu? ";
				int pazymiuKiekis;
				cin >> pazymiuKiekis;
				for (int i = 0; i < pazymiuKiekis; i++)
				{
					int pazymys = (rand() % 10) + 1;
					temp.nd.push_back(pazymys);
					temp_sum += pazymys;
				}
				temp.egz = (rand() % 10) + 1;
				temp.nd.push_back(temp.egz);
				temp_vid1 = temp_sum * 1.0 / (temp.nd.size() - 1);
			}
			temp.vid = temp_vid1 * 0.4 + temp.egz*0.6;
			sort(temp.nd.begin(), temp.nd.end());
			if (temp.nd.size() % 2 == 0)
			{
				temp_med1 = temp.nd.size() / 2;
				temp_med2 = temp.nd.size() / 2 - 1;
				temp.med = (temp.nd[temp_med1] + temp.nd[temp_med2])*1.0 / 2;
			}
			else
			{
				temp_med1 = temp.nd.size() / 2;
				temp.med = temp.nd[temp_med1];
			}
			lentele.push_back(temp); // i lentele idedam temp
			cout << "Jei norite testi spauskite 1 ";
			cin >> temp_a;
		}
	}
	else if (patsArFailas == 2)
	{
	   ivedimasIsFailo(lentele);
	}
	cout<<lentele.size()<<endl;
	if(lentele.size()!=0)
        {
           cout << "Jei norite, kad rodytu vidurki spauskite 1, jei mediana spauskite 2 ";
        cin >> temp_b;
        sort(lentele.begin(), lentele.end(), rusiavimas);
        if (temp_b == 1)
        {
            cout << setw(15) << left << "Vardas " << setw(15) << left << "Pavarde " << setw(20) << right << "Galutinis (Vid.) " << endl;
            cout.fill('-');
            cout.width(50);
            cout << "-" << endl;
            cout.fill(' ');
            for (mokinys duomenys : lentele)
                cout << setw(15) << left << duomenys.var << setw(15) << left << duomenys.pav << setw(20) << right << setprecision(3) << duomenys.vid << endl;
        }
        else if (temp_b == 2)
        {
            cout << setw(15) << left << "Vardas " << setw(15) << left << "Pavarde " << setw(20) << right << "Mediana" << endl;
            cout.fill('-');
            cout.width(50);
            cout << "-" << endl;
            cout.fill(' ');
            for (mokinys duomenys : lentele)
                cout << setw(15) << left << duomenys.var << setw(15) << left << duomenys.pav << setw(20) << right << setprecision(3) << duomenys.med << endl;
        }
        }
return 0;
}

