#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <iostream>

class Bureaucrat;

class AForm {
public:
	// Constructors and Destructor
	AForm() = delete;
	AForm(const std::string& name, int sign_grade, int exec_grade);
	virtual ~AForm() = default;
	AForm(const AForm &other);
	AForm& operator=(const AForm &other) = delete;
	
	// Getters
	const std::string& getName() const;
	bool isSigned() const;
	int getMinimumSignGrade() const;
	int getMinimumExecuteGrade() const;

	// Action methods
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(const Bureaucrat& executor) const;

	// Exception classes
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const noexcept override;
	};
	class FormNotSignedException : public std::exception {
	public:
		const char* what() const noexcept override;
	};

protected:
	virtual void executeAction() const = 0;

private:
	const std::string	_name;
	bool				_signed;
	const int			_minimum_sign_grade;
	const int			_minimum_execute_grade;
	const std::string	_target;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif