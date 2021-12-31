class cashRegister{
	private:
		int cashOnHand;
	public:
		cashRegister();
		cashRegister(int cashIn);
		int getCurrentBalance();
		void acceptAmount(int amountIn);
};

cashRegister::cashRegister(){
	cashOnHand = 500;
}

cashRegister::cashRegister(int cashIn){
	cashOnHand = cashIn; 
}

int cashRegister::getCurrentBalance(){
	return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn){
	cashOnHand = cashOnHand + amountIn;
}

class dispenserType{
	private:
		int numberOfItems;
		int cost;
	public:
		dispenserType();
		dispenserType(int setCost, int setNumberOfItems);
		int getNoOfItems();
		int getCost();
		void makeSale();
};

dispenserType::dispenserType(){
	cost = 50;
	numberOfItems = 50;
}

dispenserType::dispenserType(int setCost, int setNumberOfItems){
	cost = setCost;
	numberOfItems = setNumberOfItems;
}

int dispenserType::getNoOfItems(){
	return numberOfItems;
}

int dispenserType::getCost(){
	return cost;
}

void dispenserType::makeSale(){
	numberOfItems--;
}

#include <iostream>
using namespace std;
void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);
int main(){
	cashRegister counter;
	dispenserType candy(100,50);
	dispenserType chips(100,50);
	dispenserType gum(75,45);
	dispenserType cookies(50,85);
	int choice;
	showSelection();
	cin >> choice;
	while(choice !=5)
	{
		switch (choice)
		{
		case 1:
			sellProduct(candy, counter);
			break;
		
		case 2:
			sellProduct(chips, counter);
			break;

		case 3:
			sellProduct(gum, counter);
			break;
		
		case 4:
			sellProduct(cookies, counter);
			break;

		default:
			cout << "Invalid selection" << endl;
		}
		showSelection();
		cin >> choice;
	}
	return 0;
}

void showSelection(){
	cout << "Welcome to candy machine" << endl;
	cout << "1. Candies" << endl;
	cout << "2. Chips" << endl;
	cout << "3. Gum" << endl;
	cout << "4. Cookies" << endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter)
{
	int amount;
	int extra_amount;
	if (product.getNoOfItems() > 0)
	{
		cout << "Please deposit " << product.getCost() << " cents" << endl;
		cin >> amount;
		if (amount < product.getCost())
		{
			cout << "Please deposit another " << product.getCost() - amount << endl;
			cin >> extra_amount;
			amount = amount + extra_amount;
		}

		if (amount >= product.getCost())
		{
			pCounter.acceptAmount(amount);
			product.makeSale();
			cout << "Collect your item." << endl;
			amount = amount - product.getCost();
			cout << "Here you are " << amount << " cents. " <<  endl; 
		}

		else cout << "The amount is not enough" << endl;
	}
	else cout << "This item is sold out" << endl;
}
