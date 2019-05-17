
#include<PenkiFailai.h>
void PenkiFailai(vector<mokinys>&lentele)
{
          chrono::steady_clock::time_point begin = chrono::steady_clock::now();
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

            return 0;
}
