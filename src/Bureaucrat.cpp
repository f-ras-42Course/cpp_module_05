#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name_(name), grade_(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}


const char* GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}