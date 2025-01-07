# Inventory Management System

## Overview
This project is the final assignment for the "Programming Methodology" course, part of the Software Engineering degree. It demonstrates a practical application of programming principles learned during the semester using C++.

The system is designed to manage the inventory of a physical movie store. It provides functionality for adding, modifying, and viewing products, along with other inventory management features.

---

## Features
The program offers seven main functions:

1. **Add Product**: Add a new product to the inventory.
2. **Modify Product**: Update details of an existing product.
3. **Show Catalog**: Display all products in the inventory.
4. **Filter by Quantity**: List products with stock below a specified number.
5. **Filter by Supplier**: Show products from a specific supplier.
6. **Filter by Price**: Display products costing more than a given price.
7. **Main Menu**: Navigate between the program’s options.

---

## How It Works
The program operates through a console interface. Users interact with the main menu to access the different features. Below is a brief explanation of the core functionalities:

### Add Product
- Input product details: supplier, name, quantity, price, and rating.
- Validate the input before saving.
- Automatically generates a product key based on the supplier and product count.

### Modify Product
- Search for a product by its key.
- Update all details except the supplier and key.
- Returns an error message if the key is not found.

### Show Catalog
- Lists all products in the inventory.
- Displays an error if no products are available.

### Filter by Quantity
- Displays products with stock below a user-specified threshold.
- Shows a message if no matching products are found.

### Filter by Supplier
- Lists products from a specified supplier.
- Notifies the user if no products match the input.

### Filter by Price
- Displays products costing more than a specified price.
- Returns a message if no matching products exist.

### Main Menu
- Central navigation for the program.
- Allows users to select functions or exit the program.

---

## Requirements
- **Programming Language**: C++
- **Execution Environment**: Console application (no graphical interface).

---

## How to Run
1. Compile the C++ code using your preferred compiler.
2. Run the executable in a console environment.
3. Use the menu to navigate through the program options.

---

## Project Structure
The program is divided into logical modules corresponding to its main functionalities. Each function operates on a shared array that represents the inventory.

### Inputs and Outputs
- **Inputs**: User-provided data (e.g., product details, filters).
- **Outputs**: Console messages showing results or error messages.

---

## Example Scenarios
### Successful Product Addition
- User enters valid product details.
- Program generates a key and adds the product to the inventory.

### Failed Product Search
- User searches for a product with a non-existent key.
- Program displays an error message and returns to the menu.

---

## Limitations and Future Enhancements
- Current implementation is limited to a console interface.
- Future versions could include:
  - Graphical user interface (GUI).
  - Persistent storage for inventory data.
  - Advanced search and filtering options.

---

## Author
**Pedro Enrique Sánchez Rodríguez**

---

## Acknowledgments
- Supervised by **Dr. Ángel Juan Sánchez García**.
- Developed as part of the "Programming Methodology" course, December 2024.
- Universidad Veracruzana
