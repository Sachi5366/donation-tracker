// DonationTracker.cpp
#include <bits/stdc++.h>
using namespace std;

struct Donation {
    string donor;
    double amount;
    string date;
};

const string FILE_NAME = "donations.csv";

vector<Donation> load() {
    vector<Donation> v;
    ifstream in(FILE_NAME);
    string line;
    while (getline(in, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        string donor, amt, date;
        getline(ss, donor, ',');
        getline(ss, amt, ',');
        getline(ss, date, ',');
        v.push_back({donor, stod(amt), date});
    }
    return v;
}

void save(const vector<Donation>& v) {
    ofstream out(FILE_NAME);
    for (auto &d: v) out << d.donor << ',' << d.amount << ',' << d.date << '\n';
}

void addDonation(vector<Donation>& v) {
    Donation d;
    cout << "Donor name: "; getline(cin, d.donor);
    cout << "Amount: "; cin >> d.amount; cin.ignore();
    cout << "Date (YYYY-MM-DD): "; getline(cin, d.date);
    v.push_back(d);
    save(v);
    cout << "Saved.\n";
}

void listDonations(const vector<Donation>& v) {
    double total=0;
    cout << left<< setw(25)<<"Donor"<<setw(10)<<"Amount"<<setw(12)<<"Date\n";
    cout << string(50,'-') << '\n';
    for(auto &d: v){
        cout << setw(25) << d.donor << setw(10) << d.amount << setw(12) << d.date << '\n';
        total += d.amount;
    }
    cout << "Total: " << total << "\n";
}

int main(){
    auto data = load();
    while(true){
        cout << "\nDonation Tracker\n1) Add donation\n2) List donations\n3) Exit\nChoose: ";
        int c; if(!(cin>>c)) break; cin.ignore();
        if(c==1) addDonation(data);
        else if(c==2) listDonations(data);
        else break;
    }
}
