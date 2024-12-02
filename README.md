
# ClientKeyLogger

ClientKeyLogger is a keylogging application written in C++ that captures keyboard input from a client machine. It uses the Boost library for some functionality, such as multi-threading and file handling.

## Features

- Captures keyboard input from the client.
- Logs keystrokes to a text file.
- Uses the Boost C++ Libraries.

## Prerequisites

- A C++ compiler (e.g., Visual Studio, GCC).
- Boost C++ Libraries (version 1.70 or higher).

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/drenchew/ClientKeyLogger.git
   ```

2. Install Boost:
   - On Linux:
     ```bash
     sudo apt-get install libboost-all-dev
     ```
   - On Windows:
     Download Boost from [Boost Downloads](https://www.boost.org/users/download/), then follow the [Windows build instructions](https://www.boost.org/doc/libs/1_70_0/more/getting_started/windows.html).

3. Open the project in your IDE or terminal:
   - For Visual Studio, open `clientcpp.sln`.
   - For GCC, use the following commands:
     ```bash
     g++ -o ClientKeyLogger main.cpp -lboost_system -lboost_filesystem -pthread
     ```

## Usage

1. Build the project.
2. Run the executable.
3. Keystrokes will be logged into `log.txt`.

## Disclaimer

This project is intended for educational purposes only. Using keylogging software without explicit permission is illegal.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Boost C++ Libraries.
- Various keylogging tutorials.
