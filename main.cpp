#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double> DoubleVec;
//DoubleVec x = {3,2,1,6};

double medianSort(DoubleVec &x){

    int position;

    //Vector sortieren
    sort(x.begin(), x.end());

    //Wenn der Vektor gerade ist.
    if(x.size() % 2 == 0){

        int posX1 = (x.size()/2.0) - 1; //-1 weil wir von 0 Anfangen zu zählen.
        int posX2 = ((x.size()/2.0) + 1.0)- 1;

        double position =  1.0/2.0 * ( x.at(posX1) + x.at(posX2) );

        return position;
    } else {
        //Wenn die Anzahl des Vektors ungerade ist.
        position = ( (x.size() + 1) / 2 ) - 1;
        //cout << "Position" << position << endl;
        return x.at(position);

    }
}

double medianNthElement(DoubleVec &x){
    double median;
    bool comp(int a, int b);

    //Wenn nur 1 Element vorhanden ist.
    if(x.size() == 1){
        return x.at(0);
    } else {
        if(x.size() % 2 == 0){
            int posX1 = (x.size()/2.0) - 1; //-1 weil wir von 0 Anfangen zu zählen.
            int posX2 = ((x.size()/2.0) + 1.0)- 1;

            DoubleVec:: iterator med = x.begin() + 1.0/2.0 * ( x.at(posX1) + x.at(posX2) );

            nth_element(x.begin(), med, x.end());
            return x.at(*med);

        } else {
            double posMed = (x.size() / 2.0) - 1;
            DoubleVec::iterator med = x.begin() + posMed;

            nth_element(x.begin(), med, x.end());

            return x.at(posMed);
        }
    }

}


int main() {
    DoubleVec x;
    vector <double>:: iterator it;

    //Test Daten
    x.push_back(3);
    x.push_back(1);
    x.push_back(4);
    x.push_back(9);
    x.push_back(10);
    x.push_back(6);
    x.push_back(8);
    x.push_back(2);


    cout << "Median: " << medianSort(x) << endl;
    //Ausgabe
    for( it=x.begin(); it != x.end(); it++){
        cout <<  *it << ", ";
    }
    cout << endl;

   // cout << "Median mit nth_element: " << medianNthElement(x) << endl;
    //Ausgabe
    for( it=x.begin(); it != x.end(); it++){
        cout <<  *it << ", ";
    }



    return 0;
}
