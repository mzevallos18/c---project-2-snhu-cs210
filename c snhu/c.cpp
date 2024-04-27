//Mario Zevallos
//04/07/2024

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float initialInvestment, monthlyDeposit, annualInterest, years;

    cout << "**********************************\n";
    cout << "*********** Data Input ***********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";

    cout << "****************************\n";
    cout << "Initial Investment Amount: $\n";
    cin >> initialInvestment;
    cout << "Monthly Deposit: $\n";
    cin >> monthlyDeposit;
    cout << "Annual Interest: %\n";
    cin >> annualInterest;
    cout << "Number of years: \n";
    cin >> years;
    const auto months = years * 12;

    float totalAmount = initialInvestment;

    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "=============================================================\n";
    cout << "Year          Year End Balance          Year End Earned Interest\n";
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {
        auto interest = ((totalAmount) * (annualInterest / 100));
        totalAmount += interest;
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interest << '\n';
    }

    totalAmount = initialInvestment;

    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year          Year End Balance          Year End Earned Interest\n";
    cout << "----------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {
        float yearlyInterest = 0;

        for (int j = 0; j < 12; j++) {
            auto interest = (((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12);
            yearlyInterest += interest;
            totalAmount += monthlyDeposit + interest;
        }

        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearlyInterest << '\n';
    }

    
    return 0;
}
