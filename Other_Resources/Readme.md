# ✈️ Airline Management System

A command-line based **Airline Management System** built in C++ as a semester project. This system demonstrates Object-Oriented Programming (OOP) principles including inheritance, polymorphism, and encapsulation. It provides separate interfaces for administrators and customers to manage flights and bookings efficiently.

---

## 📸 Screenshots

### Main Menu
![Main Menu](Other_Resources/Screenshots/menu.png)

### Admin Dashboard
![Admin Dashboard](Other_Resources/Screenshots/Admin.png)

### Customer Dashboard
![Customer Dashboard](Other_Resources/Screenshots/customer.png)

---

## 🔧 Technologies Used

- **Language**: C++
- **Paradigm**: Object-Oriented Programming (OOP)
- **Key Concepts**: Inheritance, Polymorphism, Abstraction, Encapsulation
- **Interface**: Console-based menu system with custom print functions
- **Storage**: File handling *(under development)*

---

## 🚀 Getting Started

### ✅ Prerequisites

- C++ Compiler (e.g., `g++`, MinGW, or Visual Studio)
- Command-line interface (Terminal, CMD, or PowerShell)

### 🛠️ Compilation

Clone the repository and compile the source files:

```bash
git clone https://github.com/Obaid03/AirlineManagementSystem.git
cd AirlineManagementSystem
g++ main.cpp User.cpp ConsoleManipulation.cpp Flight.cpp -o AirlineManagement.exe
```

### ▶️ Run the Program

```bash
./AirlineManagement.exe
```

---

## 📌 Features

### 🛫 Admin Panel

- ➕ **Add new flights** – Create and schedule new flights
- ❌ **Remove flights** – Delete existing flights from the system
- 📋 **View all flights** – Display complete flight information
- 👥 **View all customers** – List all registered users
- ✏️ **Edit admin info** – Update admin profile details

### 🧍 Customer Panel

- 🎫 **Book flights** – Search and book available flights
- 🚫 **Cancel bookings** – Remove existing reservations
- 📄 **View booking details** – Check personal flight information
- ✏️ **Edit profile** – Update personal information

### ✈️ Flight Management

Each flight contains:

- 🔢 Flight Number
- 🌍 Origin & Destination
- 📅 Date & Time
- 📏 Distance
- 💺 Available Seats
- 👤 Customer Booking List

---

## 🧱 System Architecture

### Class Structure

```
User (Abstract Base Class)
├── Admin
└── Customer

Flight (Independent Class)
```

### 📦 `User` (Abstract Base Class)

- **Attributes**: User ID, Name, Email, Password
- **Methods**:
  - Credential verification
  - Pure virtual function: `userPanel()`
- **Derived Classes**: `Admin` and `Customer`

### 🔐 `Admin` (Derived from User)

- Manages the entire system
- CRUD operations on flights and customers
- Full access to system data

### 👤 `Customer` (Derived from User)

- Books and cancels flight reservations
- Manages personal profile and booking history

### 🛩️ `Flight`

- Stores flight metadata (number, route, schedule, capacity)
- Tracks customer bookings
- Implements overloaded `<<` operator for formatted console output

---

## 📂 Project Structure

```
AirlineManagementSystem/
├── main.cpp                    # Entry point
├── User.cpp / User.h           # User base class
├── Admin.cpp / Admin.h         # Admin class
├── Customer.cpp / Customer.h   # Customer class
├── Flight.cpp / Flight.h       # Flight class
├── ConsoleManipulation.cpp     # Console UI utilities
├── Other_Resources/
│   └── Screenshots/
│       ├── menu.png
│       ├── admin.png
│       └── customer.png
└── README.md
```

---

## 🎯 Future Enhancements

- 💾 Complete file handling implementation for persistent storage
- 🔍 Search and filter functionality for flights
- 💳 Payment integration simulation
- 📊 Analytics dashboard for admins
- 🎨 GUI implementation (Qt or similar framework)

---

## 👨‍💻 Contributors

| Name | GitHub Profile |
|------|----------------|
| **Hasnain** | [@Hasnain848](https://github.com/Hasnain848) |
| **Ibrahim** | [@maybethemuhammadibrahim](https://github.com/maybethemuhammadibrahim) |
| **Obaid** | [@Obaid03](https://github.com/Obaid03) |

---

## 📝 License

This project is licensed under the MIT License - feel free to use and modify for educational purposes.

---

## 🙏 Acknowledgments

- Developed as a semester project to demonstrate OOP concepts in C++
- Thanks to all contributors for their collaboration and effort

---

## 📧 Contact

For questions or suggestions, feel free to reach out via GitHub issues or contact any of the contributors directly.

---

**⭐ If you find this project helpful, please consider giving it a star!**
