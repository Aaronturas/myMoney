//Program to calculate my monthly money/transactions
//Original Program
//12/19/2020 && Updated 10/21/2021
//Aaron Ivan Gonzalez
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

const double Rent = 1085; //Rent money
const double OSLA = 230; //tuition debt
const double Nelnet = 185; //tuition debt
const double Mint = 25; //phone bill
const double CarInsurance = 58; //car insurance
const double StockSchedule = 42; //Monthly stock schedule
const double Stash = 1; //Monthly Cost of Stash App
const double MealPenalty = 22.20;//Meal penalty if worked past 5 hours without lunch
const double Fidelity = 100; //Roth IRA
const double ParkingPermit = 81; //Parking permit for month
const double Ally = 50; //Ally online savings account
const double Honda = 268;//Monthly car payment
//const double Linkedin = 30;//Monthly linkedin learning
const double benefits = 4.60;//fringe benfits per hour
const double vacation = 0.94;//vaction rate per hour
const double holiday = 0.86;//holiday rate per hour
double overtimeRate = 0;//overtime rate per hour
const double Accident = 1.21; //Accident Insurance
const double LTD = 1.54;//Long term disability

//Payroll taxes
double CAtax;//California Tax rate && Variable tax
const double CASDIEtax = 1.1;//California state disability income tax
double FITWtax;//Federal Income tax withholding & if you make over $12000 this will apply && Variable tax
const double MEDtax = 1.45;//Medicare Tax
const double SStax = 6.2;//Social Security


double MonthlyGas(double);
double MonthlyFood(double);
double MonthlyFastrak(double);
double MonthlyTicket(double);
double MonthlyOnlineShopping(double);
double MonthlyRoundUps(double);
double MonthlyTakeout(double);
double MonthlyHaircut(double);

int main()
{
    cout << "------------------------------------ My Money for the Month ------------------------------------------------\n";

    ofstream Dinero("Money.txt", ios::app);

    int day, month, year;

    cout << "What day is it :";
    cin >> day;

    cout << "What month is it :";
    cin >> month;

    cout << "What year is it :";
    cin >> year;

    cout << endl;

    Dinero << endl << "Date Calculated: " << month << "/" << day << "/" << year << endl;


    double hours, Grossyear, Net, overtime, lunch, allyaccount, BOA, Bankaccount;
    double payrate, taxPercent, lossPercent, incomePercent;
    double Paycheck, CA, CASDIE, FITW, MED, SS, Taxes = 0, total = 0;

    cout << "What is your Pay Rate? $";
    cin >> payrate;

    overtimeRate = payrate + (payrate * 0.5); //overtime is equal to original rate plus 50% of original payrate

    cout << "How many hours did you work this week or month? :";
    cin >> hours;

    cout << "How many hours of overtime did you work? :";
    cin >> overtime;

    cout << "How many times did you work more than 5 hours or without lunch? :";
    cin >> lunch;

    cout << endl << "Fringe Benefits is $4.60 an hour so that will be multiplied by the hours worked\n"
         << "Vacation Benefits is $0.94 an hour so that will be multiplied by the hours worked\n"
         << "Holiday Benefits is $0.86 an hour so that will be multiplied by the hours worked\n"
         << "Then added to your added to pay rate\n" << endl;

    if(hours < 80 && lunch == 0 && overtime == 0)
    {
        CAtax = 3.99;
        FITWtax = 9.622;
    }
    else if (hours < 80 && lunch > 0 && lunch < 5 && overtime == 0)
    {
        CAtax = 4.05;
        FITWtax = 9.776;
    }
    else if (hours < 80 && lunch == 1 && overtime < 1)
    {
        CAtax = 4.084;
        FITWtax = 10.01;
    }
    else if (hours < 80 && lunch > 1 && lunch < 3 && overtime < 1)
    {
        CAtax = 4.11;
        FITWtax = 9.931;
    }
    else if (hours < 80 && lunch > 2 && lunch < 4 && overtime < 1)
    {
        CAtax = 4.389;
        FITWtax = 10.647;
    }
    else if (hours < 80 && lunch >= 4 && lunch <= 8 && overtime < 1)
    {
        CAtax = 4.3982;
        FITWtax = 10.672;
    }
    else if (hours < 80 && lunch >= 9 && overtime < 1)
    {
        CAtax = 4.742;
        FITWtax = 11.3955;
    }
    else if (hours < 80 && lunch > 0 && lunch < 5 && overtime < 9)
    {
        CAtax = 4.6035;
        FITWtax = 11.128;
    }
    else if(hours >= 80 && overtime >= 0 && overtime < 1)
    {
        CAtax = 4.05;
        FITWtax = 9.776;
    }
    else if(hours >= 80 && overtime >= 0 && overtime < 5 || lunch > 0)
    {
        CAtax = 4.1;
        FITWtax = 10.1645;
    }
    else if (hours >= 80 && overtime >= 5 && overtime < 8)
    {
        CAtax = 4.345;
        FITWtax = 10.535;
    }
    else if (hours >= 80 && overtime >= 8 || lunch >= 5)
    {
        CAtax = 4.736;
        FITWtax = 11.385;
    }
    Paycheck = (payrate * hours) + (benefits * hours) + (vacation * hours) + (holiday * hours) + (overtimeRate * overtime) + (MealPenalty * lunch);
    cout << "Payrate " << payrate << " " << benefits <<  " " << vacation <<  " " << holiday <<  " " << overtimeRate <<  " " << overtime <<  " " << MealPenalty <<  " " << lunch <<  " " << hours << endl;
    cout << "CAtax : " << CAtax << endl;
    cout << "FITWtax : " << FITWtax << endl << endl;

    cout << "Your Gross Pay is $" << Paycheck << endl << endl;

    CA = Paycheck * (CAtax / 100);
    cout << "The amount taken out for California Tax Rate is $" << fixed << setprecision(2) << CA << endl;

    CASDIE = Paycheck * (CASDIEtax / 100);
    cout << "The amount taken out for California State Disability Income Tax is $" << CASDIE << endl;

    FITW = Paycheck * (FITWtax / 100);
    cout << "The amount taken out for Federal Income tax withholding is $" <<  FITW << endl;

    MED = Paycheck * (MEDtax / 100);
    cout << "The amount taken out for Medicare is $" << MED << endl;

    SS = Paycheck * (SStax / 100);
    cout << "The amount taken out for Social Security is $" << SS << endl;

    Taxes = CA + CASDIE + FITW + MED + SS;
    cout << "The Total amount of taxes is $" << Taxes << endl << endl;

    total = Paycheck - Taxes;
    cout << "The amount of Income after payroll taxes is $" << total << endl;

    if (hours >= 155)
    {
        total = total - (2 * (Accident + LTD));
        cout << "The amount of Income after deductions is $" << total << endl;
    }
    else
    {
        total = total - (Accident + LTD);
        cout << "The amount of Income after deductions is $" << total << endl;
    }



    cout << endl;
    Grossyear = Paycheck * 12;
    cout << "The Gross Pay for the year is $" << Grossyear << endl;

    Net = total * 12;
    cout << "The Net Income for the year is $" << Net << endl;
    cout << endl;

    double Gas,
           gas = 0;

    Gas = MonthlyGas(gas);
    cout << endl; //output spacing

    double Food,
           food = 0;

    Food = MonthlyFood(food);
    cout << endl; //output spacing

    double Fastrak,
           fastrak = 0;

    Fastrak = MonthlyFastrak(fastrak);
    cout << endl;

    double Ticket,
           ticket = 0;

    Ticket = MonthlyTicket(ticket);
    cout << endl;

    double Online,
           online = 0;

    Online = MonthlyOnlineShopping(online);
    cout << endl;

    double RoundUp,
           roundup = 0;

    RoundUp = MonthlyRoundUps(roundup);
    cout << endl;

    double Takeout,
           takeout = 0;
    Takeout = MonthlyTakeout(takeout);
    cout << endl;

    double Haircut,
           haircut = 0;
    Haircut = MonthlyHaircut(haircut);
    cout << endl;

    double Money = 0;
    string expenses[] = {"Gas", "Food", "Fastrak", "Ticket", "Rent", "OSLA", "Nelnet",
                           "Mint", "CarInsurance", "StockSchedule","Stash","Fidelity", "Online",
                           "ParkingPermit", "Ally","Honda", "RoundUp", "Takeout", "Haircut"};
    double arr[] = {Gas, Food, Fastrak, Ticket, Rent, OSLA, Nelnet,
                      Mint, CarInsurance,  StockSchedule, Stash, Fidelity, Online,
                      ParkingPermit, Ally, Honda, RoundUp, Takeout, Haircut};
    int loss = 0;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        double smallPercent = 0;
        smallPercent = (arr[i] / Paycheck) * 100;
        loss += arr[i];
        cout << "Your expenses for " << expenses[i] << " is $" << arr[i] <<
                " which is " << smallPercent << "% of your Gross Pay." << endl;
    }
    cout << endl;
     cout << "Your expenses for the month are :$"  << loss << endl;
    Money = total - loss;

    cout << "Your Money for the Month is $" << Money << endl;
    cout << endl;

    incomePercent = (Money / Paycheck) * 100;
    lossPercent = (loss / Paycheck) * 100;
    taxPercent = (Taxes / Paycheck) * 100;

    cout << "The Percentage of Income from Gross Pay is :" << incomePercent << "%" << endl;
    cout << "The Percentage of Expenses from Gross Pay is :" << lossPercent << "%" << endl;
    cout << "The Percentage of Payroll Taxes from Gross Pay is :" << taxPercent << "%" << endl;

    cout << endl << "Enter how much money is in your Ally Bank Accounts $";
    cin >> allyaccount;

    cout << "Enter how much money is in your Bank of America Bank Accounts $";
    cin >> BOA;

    Bankaccount = allyaccount + BOA;

    Dinero << "Your Ally Total Balance is $" << allyaccount << endl;
    Dinero << "Your Bank of America Total Balance is $" << BOA << endl;
    Dinero << "Your Total Balance from both accounts is $" << Bankaccount << endl;
    Dinero << "Your expenses for the month are :$"  << loss << endl;
    Dinero << "Your Money for the Month is $" << Money << endl;

    Bankaccount += Money;

    Dinero << "Your new Total Balance is $" << Bankaccount << endl;

    Dinero.close();

    return 0;
}
double MonthlyGas(double gas)
{
    int NumGas = 0;
    double total = 0;

    cout << "How many times did you pump gas :";
    cin >> NumGas;

    for(int a = 0; a < NumGas; a++)
    {
        cout << "What was the cost of Fuel Pump #" << (a + 1) << ": ";
        cin >> gas;
        total += gas;
    }
    cout << "The Total Cost of Gas for the Month $" << total << endl;
    return total;
}
double MonthlyFood(double food)
{
    int Numfood = 0;
    double total = 0;

    cout << "How many times did you buy groceries this month :";
    cin >> Numfood;

    for(int a = 0; a < Numfood; a++)
    {
        cout << "What was the cost of Grocery List #" << (a + 1) << ": ";
        cin >> food;
        total += food;
    }
    cout << "The Total Cost of Groceries for this Month $" << total << endl;
    return total;
}
double MonthlyFastrak(double fastrak)
{
    int Numfastrak = 0;
    double total = 0;

    cout << "How many times did you cross a toll this month :";
    cin >> Numfastrak;

    for(int a = 0; a < Numfastrak; a++)
    {
        cout << "What was the cost of Toll #" << (a + 1) << ": ";
        cin >> fastrak;
        total += fastrak;
    }

    cout << "The Total Cost of Fastrak for this Month $" << total << endl;
    return total;
}
double MonthlyTicket(double ticket)
{
    int Numticket = 0;
    double total = 0;

    cout << "How many times did you get a parking ticket this month :";
    cin >> Numticket;

    if (Numticket == 0)
    {
        cout << "Good Job" << endl;
        return total = 0;
    }

    for(int a = 0; a < Numticket; a++)
    {
        cout << "What was the cost of Parking Ticket #" << (a + 1) << ": ";
        cin >> ticket;
        total += ticket;
    }
    cout << "The Total Cost of Parking Tickets for this Month is $" << total << endl;
    return total;
}
double MonthlyOnlineShopping(double online)
{
    int NumOnline = 0;
    double total = 0;

    cout << "How many times did you buy things online for this month :";
    cin >> NumOnline;

    if (NumOnline == 0)
    {
        cout << "Good Job" << endl;
        return total = 0;
    }

    for(int a = 0; a < NumOnline; a++)
    {
        cout << "What was the cost of Online Shopping Item #" << (a + 1) << ": ";
        cin >> online;
        total += online;
    }
    cout << "The Total Cost of Online Shopping for this Month is $" << total << endl;
    return total;
}
double MonthlyRoundUps(double roundup)
{
    int NumRoundup = 0;
    double total = 0;

    cout << "How many times did the Stash App Round Up for this month :";
    cin >> NumRoundup;

    if (NumRoundup == 0)
    {
        cout << "Why no Roundups for this Month?" << endl;
        return total = 0;
    }

    for(int a = 0; a < NumRoundup; a++)
    {
        cout << "How much was RoundUp #" << (a + 1) << ": ";
        cin >> roundup;
        total += roundup;
    }
    cout << "The Total Cost of RoundUps for this Month is $" << total << endl;
    return total;
}
double MonthlyTakeout(double takeout)
{
    int Numtakeout = 0;
    double total = 0;

    cout << "How many times did you order Takeout for this month :";
    cin >> Numtakeout;

    if (Numtakeout == 0)
    {
        cout << "No Takeout! Stacking up your Chips!" << endl;
        return total = 0;
    }

    for(int a = 0; a < Numtakeout; a++)
    {
        cout << "How much was Takeout #" << (a + 1) << ": ";
        cin >> takeout;
        total += takeout;
    }
    cout << "The Total Cost of Takeout for this Month is $" << total << endl;
    return total;
}
double MonthlyHaircut(double haircut)
{
    int Numhaircut = 0;
    double total = 0;

    cout << "How many times did you get a haircut for this month :";
    cin >> Numhaircut;

    if (Numhaircut == 0)
    {
        cout << "No Trim! Bro you need to look fresh!" << endl;
        return total = 0;
    }

    for(int a = 0; a < Numhaircut; a++)
    {
        cout << "How much was Haircut #" << (a + 1) << ": ";
        cin >> haircut;
        total += haircut;
    }
    cout << "The Total Cost of haircuts for this Month is $" << total << endl;
    return total;
}
