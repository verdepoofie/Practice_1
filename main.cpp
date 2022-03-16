#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void loan();
void loan_p();
void file_copy();
void filter();
void sort_letters();
int main() {
    //loan();
    //loan_p();
    file_copy();
    filter();
    //sort_letters();
    return 0;
}
void loan(){
    cout << "Loan\nEnter loan amount, number of loan years and loan percent\n";
    double S, p, n, m = 0, r, r_pow;
    cin >> S >> n >> p;
    r = p / 100;
    r_pow = pow(1 + r, n);
    m = (S * r * r_pow) / (12 * (r_pow - 1));
    cout << "Monthly payment: " << m << "\n";
}
void loan_p(){
    cout << "Loan (percent search)\nEnter loan amount, monthly payment and number of loan years\n";
    double S, r_pow, n, m = 0, in_m, r;
    cin >> S >> in_m >> n;
    for(r = 0; r <= 1; r += 0.001) {
        r_pow = pow(1 + r, n);
        m = (S * r * r_pow) / (12 * (r_pow - 1));
        if (m >= in_m){
            cout << "Percent: " << r * 100 << "%\n";
            return;
        }
    }
}
void file_copy(){
    cout << "File copy\nInput file path\n";
    string path;
    cin >> path;
    ifstream f_in(path);
    if (!f_in) {
        cout << "File is not open!\n";
        return;
    }
    char buf;
    for (f_in; f_in.get(buf); f_in.eof())
        cout << buf;
    f_in.close();
}
void filter() {
    cout << "File filter\nInput file path\n";
    string path;
    cin >> path;
    ifstream f_in(path);
    if (!f_in) {
        cout << "Can't open fail\n";
        return;
    }
    char buf;
    for (f_in; f_in.get(buf); f_in.eof())
        if ((buf >= '0') && (buf <= '9'))
            cout << buf;
    cout << "\n";
    f_in.close();
}
void sort_letters(){
    cout << "Sort letters\nInput file path\n";
    string path;
    cin >> path;
    ifstream f_in(path);
    string txt;
    f_in >> txt;
    f_in.close();
    cout << txt << "\n";
    sort(txt.begin(), txt.end());
    cout << txt << "\n";
}