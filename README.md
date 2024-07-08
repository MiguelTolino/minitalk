# 🗣️ minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.

## 📑 Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)

## 🧮 Introduction

The project aims to demonstrate the use of UNIX signals for inter-process communication (IPC). The project consists of two programs: a server and a client. The client sends a string message to the server, and the server receives and displays the message.

The main challenge of the project is to implement a communication protocol using signals, where the client transmits the message bit by bit, and the server reconstructs the message from the individual bits received.

## 🧰 Requirements

To run the project, you need the following:

- A UNIX-based operating system (Linux or macOS).
- *GCC* (GNU Compiler Collection) or any compatible C compiler.

## 🌄 Installation

1. Clone the repository to your local machine:

```bash
git clone https://github.com/MikelTolino/minitalk.git
cd minitalk
```

2. Compile the server and client programs:

```bash
make all
```

## ⏯️ Usage

1. Start the server by running the following command:

```bash
./server
```

The server will display its process ID (PID), indicating that it is ready to receive messages.

2. In a separate terminal window, run the client program with the server's PID and the message you want to send:

```bash
./client [PID] [message]
```

Replace `[PID]` with the PID displayed by the server, and `[message]` with the string you want to send. For example:

```bash
./client 12345 "Hello, Minitalk!"
```

The client will transmit the message to the server, and the server will display the received message.

## 🆕 Features

- Client-server communication using UNIX signals.
- Reliable transmission of messages bit by bit.
- Support for sending messages with various characters, including special characters and spaces.

## 🩹 Contributing

Contributions to the project are welcome and encouraged! If you have any suggestions, improvements, or bug fixes, please create a pull request with your changes.

1. Fork the repository.
2. Create a new branch for your feature or bug fix: `git checkout -b my-feature`.
3. Make your changes and commit them: `git commit -m "Add new feature"`.
4. Push the branch to your forked repository: `git push origin my-feature`.
5. Open a pull request on the original repository and describe your changes.

Please ensure your code follows the project's coding standards and practices.

## ☑️ Todo's
- [X] Reduce global variables
- [ ] It has been approved by Norminette
- [x] Makefile does relink
- [X] Minimize the number of signals and the time in process
- [X] Use signaction to display the caller process
