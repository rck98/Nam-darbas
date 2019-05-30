#include "ivedimasIsFailo.h"
void ivedimasIsFailo(vector <mokinys> &lentele)
{
    string failoPav = "kursiokai.txt";
    int temp_sum = 0;
	double temp_vid1, temp_med1, temp_med2;
	mokinys temp;
try {

    std::ifstream failas;
    failas.open (failoPav, std::ifstream::in);
		if(!failas)
        throw (std::runtime_error("failas neegzistuoja"));
		string eilute;
		getline(failas, eilute);
		while (!failas.eof())
		{
			failas>>temp.var>>temp.pav;
			temp.nd.clear();
			for(int i=0, temp_paz; i<5; i++)
            {
                failas>>temp_paz;
                temp.nd.push_back(temp_paz);
            }
            failas>>temp.egz;
            temp_sum=0;
			for (int i : temp.nd)
				temp_sum += i;
			temp_vid1 = temp_sum * 1.0 / (temp.nd.size());
			temp.vid = temp_vid1 * 0.4 + temp.egz*0.6;
			temp.nd.push_back(temp.egz);
			sort(temp.nd.begin(), temp.nd.end());
			if (temp.nd.size() % 2 == 0)
			{
				temp_med1 = temp.nd.size() / 2;
				temp_med2 = temp.nd.size() / 2 + 1;
				temp.med = (temp.nd[temp_med1] + temp.nd[temp_med2])*1.0 / 2;
			}
			lentele.push_back(temp); // i lentele idedam temp
		}
            failas.close();
        }
            catch(const std::runtime_error &e1)
        {
            cout<<"klaida: "<<e1.what()<<endl;
            terminate();
        }
}
void PenkiFailai(vector<mokinys>&lentele)
{
    vector<mokinys>moksliukai;
	vector<mokinys>nemoksliukai;
    int temp_sum = 0;
	double temp_vid1, temp_med1, temp_med2;
	mokinys temp;
    string numeris;
    string txt={".txt"};
    string a[15]="Vardas";
    string b[15]="Pavarde";
    int k=1;
    for(int i=1; i<6; i++)
    {
        k=k*10;
        ofstream file;
        file.open (std::to_string(i) + ".txt");
            file <<"Vardas Pavarde ND1 ND2 ND3 ND4 ND5 EGZ" <<endl;
            for(int j=1; j<=k; j++)
                file << a[i]<<j<<" "<<b[i]<<j<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<" "<<rand() % 10 + 1<<"\n";
                file.close();
    }
                cout<<"iveskite failo numeri nuo 1 iki 5 kuri noretumete surusiuoti (1 - 10 zmoniu .... 5 - 100000 zmoniu) ";
                cin>>numeris;
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                numeris+=txt;
                ifstream in (numeris);
                string eilute;
                getline (in, eilute);
                while (!in.eof())
            {
			in>>temp.var>>temp.pav;
			temp.nd.clear();
			for(int i=0, temp_paz; i<5; i++)
            {
                in>>temp_paz;
                temp.nd.push_back(temp_paz);
            }
            in>>temp.egz;
            temp_sum=0;
			for (int i : temp.nd)
				temp_sum += i;
			temp_vid1 = temp_sum * 1.0 / (temp.nd.size());
			temp.vid = temp_vid1 * 0.4 + temp.egz*0.6;
			if(temp.vid>=5)
                moksliukai.push_back(temp);
			else
                nemoksliukai.push_back(temp);
            }
            in.close();
            ofstream out("galvociai.txt");
            out << setw(15) << left << "Vardas " << setw(15) << left << "Pavarde " << setw(20) << right << "Galutinis (Vid.) " << endl;
            out.fill('-');
            out.width(50);
            out << "-" << endl;
            out.fill(' ');
            for (mokinys duomenys : moksliukai)
                out << setw(15) << left << duomenys.var << setw(15) << left << duomenys.pav << setw(20) << right << setprecision(3) << duomenys.vid << endl;
            out.close();
            ofstream aut("nuskriaustukai.txt");
            aut << setw(15) << left << "Vardas " << setw(15) << left << "Pavarde " << setw(20) << right << "Galutinis (Vid.) " << endl;
            aut.fill('-');
            aut.width(50);
            aut << "-" << endl;
            aut.fill(' ');
            for (mokinys duomenys : nemoksliukai)
                aut << setw(15) << left << duomenys.var << setw(15) << left << duomenys.pav << setw(20) << right << setprecision(3) << duomenys.vid << endl;
            aut.close();
            chrono::steady_clock::time_point end=chrono::steady_clock::now();
            cout << "Jusu programa dirbo " << chrono::duration_cast<chrono::seconds>(end - begin).count() <<" sekundziu"<<endl;

}
