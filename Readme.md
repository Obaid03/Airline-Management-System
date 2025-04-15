# ✈️ Airline Management System

A basic OOP implementation semester project in C++. This command-line-based system allows administrators to manage flights and customers, while users (admins and customers) can interact through a custom-built menu system.

---

## 🔧 Technologies Used

- **Language**: C++
- **Concepts**: Object-Oriented Programming (OOP), Inheritance, Polymorphism
- **Interface**: Console-based menu system (custom print functions)
- **Storage**: File handling *(under development)*

---

## 🚀 How to Run

### ✅ Prerequisites
- C++ Compiler (e.g., MinGW with `g++`)
- Command-line interface (CMD or Terminal)

### 🛠️ Compile
```bash
g++ main.cpp User.cpp ConsoleManipulation.cpp Flight.cpp -o AirlineManagement.exe

---

## 📌 Features

### 🛫 Admin Panel
- Add new flights
- Remove existing flights
- View all available flights
- View all registered customers
- Edit admin information

### 🧍‍♂️ Customer Panel
- Book new flights
- Cancel booked flights
- View personal and booking information
- Edit profile details

### ✈️ Flight Management
- View complete flight details:
  - Flight Number
  - Origin and Destination
  - Date and Time
  - Distance and Available Seats
- Track customers booked on each flight

---

## 🧱 Class Architecture

### `User` (Abstract Base Class)
- Contains common user data: ID, Name, Email, Password
- Credential verification function
- Pure virtual function: `userPanel()`
- Derived by: `Admin` and `Customer`

### `Admin` (Derived from User)
- Controls the system (CRUD operations on flights/customers)
- Can list all flights and all registered users

### `Customer` (Derived from User)
- Books and manages flight reservations
- Holds personal booking data

### `Flight`
- Stores flight metadata (number, cities, time, date, seats, distance)
- Manages customer bookings
- Overloaded `<<` operator for formatted output

---
