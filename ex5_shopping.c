#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products
#define MAX_PRODUCTS 10

// Structure to represent a product
struct Product 
{
    char name[50];
    float price;
};

// Function to display the list of products
void displayProducts(struct Product products[], int size) {
    printf("\nList of Products:\n");
    printf("%-20s%-10s\n", "Product Name", "Price");
    printf("----------------------------\n");
    
    for (int i = 0; i < size; ++i) {
        printf("%-20s$%-10.2f\n", products[i].name, products[i].price);
    }
}

int main()
{
    // Declare an array of products
    struct Product productList[MAX_PRODUCTS];
    
    // Populate the list of products
    strcpy(productList[0].name, "Laptop");
    productList[0].price = 899.99;
    
    strcpy(productList[1].name, "Smartphone");
    productList[1].price = 499.99;
    
    strcpy(productList[2].name, "Headphones");
    productList[2].price = 79.99;

    // Add more products as needed...

    // Display the list of products
    displayProducts(productList, 3);  // Assuming 3 products for demonstration

    return 0;
}// end main
