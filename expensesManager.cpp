#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "Expense.h" // Include the Expense header
#include <vector> // Include vector for storing expenses
#include <fstream> // Include fstream for file I/O
#include <exception> // Include exception for error handling

// Class to manage a collection of expenses
class ExpenseManager {
private:
    std::vector<Expense*> expenses; // Vector to store pointers to Expense objects

public:
    // Destructor to clean up dynamically allocated memory
    ~ExpenseManager() {
        for (Expense* expense : expenses) {
            delete expense; // Delete each dynamically allocated Expense object
        }
    }

    // Function to add an expense to the collection
    void addExpense(Expense* expense) {
        expenses.push_back(expense); // Add expense pointer to the vector
    }

    // Function to display all stored expenses
    void displayAllExpenses() const {
        if (expenses.empty()) { // Check if the list is empty
            std::cout << "No expenses recorded.\n";
        } else {
            for (const Expense* expense : expenses) {
                expense->displayExpense(); // Call the virtual displayExpense method
            }
        }
    }

    // Function to save expenses to a file
    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename); // Open file for writing
        if (!outFile) {
            throw std::runtime_error("Failed to open file for writing."); // Error if file can't be opened
        }
        for (const Expense* expense : expenses) {
            outFile << expense->getAmount() << "," // Write amount
                    << expense->getCategory() << "," // Write category
                    << expense->getDate() << "\n"; // Write date
        }
    }

    // Function to load expenses from a file
    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename); // Open file for reading
        if (!inFile) {
            throw std::runtime_error("Failed to open file for reading."); // Error if file can't be opened
        }

        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line); // Parse the line
            std::string amt, cat, dt;
            if (std::getline(iss, amt, ',') && // Extract amount
                std::getline(iss, cat, ',') && // Extract category
                std::getline(iss, dt)) { // Extract date
                double amount = std::stod(amt); // Convert amount to double
                expenses.push_back(new VariableExpense(amount, cat, dt)); // Add as VariableExpense
            }
        }
    }
};

#endif // EXPENSEMANAGER_H
