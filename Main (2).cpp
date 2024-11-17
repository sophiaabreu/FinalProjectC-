#include "ExpenseManager.h" // Include the ExpenseManager header
#include <iostream> // Include iostream for input/output

// Function to display the menu
void displayMenu() {
    std::cout << "Expense Tracker Menu:\n";
    std::cout << "1. Add Fixed Expense\n";
    std::cout << "2. Add Variable Expense\n";
    std::cout << "3. Display All Expenses\n";
    std::cout << "4. Save Expenses to File\n";
    std::cout << "5. Load Expenses from File\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ExpenseManager manager; // Create an instance of ExpenseManager
    bool running = true; // Flag to control the main loop

    while (running) {
        displayMenu(); // Display the menu
        int choice;
        std::cin >> choice; // Get user input

        switch (choice) {
        case 1: {
            double amount;
            std::string category, date;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> date;
            manager.addExpense(new FixedExpense(amount, category, date)); // Add a FixedExpense
            break;
        }
        case 2: {
            double amount;
            std::string category, date;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> date;
            manager.addExpense(new VariableExpense(amount, category, date)); // Add a VariableExpense
            break;
        }
        case 3:
            manager.displayAllExpenses(); // Display all expenses
            break;
        case 4: {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            manager.saveToFile(filename); // Save to file
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            manager.loadFromFile(filename); // Load from file
            break;
        }
        case 6:
            running = false; // Exit the loop
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0; // End program
}
