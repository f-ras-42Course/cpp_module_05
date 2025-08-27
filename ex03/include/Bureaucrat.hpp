#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>

class AForm;

class Bureaucrat {
public:
	Bureaucrat() = delete;
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat() = default;
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other) = delete;
	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& form);
	void executeForm(const AForm& form) const;

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
	const std::string	name_;
	int					grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif