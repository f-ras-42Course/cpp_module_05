#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Form & Bureaucrat Test ====\n";
	
	try {
		Bureaucrat johnny("Johnny", 10);
		Bureaucrat alex("Alex", 100);
		
		Form form1("Taxation Sheet", 50, 30);
		Form form2("Confidential Document", 5, 1);
		
		std::cout << "\nBureaucrats:" << std::endl;
		std::cout << johnny << std::endl;
		std::cout << alex << std::endl;
		
		std::cout << "\nForms:" << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		
		std::cout << "\n---- Signing Tests ----\n";
		johnny.signForm(form1);  // Should work
		alex.signForm(form1);    // Should fail
		johnny.signForm(form2);  // Should fail

		std::cout << "\n---- Exception Tests ----\n";
		try {
			Form invalid("Bad Form", 0, 50);
		} catch (const Form::GradeTooHighException& e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		
		try {
			Bureaucrat invalid("Bad Guy", 151);
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}