#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <iostream>

class Bureaucrat; // Forward declaration

class Form {
public:
	Form() = delete;
	Form(const std::string& name, int sign_grade, int exec_grade);
	~Form() = default;
	Form(const Form &other);
	Form& operator=(const Form &other);
	const std::string& getName() const;
	bool isSigned() const;
	int getMinimumSignGrade() const;
	int getMinimumExecuteGrade() const;
	void beSigned(const Bureaucrat& bureaucrat);

	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const noexcept override;
	};
private:
	const std::string _name;
	bool _signed;
	const int _minimum_sign_grade;
	const int _minimum_execute_grade;
};


std::ostream& operator<<(std::ostream& os, const Form& form);


#endif