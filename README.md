# 🏦 Devbhoomi Bank System

<div align="center">

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-informational?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)

**A fully functional console-based banking system built in C++**  
Create accounts · Deposit & Withdraw · Transfer Funds · Persist Data

</div>

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Project Structure](#-project-structure)
- [Class Architecture](#-class-architecture)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Running the Application](#running-the-application)
- [Usage Guide](#-usage-guide)
  - [Main Menu](#main-menu)
  - [Create Account](#1-create-account)
  - [Deposit Money](#2-deposit-money)
  - [Withdraw Money](#3-withdraw-money)
  - [Check Balance](#4-check-balance)
  - [Display Account Details](#5-display-account-details)
  - [Transfer Money](#6-transfer-money)
  - [Show All Accounts](#7-show-all-accounts)
  - [Save Data](#8-save-data)
- [Data Persistence](#-data-persistence)
- [Security](#-security)
- [Sample Output](#-sample-output)
- [Limitations & Future Improvements](#-limitations--future-improvements)
- [Contributing](#-contributing)
- [License](#-license)

---

## 🌐 Overview

**Devbhoomi Bank System** is a console-based banking application written in C++ that simulates core banking operations. It allows users to create and manage bank accounts, perform transactions (deposits, withdrawals, transfers), and persist account data to a local file.

This project demonstrates core Object-Oriented Programming (OOP) concepts in C++ including:

- **Encapsulation** – Private data with controlled public access
- **Abstraction** – Clean interface hiding implementation details
- **Modular Design** – Separation of account logic and system management

---

## ✨ Features

| Feature | Description |
|---|---|
| 🆕 **Create Account** | Register a new bank account with a unique account number, holder name, type, balance, and PIN |
| 💰 **Deposit Money** | Add funds to any existing account |
| 💸 **Withdraw Money** | Securely withdraw funds with PIN verification |
| 📊 **Check Balance** | View current balance after PIN authentication |
| 📄 **Account Details** | Display full account information after PIN authentication |
| 🔄 **Transfer Money** | Transfer funds between two accounts with sender PIN verification |
| 📋 **All Accounts** | View a summary of all registered accounts |
| 💾 **Save Data** | Persist all account data to `bank_data.txt` |

---

## 📁 Project Structure

```
devbhoomi-bank/
│
├── bankSystem.cpp            # Entry point + Menu function
├── bank_data.txt       # Auto-generated data file (after saving)
└── README.md           # Project documentation
```

> The entire project lives in a single `main.cpp` file, making it portable and easy to compile anywhere.

---

## 🏗️ Class Architecture

### `BankAccount` Class

Represents an individual bank account with its data and operations.

```
┌─────────────────────────────────────────────┐
│                 BankAccount                 │
├─────────────────────────────────────────────┤
│ PRIVATE                                     │
│  - accountNumber : int                      │
│  - holderName    : string                   │
│  - accountType   : string                   │
│  - balance       : double                   │
│  - pin           : string                   │
├─────────────────────────────────────────────┤
│ PUBLIC                                      │
│  + BankAccount()                            │
│  + BankAccount(int, string, string,         │
│                double, string)              │
│  + getAccountNumber() → int                 │
│  + getHolderName()    → string              │
│  + getBalance()       → double              │
│  + verifyPin(string)  → bool                │
│  + deposit(double)    → void                │
│  + withdraw(double)   → void                │
│  + displayAccount()   → void                │
│  + serialize()        → string              │
└─────────────────────────────────────────────┘
```

### `BankSystem` Class

Manages a collection of `BankAccount` objects and exposes all system-level operations.

```
┌─────────────────────────────────────────────┐
│                 BankSystem                  │
├─────────────────────────────────────────────┤
│ PRIVATE                                     │
│  - accounts : vector<BankAccount>           │
├─────────────────────────────────────────────┤
│ PUBLIC                                      │
│  + createAccount()         → void           │
│  + findAccount(int)        → BankAccount*   │
│  + depositMoney()          → void           │
│  + withdrawMoney()         → void           │
│  + checkBalance()          → void           │
│  + displayAccountDetails() → void           │
│  + transferMoney()         → void           │
│  + saveAccountsToFile()    → void           │
│  + showAllAccounts()       → void           │
└─────────────────────────────────────────────┘
```

### Relationship Diagram

```
┌──────────────┐         contains         ┌──────────────┐
│  BankSystem  │ ──────────────────────►  │ BankAccount  │
│              │   vector<BankAccount>    │              │
└──────────────┘                          └──────────────┘
       │
       │ uses
       ▼
  bank_data.txt  (file persistence via serialize())
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting **C++11 or later**:
  - `g++` (GCC) — Linux / macOS / Windows (MinGW)
  - `clang++` — macOS / Linux
  - `MSVC` — Visual Studio on Windows
- Terminal or Command Prompt

### Compilation

**Linux / macOS:**
```bash
g++ -o bank_system main.cpp -std=c++11
```

**Windows (MinGW):**
```bash
g++ -o bank_system.exe main.cpp -std=c++11
```

**Using clang++:**
```bash
clang++ -o bank_system main.cpp -std=c++11
```

### Running the Application

**Linux / macOS:**
```bash
./bank_system
```

**Windows:**
```bash
bank_system.exe
```

---

## 📖 Usage Guide

### Main Menu

```
== WELCOME TO DEVBHOOMI BANK ==
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Display Account Details
6. Transfer Money
7. Show All Accounts
8. Save Data
9. Exit
============================================
Enter Your Choice:
```

---

### 1. Create Account

Creates a new bank account. The account number must be **unique**.

**Inputs Required:**
| Field | Type | Description |
|---|---|---|
| Account Number | `int` | Unique numeric ID |
| Holder Name | `string` | Full name of the account holder |
| Account Type | `string` | `SAVING` or `CURRENT` |
| Initial Balance | `double` | Opening balance in Rs. |
| PIN | `string` | 4-digit security PIN |

```
Enter Account Number: 1001
Enter Holder name: Ravi Sharma
Enter Account Type (SAVING/CURRENT): SAVING
Enter initial Balance: Rs. 5000
Set 4-digits PIN: 1234

 ==< Account Created Successfully >==
```

---

### 2. Deposit Money

Deposits a positive amount into an existing account. **No PIN required.**

```
Enter Account Number: 1001
Enter Amount to Deposit: Rs. 2000
Amount Deposited Successfully!
```

---

### 3. Withdraw Money

Withdraws money from an account. **PIN verification required.**

```
Enter Account Number: 1001
Enter PIN: 1234
Enter Withdrawal Amount: Rs. 1000
Withdrawal Successful!
```

**Error Cases:**
- `Incorrect PIN!` — wrong PIN entered
- `Insufficient Balance!` — amount exceeds current balance
- `Invalid Withdrawal Amount!` — amount is zero or negative

---

### 4. Check Balance

Displays the current balance. **PIN verification required.**

```
Enter Account Number: 1001
Enter PIN: 1234

Current Balance: Rs. 6000.00
```

---

### 5. Display Account Details

Shows full account information. **PIN verification required.**

```
Enter Account Number: 1001
Enter PIN: 1234

==================================
Account Number : 1001
Holder Name    : Ravi Sharma
Account Type   : SAVING
Balance         : Rs. 6000.00
==================================
```

---

### 6. Transfer Money

Transfers funds from a sender to a receiver account. **Sender's PIN required.**

```
Enter Sender Account Number: 1001
Enter PIN: 1234
Enter Receiver Account Number: 1002
Enter Transfer Amount: Rs. 500
Withdrawal Successful!
Amount Deposited Successfully!
Money Transfer Successful!
```

**Error Cases:**
- `Sender Account Not Found!`
- `Receiver Account Not Found!`
- `Incorrect PIN!`
- `Insufficient Balance!`

---

### 7. Show All Accounts

Lists details of every registered account. No authentication required.

```
========== ALL ACCOUNTS ==========

==================================
Account Number : 1001
Holder Name    : Ravi Sharma
Account Type   : SAVING
Balance         : Rs. 5500.00
==================================

==================================
Account Number : 1002
Holder Name    : Priya Mehta
Account Type   : CURRENT
Balance         : Rs. 12000.00
==================================
```

---

### 8. Save Data

Saves all current account data to `bank_data.txt` in CSV format.

```
Data Saved Successfully!
```

---

## 💾 Data Persistence

Accounts are serialized and stored in `bank_data.txt` using comma-separated values:

```
accountNumber,holderName,accountType,balance,pin
```

**Example `bank_data.txt`:**
```
1001,Ravi Sharma,SAVING,5500.000000,1234
1002,Priya Mehta,CURRENT,12000.000000,5678
```

> ⚠️ **Note:** Data is only saved when you explicitly choose **Option 8 (Save Data)**. Data is not automatically loaded on startup in the current version.

---

## 🔐 Security

| Aspect | Current Behavior |
|---|---|
| PIN Storage | Stored as plain text (no hashing) |
| PIN Verification | Required for withdraw, balance check, account details, and transfer |
| Deposit | Does not require PIN (intentional design) |
| File Security | `bank_data.txt` stores PINs in plain text — keep secure |

> ⚠️ **Security Notice:** This is an educational project. PINs are stored and saved as plain text. For any production use, PIN hashing (e.g., SHA-256) and encrypted file storage should be implemented.

---

## 🖥️ Sample Output

```
== WELCOME TO DEVBHOOMI BANK ==
1. Create Account
...
Enter Your Choice: 1

Enter Account Number: 2024
Enter Holder name: Ankit Rawat
Enter Account Type (SAVING/CURRENT): SAVING
Enter initial Balance: Rs. 10000
Set 4-digits PIN: 9876

 ==< Account Created Successfully >==

== WELCOME TO DEVBHOOMI BANK ==
...
Enter Your Choice: 4

Enter Account Number: 2024
Enter PIN: 9876

Current Balance: Rs. 10000.00
```

---

## 🔧 Limitations & Future Improvements

### Current Limitations

- ❌ No automatic data loading on startup
- ❌ PINs stored as plain text
- ❌ No transaction history / logs
- ❌ No interest calculation
- ❌ No input validation for PIN length or account number format
- ❌ No admin/superuser role

### Suggested Improvements

- [ ] **Load accounts on startup** from `bank_data.txt`
- [ ] **PIN hashing** using SHA-256 or bcrypt
- [ ] **Transaction history** per account
- [ ] **Interest calculation** for savings accounts
- [ ] **Input validation** — enforce 4-digit PIN, positive balances
- [ ] **Admin panel** — delete accounts, view all with balances
- [ ] **GUI** using Qt or a web frontend
- [ ] **Database backend** (SQLite) instead of flat-file storage
- [ ] **Multiple file support** — one file per account

---

## 🤝 Contributing

Contributions are welcome! Here's how to get started:

1. **Fork** the repository
2. **Create** a feature branch
   ```bash
   git checkout -b feature/add-transaction-history
   ```
3. **Commit** your changes
   ```bash
   git commit -m "Add transaction history logging"
   ```
4. **Push** to your branch
   ```bash
   git push origin feature/add-transaction-history
   ```
5. Open a **Pull Request**

Please follow clean code practices and comment your additions.

---

## 📄 License

This project is licensed under the **MIT License**.

```
MIT License

Copyright (c) 2024 Devbhoomi Bank System

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
```

---

<div align="center">

Made with ❤️ | Devbhoomi Bank System

</div>
