#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "====| Creating Bureaucrats and changing values\n";
		Bureaucrat bobbie("Bobbie", 149);
		std::cout << bobbie;
		bobbie.decrementGrade();
		std::cout << bobbie;
		Bureaucrat tom("Tom", 2);
		std::cout << tom;
		tom.incrementGrade();
		std::cout << tom;

		std::cout << "\n====| Over-incrementing and decrementing grades\n";
		try {
			tom.incrementGrade();
		} catch (std::exception & e) {
			std::cerr << "Exception caught for Tom: " << e.what() << std::endl;
		}
		try {
			bobbie.decrementGrade();
		} catch (std::exception & e) {
			std::cerr << "Exception caught for Bobbie: " << e.what() << std::endl;
		}

		std::cout << "\n====| Testing exceptions for invalid grades\n";
		try {
			Bureaucrat gerard("Gerard", 151);
		} catch (std::exception & e) {
			std::cerr << "Exception caught for Gerard: " << e.what() << std::endl;
		}
		try {
			Bureaucrat mitchel("Mitchel", -1);
		} catch (std::exception & e) {
			std::cerr << "Exception caught for Mitchel: " << e.what() << std::endl;
		}

	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}