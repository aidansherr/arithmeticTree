#include "ArithmeticTree.h"

ArithmeticTree::ArithmeticTree()
{
	// initialize all the variables to a standard value
	A = -1;   
	B = -1;
	C = -1;
	D = -1;
	expression = "ABC+*D/";
	tmpexpr = "";
	treeExpr = "";
}

ArithmeticTree::~ArithmeticTree()
{
	TreeNode * tmp = expr.top();
	delete tmp;
	expr.pop();
	std::cout << "Expr stack empty";
}

void ArithmeticTree::setValues()
{
	std::cout << "Please enter an integer value for each of the following variables : ";
	while (std::cout << "\nA = " && !(std::cin >> A)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, enter an integer.\n";
	}
	while (std::cout << "\nB = " && !(std::cin >> B)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, enter an integer.\n";
	}
	while (std::cout << "\nC = " && !(std::cin >> C)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, please enter an integer.\n";
	}
	while (std::cout << "\nD = " && !(std::cin >> D)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, please enter an integer.\n";
	}
	std::cout << std::endl;
}
TreeNode * ArithmeticTree::createTree()
{	
	TreeNode *node, *left, *right;				// used to create a new node with a left and right ptr
	std::string subexpr;						// used to parse expression
	int len = expression.length();				// obtain length of expr string to iterate through 
	for (int i = 0; i < len; i++)
	{
		subexpr = expression.substr(i,1);		// get index in expr string
		
		// if an operator, create a tree with operands from stack
		if (subexpr == "+" || subexpr == "-" ||
			subexpr == "*" || subexpr == "/")
		{
			right = expr.top();
			expr.pop();
			left = expr.top();
			expr.pop();
			node = new TreeNode();
			node->setName(subexpr);
			node->setLeft(left);
			node->setRight(right);
			expr.push(node);
		}
		// else if operand, push on to stack as own tree with no children
		else if ((subexpr >= "a" || subexpr <= "z") ||
			(subexpr >= "A" || subexpr <= "Z"))
		{
			node = new TreeNode();
			node->setName(subexpr);
			expr.push(node);
		}
		// if neither operand or operator, exit. Tree is invalid.
		else
		{
			std::string msg = "Invalid tree. Exiting...";
			throw std::string(msg);
		}
	}

	//return ptr to root of tree
	return expr.top();
}

void ArithmeticTree::traverseTree(TreeNode * tree)
{
	// if the node is not null, get the left side and then the right recursively
	if (tree != nullptr)
	{
		traverseTree(tree->getLeft());
		traverseTree(tree->getRight());
		tmpexpr += tree->getName();		// as the tree is traversed recursively, 
										// record the characters in a tmp expr to 
										// set the values before evaluating
	}
}

void ArithmeticTree::solveTree(TreeNode * tree)
{
	traverseTree(tree);								// get tmpexpr to input values
	int len = static_cast<int>(tmpexpr.length());	// length of tmpexpr to iterate through string
	char tmpchar;									// used for index in string
	std::stack <int> workingexpr;					// stack to keep track of operands in expr
	int operand1;									// first operand on stack	
	int operand2;									//second operand on stack
	int tmp;
	for (int i = 0; i < len; i++)
	{
		tmpchar = tmpexpr[i];						// get index in expr string

		// if operator, add to final expression and then evaluate first two operands on stack
		// and push the result onto the stack as a new operand
		if (tmpchar == '+' || tmpchar == '-' ||
			tmpchar == '*' || tmpchar == '/')
		{
			treeExpr += tmpchar;
			operand1 = workingexpr.top();
			workingexpr.pop();
			operand2 = workingexpr.top();
			workingexpr.pop();
			switch (tmpchar)
			{
			case '+':
				tmp = operand2 + operand1;
				workingexpr.push(tmp);
				break;
			case '-':
				tmp = operand2 - operand1;
				workingexpr.push(tmp);
				break;
			case '*':
				tmp = operand2 * operand1;
				workingexpr.push(tmp);
				break;
			case '/':
				if (operand1 == 0)
				{
					std::cout << "Error calculating result. Cannot divide by 0. Result will skip division.";
					tmp = operand2;
					workingexpr.push(tmp);
				}
				else
				{
					tmp = operand2 / operand1;
					workingexpr.push(tmp);
				}
				break;
			default:
				std::cout << "Invalid operator. Expression evaluation will not be valid.";
				break;
			}
		}
		// if operand, add to final expression and then push onto stack
		else if ((tmpchar >= 'a' || tmpchar <= 'z') || 
			(tmpchar >= 'A' || tmpchar <= 'Z'))
		{
			switch (tmpchar)
			{
			case 'A':
				treeExpr += std::to_string(A);
				workingexpr.push(A);
				break;
			case 'B':
				treeExpr += std::to_string(B);
				workingexpr.push(B);
				break;
			case 'C':
				treeExpr += std::to_string(C);
				workingexpr.push(C);
				break;
			case 'D':
				treeExpr += std::to_string(D);
				workingexpr.push(D);
				break;
			default:
				std::cout << "\nLetter in expression out of range. Expression evaluation will not be valid.\n";
				break;
			}
		}
	}
	tmpexpr = "";					// reset tmpexpr to evaluate a new expression
	solution = workingexpr.top();	// store the result 
}
void ArithmeticTree::printValues()
{
	std::cout << "Values: \nA = " << A << std::endl << "B = " << B << std::endl << "C = " << C << std::endl << "D = "
		<< D << std::endl;
}
void ArithmeticTree::printSolution()
{
	std::cout << "\nThe solution to the expression with the provided values is " << solution << std::endl;
}
void ArithmeticTree::printExpression()
{
	//hardcoded expression
	std::cout << "\nThe expression to be evaluated in postfix form is: " << expression << std::endl;
}
void ArithmeticTree::printValExpr()
{
	//expression with values in place
	std::cout << "\nThe expression with the values being evaluated is: " << treeExpr;
	treeExpr = "";					// reset treeExpr to be used again
}
