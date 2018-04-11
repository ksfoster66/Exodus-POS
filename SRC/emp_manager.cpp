#include "emp_manager.hpp"

	//map<int, Employee> employee_map; //Main directory, maps ID number to employee
	
	//int num_employed;//Number of current employees
	
	//EmpManager(){} //Already implemented
	
	//Getters and setters
	Employee* EmpManager::getEmployee(int id){
		return employee_map[id];
	}
	
	int EmpManager::getNumEmployees(){
		return num_employed;
	}
	
	std::vector<Employee*> EmpManager::getEmployees(std::string name){
		std::vector<Employee*> list;
		for(std::map<int, Employee*>::iterator it = employee_map.begin(); it!=employee_map.end(); it++){
			if (name == it->second->getName()) list.push_back(it->second);
		}
		return list;
	}
	
	void EmpManager::addEmployee(Employee *e){
		int id = e->getID();
		employee_map.insert( std::pair<int, Employee*>(id, e));
		num_employed++;
	}
	
	void EmpManager::removeEmployee(int ID){
		employee_map.erase(ID);
		num_employed--;
	}
