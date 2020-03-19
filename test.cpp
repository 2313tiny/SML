#include"test.hpp"

void greeting()
{
	std::cout << "************  Welcome to Simpletron *************\n";
	std::cout << "*** Please enter your program one instruction ***\n"
		  << "*** (or data word) at a time. I will type the ***\n"
		  << "*** location number and a question mark(?) .  ***\n";
	std::cout << "*** You then type the word for that location. ***\n"
		  << "*** Type the sentinel -99999 to stop entering.***\n"
	 	  << "*** your program. ***" << std::endl;
	std::cout << "***************************************************\n"; 
}

void loading(matrix & memdump)
{
	int operationOperand=0;
	int location = 0;
	do {
		std::cout << std::setw(2) <<  location << " ? "; 
	        std::cin >> operationOperand;
		memdump (0, location,  operationOperand); 
		++location;
	}  while ( -99999 != operationOperand );
	std::cout << "*** Program loading comleted ***\n"
		  << "*** Program execution begins ***" << std::endl; 
}

void current_state(matrix & memorydump,
		  int & accumulator, 
		  size_t & instructionCounter,
		  size_t & operationCode,
		  size_t & operand,
		  int & instructionRegister )
{
	std::cout << YELLOW ;
	std::cout << "REGISTERS:" << RESET <<  std::endl;
	std::cout << YELLOW ;
	std::cout << "accumulator " << RESET <<  std::setw(18) << std::setfill(' ') 
		  << std::right <<  accumulator ;
	std::cout << YELLOW;
	std::cout << "\ninstructionCounter " << RESET <<  std::setw(11)<< std::setfill(' ') 
		  << std::right << instructionCounter;
	std::cout << YELLOW;
	std::cout << "\ninstructionRegister " << RESET << std::setw(10)<< std::setfill(' ') 
		  << std::right  <<  instructionRegister;
	std::cout << YELLOW;
	std::cout << "\noperationCode "  << RESET <<   std::setw(16) << std::setfill(' ') 
		  << std::right << operationCode;
	std::cout << YELLOW;
	std::cout << "\noperand "  << RESET << std::setw(22) << std::setfill(' ') 
		  << std::right << operand << RESET 
		  << std::endl << std::endl;
	std::cout << GREEN;
	std::cout << "MEMORY:" ;
	std::cout << RESET << std::endl;
	std::cout << memorydump;
}

void init_registers( matrix & memorydump,
		  int & accumulator, 
		  size_t & instructionCounter,
		  size_t & operationCode,
		  size_t & operand,
		  int & instructionRegister )
{
	instructionRegister = memorydump(0,instructionCounter);
	int instructionRegister_temp = instructionRegister;
	if (instructionRegister < 0) {
		 instructionRegister_temp *= -1;
		}
	operationCode = instructionRegister_temp / 100;
	operand = instructionRegister_temp % 100;
	
}

void handling( matrix & memorydump,
		  int & accumulator, 
		  size_t & instructionCounter,
		  size_t & operationCode,
		  size_t & operand,
		  int & instructionRegister )

{
	int data;
	int i = operand / 10;
	int j = operand % 10;
	//std::cout << " i = " << i << " j = " << j << std::endl;
	switch(operationCode){
		case 10:
			std::cout << "read ->";
			std::cin >> data;
			memorydump(i,j, data);
			break;
		case 11:
			std::cout << "write " << std::endl;;
			std::cout << memorydump(i,j);
			break;
		case 20:
			std::cout << "load" << std::endl;
			accumulator = memorydump(i,j);
			break;
		case 21:
			std::cout << "store";
			memorydump(i, j, accumulator);
			break;
		case 30:
			std::cout << "add " << std::endl;
			accumulator = memorydump(i,j) + accumulator;
			break;
		case 31:
			std::cout << "substract " << std::endl;
			accumulator = memorydump(i,j) - accumulator;
			break;
		case 32:
			std::cout << "divide " << std::endl;
			accumulator = memorydump(i,j) / accumulator;
			break;
		case 33:
			std::cout << "multiply " << std::endl;
			accumulator = memorydump(i,j) * accumulator;
			break;
		case 40:
			std::cout << "if.. else" << std::endl;
			break;
		case 41:
			std::cout << "branch to " << i <<"," << j << "if accu < 0" << std::endl;
			break;
		case 42:
			std::cout << "branch to " << i <<"," << j << "if accu = 0" << std::endl;
			break;
		case 43:
			std::cout << "*** Simpletron execution terminated ***" << std::endl;
			break;
		default:
			break;
	}
}

void test_v1()
{
	//DATA
	matrix memorydump;	
	int accumulator = 0;
	size_t instructionCounter = 0;
	size_t operationCode = 0;
	size_t operand = 0;
	int instructionRegister = 0;
	char cr; //watch changing memory step by step

	//PROCEDURE
	greeting();
	loading(memorydump);	
	while( 43 != operationCode ){
	current_state(memorydump, accumulator,
		      instructionCounter, operationCode,
		      operand, instructionRegister);
	init_registers(memorydump, accumulator,
		      instructionCounter, operationCode,
		      operand, instructionRegister);
	handling(memorydump, accumulator,
		      instructionCounter, operationCode,
		      operand, instructionRegister);
		    
		      instructionCounter++;
		      std::cin.get(cr); // watch changin memory step by step
	};
	
}

void test_v2()
{
	//emtpy body
}

void test_v3()
{
	//emtpy body
}

