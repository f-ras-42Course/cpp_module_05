#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>

class Bureaucrat {
public:
	Bureaucrat() = delete;
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat() = default;
	Bureaucrat(const Bureaucrat& other) = default;
	Bureaucrat& operator=(const Bureaucrat& other) = default;
	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
private:
	std::string name_;
	int 		grade_;
};


// Exception classes
class GradeTooHighException : public std::exception {
public:
	const char* what() const noexcept override;
};
class GradeTooLowException : public std::exception {
public:
	const char* what() const noexcept override;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif