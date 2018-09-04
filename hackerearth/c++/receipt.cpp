#include<iostream>
#include<vector>

using namespace std;
enum ProductType {
    PRODUCT_TYPE_INVALID = 0,
    PRODUCT_TYPE_GENERAL = 1,
    PRODUCT_TYPE_MEDICAL = 2,
    PRODUCT_TYPE_MAX = 3,
};

ProductType find_product_type(const string& name)
{

    if(name.find("pill")!=std::string::npos )
    {
        return PRODUCT_TYPE_MEDICAL;
    }
    else
    {
        return PRODUCT_TYPE_GENERAL;
    }
}

class Product
{
    protected:
    string name;
    double price;
    int quantity;
    double sales_tax_percentage;
    double sales_tax;
    double total_price;
    virtual void calculate_sales_tax()
    {
        sales_tax = ((double)quantity)*price*sales_tax_percentage/100;
    };

    virtual void calculate_product_price()
    {
        total_price = ((double)quantity)*price + sales_tax;
    };

    public:
    Product(){};
    double get_product_taxed_price()
    {
        calculate_product_price();
        return total_price;
    };
    double get_product_sales_tax()
    {
        calculate_sales_tax();
        return sales_tax;
    };
    string& get_name()
    {
        return name;
    }
    int get_quantity()
    {
        return quantity;
    }
};

class MedicalProduct : public Product
{
    public:
    MedicalProduct(const string& ip_name, double ip_price, int ip_quantity)
    {
        this->name = ip_name;
        this->price = ip_price;
        this->quantity = ip_quantity;
        this->sales_tax_percentage = 0.0; 
    };
};

class GeneralProduct : public Product
{
    public:
    GeneralProduct(const string& ip_name, double ip_price, int ip_quantity)
    {
        this->name = ip_name;
        this->price = ip_price;
        this->quantity = ip_quantity;
        this->sales_tax_percentage = 20.0; 
    };

};

class Billing
{
    double total;
    double sales_tax_total;
    vector<Product> purchased_product_list;
    public:
    void clear_cart()
    {
        purchased_product_list.clear();

    } 
    ~Billing(){ clear_cart();};
   

    void add_product(int quantity, const string& name, float price)
    {
        ProductType p_type = find_product_type(name);
        Product product;
        if(p_type == PRODUCT_TYPE_GENERAL)
        {
            //cout<<name<<endl;
            GeneralProduct product(name, price, quantity);
            purchased_product_list.push_back(product);
        }
        else if(p_type == PRODUCT_TYPE_MEDICAL)
        {
            //cout<<name<<endl;
            MedicalProduct product(name, price, quantity);
            purchased_product_list.push_back(product);
        }
    };

    void print_bill()
    {
        sales_tax_total = 0.0;
        total = 0.0;
        if(purchased_product_list.size()<2)
        {
            cout<<"Error Message"<<endl;
            return;
        }
        for(auto it=purchased_product_list.begin(); it!=purchased_product_list.end();++it)
        {
            cout<<it->get_quantity()<< " " << it->get_name() << ": " << it->get_product_taxed_price()<<endl;
            sales_tax_total = sales_tax_total + it->get_product_sales_tax();
            total = total + it->get_product_taxed_price();
        }
        cout<<"Sales Tax: "<<sales_tax_total<<endl;
        cout<<"Total: "<<total<<endl;
        cout<<endl;
    };

};

class TestCaseBuilder
{
    Billing* billing;
    
    public:
    TestCaseBuilder() {
        billing = new Billing();
    }
    ~TestCaseBuilder() {
        delete billing;
    }
    
    void add_test_product(int units, const string& product_name, float cost)
    {
        billing->add_product(units, product_name, cost);
    }
    
    void executeTest()
    {
        billing->print_bill();
        billing->clear_cart();
    }
};


int main()
{
    TestCaseBuilder test;
    
    //TC1
    test.add_test_product(1, "book", 30.0);
    test.add_test_product(1, "chocolate", 1.0);
    test.executeTest();
    
    //TC2
    test.add_test_product(1, "bottle of wine", 20.0);
    test.add_test_product(2, "box of headache pills", 4.0);
    test.add_test_product(1, "box of pens", 10.0);
    test.executeTest();
    
    //TC3
    test.add_test_product(1, "pen", 5.0);
    test.executeTest();
}
