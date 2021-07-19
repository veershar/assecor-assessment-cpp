# C++ Developer Test (EN)

## Goal

We need to create a library that lets us manage the customers in our store. This library must have two classes:

1. A customer repository that can:
    1. Add customers
    2. Retrieve all customers
    3. Retrieve a single customer by their Id
2. A customer formatter that can:
    1. Retrieve nicely-formatted display text for a single customer by their Id

When formatting customer data for display, please use the following format:
- If the customer is found:
    - `<last name>, <first name>, <zip code> <city>, <favorite color>`
    - Example: `Müller, Hans, 67742 Lauterecken, blue`
- If no customer is found:
    - `(no customer)`

## Acceptance Criteria

- The library must use the customer data structure in the file [customer.h](customer.h). This is a C header that the company uses in many other projects and it may not be modified.
- Customers should be stored in-memory. (No database is necessary.)
- There are plans to extend the library so it can store customers elsewhere, such as in a file, database, or a cloud storage service. Please design your architecture so we can add this in the future without rewrites.
- The customer formatter should retrieve customers itself using any kind of customer repository.
- Write the necessary integration and unit tests to ensure that this library behaves as expected and can be safely extended or refactored.
    - Unit tests should use mocked dependencies.

## Bonus Points

Make a small MFC application to display customers.
- This application doesn't need to allow users to create customers - only retrieve them and show them to the user.
- For simplicity, the users can be hard-coded into the project.
- The goal is to demonstrate a basic knowledge of MFC. The UX may be as quick and dirty as possible :)
