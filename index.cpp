#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
public:
    string name;
    double price;
    Product(string n, double p) : name(n), price(p) {}
};

class Cart {
private:
    vector<Product> items;
public:
    void addProduct(Product p) {
        items.push_back(p);
        cout << p.name << " added to cart.\n";
    }

    void showCart() {
        if (items.empty()) {
            cout << "Your cart is empty.\n";
            return;
        }
        double total = 0;
        cout << "Items in your cart:\n";
        for (auto &item : items) {
            cout << "- " << item.name << " : $" << item.price << "\n";
            total += item.price;
        }
        cout << "Total: $" << total << "\n";
    }
};

int main() {
    vector<Product> products = {
        Product("Laptop", 999.99),
        Product("Smartphone", 499.99),
        Product("Headphones", 79.99),
        Product("Smartwatch", 199.99)
    };

    Cart cart;
    int choice;
    do {
        cout << "\nE-Commerce Store\n";
        cout << "1. View Products\n2. Add to Cart\n3. View Cart\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Available Products:\n";
                for (size_t i = 0; i < products.size(); i++) {
                    cout << i + 1 << ". " << products[i].name << " - $" << products[i].price << "\n";
                }
                break;
            case 2:
                int productChoice;
                cout << "Enter product number to add to cart: ";
                cin >> productChoice;
                if (productChoice > 0 && productChoice <= products.size()) {
                    cart.addProduct(products[productChoice - 1]);
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            case 3:
                cart.showCart();
                break;
            case 4:
                cout << "Thank you for shopping with us!\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
        }
    } while (choice != 4);
    return 0;
}
