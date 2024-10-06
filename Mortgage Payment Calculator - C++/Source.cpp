//Mortgage Payment Calculator

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
using std::endl;

//class for the mortgage is declared
class Mortgage
{
private:

	int loanYears; //number of years on the mortgage
	double loanAmount; //Total amount of the mortgage
	double interestRate; //rate of interest on the mortgage

public:

	Mortgage(); //Default constructor declared
	//functions for setting data
	void setLoanAmount(double);
	void setLoanYears(int);
	void setInterestRate(double);

	//functions to calculate values
	double calcMonthlyPayment(); //calculates monthly payment based on data entered
	double calcTotalPaid(); //calculates total paid over the life of the mortgage
};

//Member Function Definitions:
//Default constructor sets initial values to zero
Mortgage::Mortgage()
{
	setLoanAmount(0);
	setLoanYears(0);
	setInterestRate(0);
}

//Function for setting the loan amount
void Mortgage::setLoanAmount(double amount)
{
	loanAmount = amount;
}

//Function for setting the term of the loan
void Mortgage::setLoanYears(int years)
{
	loanYears = years;
}

//Function for setting the interest rate
void Mortgage::setInterestRate(double rate)
{
	interestRate = rate / 100;
}

//Function calculates the monthly payment
double Mortgage::calcMonthlyPayment()
{
	double term = pow(1 + (interestRate / 12), 12 * loanYears);
	double payment = (loanAmount * (interestRate / 12) * term) / (term - 1);
	return payment;
}

//Function to calculate the total paid into the loan
double Mortgage::calcTotalPaid()
{
	return (12. * loanYears * calcMonthlyPayment());
}

int main(int argc, char** argv) {

	Mortgage userLoan; //object of class Mortgage declared
	//temporary variables used outside of the class
	double tempLoan, tempInterest;
	int tempYears;

	//Program welcomes the user, describes function
	cout << "Mortgage Payment Calculator";
	cout << "\n\nThis program will calculate your monthly mortgage payment ";
	cout << "\nbased on the data you enter." << endl;;

	//Get loan amount from the user
	cout << "\nPlease enter the total amount of the loan: $";
	cin >> tempLoan;
	//Program will not accept negative numbers
	if (tempLoan < 0) {
		cout << "Please enter a valid loan amount: $";
		cin >> tempLoan;
	}

	//Get total number of years from the user
	cout << "\nNow, enter the total number of years on the loan: ";
	cin >> tempYears;
	//Will not accept negative value
	if (tempYears < 0) {
		cout << "Please enter a valid number of years: ";
		cin >> tempYears;
	}

	//Get the interest rate from the user
	cout << "\nFinally, enter the interest rate of the loan: ";
	cin >> tempInterest;
	//Won't accept negative value or greater than 100%
	if (tempInterest < 0 || tempInterest > 100) {
		cout << "Please enter a valid interest rate: ";
		cin >> tempInterest;
	}

	//Values entered by user passed to member functions
	userLoan.setLoanAmount(tempLoan);
	userLoan.setLoanYears(tempYears);
	userLoan.setInterestRate(tempInterest);

	//Payment and total amount displayed
	cout << "The monthly payment is $" << userLoan.calcMonthlyPayment() << std::fixed << std::setprecision(2) << endl;
	cout << "The total amount of the loan is $" << userLoan.calcTotalPaid() << std::fixed << std::setprecision(2) << endl;

	return 0;
}