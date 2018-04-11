/*
Keeps track of all employees
Employees are searchable by last name and employee ID number
*/
#ifndef EMP_MANAGER_HPP
#define EMP_MANAGER_HPP

#include "employee.hpp"
#include <map>
#include <vector>
#include <string>

class EmpManager{
	std::map<int, Employee*> employee_map; //Main directory, maps ID number to employee
	
	int num_employed;//Number of current employees
	
	
public:
	//Methods
	//Constructor + destructors
	EmpManager(){
		num_employed = 0;
	}
	
	//Getters and setters
	Employee* getEmployee(int id);
	
	int getNumEmployees();
	
	std::vector<Employee*> getEmployees(std::string name);
	
	//Modifiers
	
	void addEmployee(Employee *e);
	
	void removeEmployee(int ID);

};

#endif
