#include "Main.h"
#include "ArithmeticTree.h"


Main::Main()
{
}


Main::~Main()
{
}

using namespace std;

int main()
{
	TreeNode * root = nullptr;											// will point to top of tree
	char done;															// to check if the user is finished
	cout << "Hello! Today we will be solving a postfix expression.\n";  
	ArithmeticTree tree = ArithmeticTree();								
	tree.printExpression();	
	cout << "\nFirst we create the tree.\n";
	try
	{
		//try to create the tree with the hardcoded expression
		root = tree.createTree();
	}
	catch (string e)
	{
		//if the tree cannot be created, exit.
		cout << e << endl;
		return 1;
	}
	do
	{
		cout << "\nThe tree has been created. Now we get the values to solve the expression for.\n";
		tree.setValues();		// obtain values from user to evaluate
		cout << "\nThen we solve the expression we get from the tree.\n";
		tree.solveTree(root);	// traverses the tree and evaluates the expression based on the input values
		cout << "And finally we show our results!";
		tree.printExpression(); // hardcoded expression
		tree.printValues();		// input values
		tree.printValExpr();	// expression with values in it
		tree.printSolution();   // prints result from solveTree
		do
		{
			// check to see if the user would like to input a new set of values
			cout << "Would you like to solve for different values? (Y/N): ";
			cin >> done;
			done = toupper(done); 
		} while (done != 'Y' && done != 'N');
	} while (done != 'N');
	
	return 0;
}
