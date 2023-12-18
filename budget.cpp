#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        //Assume POSIX
        system("clear");
    #endif
}

int main() 
{
    int jobQuantity;               //How many jobs you're working

    std::cout << "Enter the number of jobs you have: ";
    std::cin >> jobQuantity;       //Fill in job quantity

    //Check for a valid number
    if (jobQuantity <= 0) 
    {
        std::cerr << "Invalid number of jobs. Exiting program." << std::endl;
        return 1;
    }

    double hours[jobQuantity];
    double wages[jobQuantity];      //Fill in arrays based on job quantity
    double totalHours = 0.0, totalWages = 0.0, totalEarnings = 0.0;
    double estimatedRent;


    //--Loop based on the number of jobs--
    for (int i = 0; i < jobQuantity; ++i) 
    {
        //std::cout << "Processing job " << (i + 1) << "/" << jobQuantity << std::endl; //Confirming

        std::cout << "Enter the number of hours worked per week for job " << (i + 1) << ": "; //Hours worked
        std::cin >> hours[i];
        totalHours += hours[i];

        std::cout << "Enter the wage per hour for job " << (i + 1) << ": "; //Wage earned
        std::cin >> wages[i];
        totalWages += wages[i] * hours[i];
    }

    std::cout << "How much do you want to pay per month for rent? $";
    std::cin >> estimatedRent;

    double averageMealCost;
    std::cout << "How much is your expected average cost per meal? $";
    std::cin >> averageMealCost;
    double monthlyFoodExpense = averageMealCost * 3 * 30;


    clearScreen();
    
    totalEarnings = totalWages;
    double averageWage = (jobQuantity > 0) ? (totalWages / totalHours) : 0;
    double yearlyEarnings = totalEarnings * 52;
    double monthlyEarnings = yearlyEarnings / 12;
    double netEarnings = yearlyEarnings;
    double netMoEarnings = monthlyEarnings;

    std::cout << std::fixed << std::setprecision(2); //Format the output
    
    std::cout << "Hours worked in a week: " << totalHours << std::endl;
    std::cout << "Average hourly wage: $" << averageWage << std::endl;
    std::cout << "Weekly wage: $" << totalEarnings << std::endl;
    std::cout << "Monthly wage: $" << monthlyEarnings << std::endl;
    std::cout << "Yearly wage: $" << yearlyEarnings << std::endl;

    std::cout << "\n::: Tax Calculation :::" << std::endl;
    if (yearlyEarnings < 20000) 
    {
        std::cout << "• Yearly wage with 15% tax: $" << yearlyEarnings * 0.85 << std::endl;
        std::cout << "• Yearly wage with 20% tax: $" << yearlyEarnings * 0.80 << std::endl;
        std::cout << "• Yearly wage with 25% tax: $" << yearlyEarnings * 0.75 << std::endl;
        netEarnings = yearlyEarnings * 0.75;
        netMoEarnings = monthlyEarnings * 0.75;
    } else if (yearlyEarnings < 50000) 
    {
        std::cout << "• Yearly wage with 20% tax: $" << yearlyEarnings * 0.80 << std::endl;
        std::cout << "• Yearly wage with 25% tax: $" << yearlyEarnings * 0.75 << std::endl;
        std::cout << "• Yearly wage with 30% tax: $" << yearlyEarnings * 0.70 << std::endl;
        netEarnings = yearlyEarnings * 0.70;
        netMoEarnings = monthlyEarnings * 0.70;
    } else 
    {
        std::cout << "• Yearly wage with 20% tax: $" << yearlyEarnings * 0.80 << std::endl;
        std::cout << "• Yearly wage with 30% tax: $" << yearlyEarnings * 0.70 << std::endl;
        std::cout << "• Yearly wage with 35% tax: $" << yearlyEarnings * 0.65 << std::endl;
        netEarnings = yearlyEarnings * 0.65;
        netMoEarnings = monthlyEarnings * 0.65;
    }

    double affordableRent = monthlyEarnings * 0.30;
    affordableRent = std::ceil(affordableRent / 100.0) * 100.0;
    //affordableRent = std::round(affordableRent / 100.0) * 100.0;  //rounded down
    double rentPercentage = (estimatedRent / monthlyEarnings) * 100;
    double salaryLeftOver = monthlyEarnings - estimatedRent;
    salaryLeftOver -= monthlyFoodExpense;

    std::cout << "::: END OF Tax Calculation :::" << std::endl;
    
    std::cout << "\nOptimal Rent: $" << affordableRent << "/mo" << std::endl;
    std::cout << "Inputted Rent: $" << estimatedRent << "/mo" << std::endl;
    std::cout << "Percentage of Salary in Rent: " << rentPercentage << "%" << std::endl;
    std::cout << "Food cost per day: " << averageMealCost * 3 << std::endl;
    std::cout << "Food cost per month: " << monthlyFoodExpense << std::endl;
    std::cout << "Salary left over after Rent & Food: $" << salaryLeftOver << "/mo" << std::endl;

    return 0;
}