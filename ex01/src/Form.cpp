#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int sign_grade, int exec_grade)
:	_name(name), _signed(false), \
	_minimum_sign_grade(sign_grade), _minimum_execute_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1) {
		throw GradeTooHighException();
	}
	if (sign_grade > 150 || exec_grade > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form &other)
:	_name(other._name), _signed(other._signed), 
	_minimum_sign_grade(other._minimum_sign_grade), 
	_minimum_execute_grade(other._minimum_execute_grade) {
}

Form& Form::operator=(const Form &other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getMinimumSignGrade() const {
	return _minimum_sign_grade;
}

int Form::getMinimumExecuteGrade() const {
	return _minimum_execute_grade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _minimum_sign_grade) {
		throw GradeTooLowException();
	}
	_signed = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "____________________________________________\n"
	   << "| Form Name: " << form.getName()
	   << "\n| Signed: " << (form.isSigned() ? "Yes" : "No")
	   << "\n| Minimum Sign Grade: " << form.getMinimumSignGrade()
	   << "\n| Minimum Execute Grade: " << form.getMinimumExecuteGrade()
	   << "\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾";
	return os;
}
