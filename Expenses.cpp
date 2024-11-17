#ifndef EXPENSE_H
#define EXPENSE_H

#include <string> // Include string for data members like category and date
#include <iostream> // Include iostream for printing purposes

// Base class Expense
class Expense {
protected:
    double amount; // Protected member to store the amount of the expense
    std::string category; // Protected member to store the category of the expense
    std::string date; // Protected member to store the date of the expense

public:
    // Constructor to initialize the base class members
    Expense(double amt, const std::string& cat, const std::string& dt)
        : amount(amt), category(cat), date(dt) {}

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Expense() {}

    // Virtual function to display expense details, to be overridden in derived classes
    virtual void displayExpense() const = 0;

    // Getters for encapsulated data members
    double getAmount() const { return amount; } // Returns the amount
    std::string getCategory() const { return category; } // Returns the category
    std::string getDate() const { return date; } // Returns the date
};

// Derived class for FixedExpense
class FixedExpense : public Expense {
public:
    // Constructor to initialize FixedExpense by calling the base class constructor
    FixedExpense(double amt, const std::string& cat, const std::string& dt)
        : Expense(amt, cat, dt) {}

    // Override displayExpense to display specific details for fixed expenses
    void displayExpense() const override {
        std::cout << "[Fixed Expense] Amount: $" << amount
                  << ", Category: " << category
                  << ", Date: " << date << std::endl;
    }
};

// Derived class for VariableExpense
class VariableExpense : public Expense {
public:
    // Constructor to initialize VariableExpense by calling the base class constructor
    VariableExpense(double amt, const std::string& cat, const std::string& dt)
        : Expense(amt, cat, dt) {}

    // Override displayExpense to display specific details for variable expenses
    void displayExpense() const override {
        std::cout << "[Variable Expense] Amount: $" << amount
                  << ", Category: " << category
                  << ", Date: " << date << std::endl;
    }
};

#endif // EXPENSE_H
