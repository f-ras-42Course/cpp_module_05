#include "AForm.hpp"
#include "Bureaucrat.hpp"


// Constructors and Destructor
AForm::AForm(const std::string& name, int sign_grade, int exec_grade)
:	_name(name), _signed(false), \
	_minimum_sign_grade(sign_grade), _minimum_execute_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1) {
		throw GradeTooHighException();
	}
	if (sign_grade > 150 || exec_grade > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm &other)
:	_name(other._name), _signed(other._signed), 
	_minimum_sign_grade(other._minimum_sign_grade), 
	_minimum_execute_grade(other._minimum_execute_grade) {
}

// Getters
const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _signed;
}

int AForm::getMinimumSignGrade() const {
	return _minimum_sign_grade;
}

int AForm::getMinimumExecuteGrade() const {
	return _minimum_execute_grade;
}


// Action methods
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _minimum_sign_grade) {
		throw GradeTooLowException();
	}
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > _minimum_execute_grade)
        throw GradeTooLowException();
    executeAction();
}


// Execute method
const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const noexcept {
    return "Form is not signed.";
}


std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	os << "____________________________________________\n"
	   << "| Form Name: " << AForm.getName()
	   << "\n| Signed: " << (AForm.isSigned() ? "Yes" : "No")
	   << "\n| Minimum Sign Grade: " << AForm.getMinimumSignGrade()
	   << "\n| Minimum Execute Grade: " << AForm.getMinimumExecuteGrade()
	   << "\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";
	return os;
}
