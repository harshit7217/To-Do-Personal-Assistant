#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>

int main() {
    std::tm userTime = {};
    int year, month, day, hour, minute, second;

    // Input date and time
    std::cout << "Enter year (e.g., 2024): ";
    std::cin >> year;

    std::cout << "Enter month (1-12): ";
    std::cin >> month;

    std::cout << "Enter day (1-31): ";
    std::cin >> day;

    std::cout << "Enter hour (0-23): ";
    std::cin >> hour;

    std::cout << "Enter minute (0-59): ";
    std::cin >> minute;

    std::cout << "Enter second (0-59): ";
    std::cin >> second;

    // Validate input
    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::cerr << "Error: Invalid date entered!" << std::endl;
        return 1;
    }
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        std::cerr << "Error: Invalid time entered!" << std::endl;
        return 1;
    }

    // Assign to tm structure
    userTime.tm_year = year - 1900;  // Year since 1900
    userTime.tm_mon = month - 1;    // 0-based month
    userTime.tm_mday = day;
    userTime.tm_hour = hour;
    userTime.tm_min = minute;
    userTime.tm_sec = second;

    // Convert to time_t
    std::time_t enteredTime = std::mktime(&userTime);
    if (enteredTime == -1) {
        std::cerr << "Error: Could not process date and time!" << std::endl;
        return 1;
    }

    // Display date and time
    std::cout << "You entered: "
              << std::put_time(std::localtime(&enteredTime), "%Y-%m-%d %H:%M:%S")
              << std::endl;

    return 0;
}
