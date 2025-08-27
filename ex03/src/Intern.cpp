#include "Intern.hpp"
#include <iostream>

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	switch (getFormType(formName)) {
		case SHRUBBERY:
			std::cout << "Intern creates " << formName << std::endl;
			return createShrubberyForm(target);
		case ROBOTOMY:
			std::cout << "Intern creates " << formName << std::endl;
			return createRobotomyForm(target);
		case PRESIDENTIAL:
			std::cout << "Intern creates " << formName << std::endl;
			return createPresidentialForm(target);
		default:
			std::cout << "Intern could not find the form: " << formName << std::endl;
			return nullptr;
	}
}

AForm* Intern::createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

FormType getFormType(const std::string& formName) {
	if (formName == "shrubbery creation") return SHRUBBERY;
	if (formName == "robotomy request") return ROBOTOMY;
	if (formName == "presidential pardon") return PRESIDENTIAL;
	return UNKNOWN;
}