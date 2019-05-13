
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <fstream>
#include "ErrorState.h"
const int max_sku_length = 7; // Maximum number of characters in a sku 
const int  max_unit_length = 10; //  Maximum number of characters in the units’ descriptor for a product
const int  max_name_length = 75; //   Maximum number of characters in the user’s name descriptor for a product length
const double tax_rate = 0.13;

namespace AMA {
	class Product {
	private:

		char product_type;//A character that indicates the type of the product 
		char product_sku[max_sku_length + 1]; //A character array that holds the product’s sku (stock keeping unit)
		char product_unit[max_unit_length + 1];//A character array that describes the product’s unit
		char * product_name;//A pointer that holds the address of a C-style string in dynamic memory containing the name of the product. 
		int currproduct_qty; //An integer that holds the quantity of the product currently on hand
		int needproduct_qty;//An integer that holds the quantity of the product needed
		double prunit_price;// A double that holds the price of a single unit of the product before any taxes
		bool taxable; // A bool that identifies the taxable status of the product
		ErrorState error;//An ErrorState object that holds the error state of the Product object

	protected:

		void name(const char* Name);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		void message(const char*);
		bool isClear() const;

	public:

		Product(const char prname = 'N');
		Product(const char*, const char*, const char*, int prodqty = 0,
                bool taxstatus = true, double prprice = 0.00, int  qtyneeded = 0);
		Product(const Product &obj);
		Product& operator=(const Product& rhs);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear = true) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		double cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product& prodname) const;
		int operator+=(int);


	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);

}
#endif
