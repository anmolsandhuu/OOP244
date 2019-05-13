// Libraries
#include <iomanip>
#include <fstream>
#include <cstring>
// Headers
#include "Product.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace AMA {
    // Checked
	void Product::name(const char *Name)
	{

        if (Name != nullptr)
        {
            product_name = nullptr;
            product_name = new char[max_name_length + 1];
            strncpy(product_name, Name, max_name_length + 1);
        }
	}
    
    // Checked
	const char *Product::name() const
	{
        return product_name;
	}
    
    // Checked
	const char *Product::sku() const
	{
		return product_sku;
	}
    
    // Checked
	const char *Product::unit() const
	{
		return product_unit;
	}
    
    // Checked
	bool Product::taxed() const
	{
		return taxable;
	}
    
    // Checked
	double Product::price() const
	{
		return prunit_price;
	}
    
    // Checked
	double Product::cost() const
	{
        if(taxed()){
            return (1 + tax_rate) * price();
        } else {
            return price();
        }
	}
    
    // Checked
	void Product::message(const char *errormessage) {
		error.message(errormessage);
	}

	bool Product::isClear() const {
        return error.isClear();
	}

    // Checked
	Product::Product(const char prname) {
		product_type = prname;
		product_sku[0] = '\0';
		product_unit[0] = '\0';
		currproduct_qty = 0;
		product_name = nullptr;
		needproduct_qty = 0;
		prunit_price = 0.00;
		//taxable = true;
	}
    
    // Checked
	Product::Product(const char *productsku, const char *productname,
                     const char *productunit, int prodqty , bool taxstatus ,
                     double prprice , int qtyneeded)
	{
		name(productname);
		strncpy(this -> product_sku, productsku, max_sku_length + 1);
		strncpy(this -> product_unit, productunit, max_unit_length + 1);
        
		this -> currproduct_qty = prodqty;
		this -> taxable = taxstatus;
		this -> prunit_price = prprice;
		this -> needproduct_qty = qtyneeded;

	}

    // Checked
	Product::Product(const Product &obj) {
        if(obj.product_name != nullptr){
            *this = obj;
        }
	}

    // Checked
	Product & Product::operator=(const Product & rhs)
	{
		if (this != &rhs) {
            name(rhs.product_name);
            strncpy(this -> product_sku, rhs.product_sku, max_sku_length + 1);
            strncpy(this -> product_unit, rhs.product_unit, max_unit_length + 1);
            
            this -> currproduct_qty = rhs.currproduct_qty;
            this -> taxable = rhs.taxable;
            this -> prunit_price = rhs.prunit_price;
            this -> needproduct_qty = rhs.needproduct_qty;
		}
		return *this;
	}
    
    // Checked
	Product::~Product() {
		delete [] product_name;
        this -> error.clear();
	}
    
    // Checked
	fstream& Product::store(fstream& file, bool newLine) const {
        // Write code ->> change positions for printing
        file << product_type << ',';
        file << product_sku << ',';
        file << product_name << ',';
		file << product_unit << ',';
        file << taxable;
        file << prunit_price << ',';
		file << currproduct_qty << ',';
		file << needproduct_qty << ',';
        
        if(newLine){
            file << endl;
        }
        
        return file;
	}
    
    // ?
	fstream& Product::load(fstream& file) {
        
        Product temp;
        return file;
	}
    
    // ?
	ostream& Product::write(ostream& os, bool linear) const {
        if(this -> isClear() != 1){
            os << this -> error.message();
            return os;
        }
        
        if(linear){
            os << setw(max_sku_length) << left;
            os << sku() << "|";
            os << setw(20) << left;
            os << name() << "|";
            os << setw(7) << fixed << setprecision(2) << right;
            os << cost() << "|";
            os << setw(4) << right;
            os << quantity() << "|";
            os << setw(10) << left;
            os << unit() << "|";
            os << setw(4) << right;
            os << qtyNeeded() << "|";
            
        } else {
            os << " SKU : " << sku() << endl;
            os << " Name (no spaces): " << name() << endl;
            os << " Price : " << price() << endl;
            
            if (this -> taxed()){
                os << " Price after tax : " << cost() << endl;
            } else {
                os << " Price after tax : N/A" << endl;
            }
            
            os << " Quantity on hand : " << quantity();
            os << ' ' << product_unit << endl;
            os << " Quantity Needed : " << qtyNeeded();
        }
        
        return os;
	}

	istream& Product::read(std::istream& is) {
        // Rewrite
		Product temp;
        temp.product_name = new char[max_name_length];
        char tax;
        
        cout << " Sku: ";
        is >> temp.product_sku;
        
        cout << " Name (no spaces): ";
        is >> temp.product_name;
        
        cout << " Unit: ";
        is >> temp.product_unit;
        
        cout << " Taxed? (y/n): ";
        is >> tax;
        
        if(tax == 'Y' || tax == 'y'){
             temp.taxable= true;
        } else if(tax == 'N' || tax == 'n'){
            temp.taxable = false;
        } else {
            is.setstate(ios::failbit);
            temp.error.message("Only (Y)es or (N)o are acceptable");
        }
        
        if (!is.fail()) {
            cout << " Price: ";
            is >> temp.prunit_price;
            if (is.fail()) {
                temp.error.message("Invalid Price Entry");
            }
        }
        
        if (!is.fail()) {
            cout << " Quantity on hand: ";
            is >> temp.currproduct_qty;
            if (is.fail()) {
                temp.error.message("Invalid Quantity Entry");
            }
        }
        
        if (!is.fail()) {
            cout << " Quantity needed: ";
            is >> temp.needproduct_qty;
            if (is.fail()) {
                temp.error.message("Invalid Quantity Needed Entry");
            }
        }
        
        if (!is.fail()) {
            *this = temp;
        }
        
        delete [] temp.product_name;
        temp.product_name = nullptr;
        
        return is;
	}
    
    //
	bool  Product::operator==(const char* mysku) const {
        return strcmp(mysku, product_sku);
	}
    
    // Checked
	double Product::total_cost() const {
		return cost() * currproduct_qty;
	}
    
    // Checked
	void  Product::quantity(int numofunits) {
		currproduct_qty = numofunits;
	}
    
    // Checked
	bool Product::isEmpty() const {
        return product_name == nullptr;
	}
    
    // Checked
    int Product::qtyNeeded() const {
		return needproduct_qty;
	}
	
    // Checked
    int Product::quantity() const {
		return currproduct_qty;

	}
    
    // Cheched
	bool Product::operator>(const char* productsku) const {
        return strcmp(this -> product_sku, productsku) > 0;
	}

    // Checked
	bool Product::operator>(const Product& prodname) const {
        return strcmp(this -> product_name, prodname.product_name) > 0;
	}
    
    //Checked
	int Product:: operator+=(int added) {
		if (added > 0) {
			currproduct_qty += added;
		}
        return currproduct_qty;
	}
    
    // Checked
	ostream& operator<<(ostream&os, const Product&prod) {
		prod.write(os, true);
		return os;
	}

    // Checked
	istream& operator>>(istream& is, Product& myprod) {
		myprod.read(is);
        return is;
	}

    // Checked
	double operator+=(double& dreceived, const Product& calacualted) {
		dreceived += calacualted.total_cost();
		return dreceived;
	}

}
