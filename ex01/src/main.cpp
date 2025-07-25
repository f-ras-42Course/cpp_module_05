#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bobbie("Bobbie", 149);
		Bureaucrat tom("Tom", 2);

		tom.incrementGrade();
		bobbie.decrementGrade();
		
		// tom.incrementGrade();
		// bobbie.decrementGrade();
		// Bureaucrat gerard("Gerard", 151);
		// Bureaucrat mitchel("Mitchel", -1);

		std::cout << bobbie;
		std::cout << tom;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}