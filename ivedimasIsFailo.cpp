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
