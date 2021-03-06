#ifndef ROUTES_HPP
#define ROUTES_HPP

#include <string>
#include <vector>
#include <iostream>
#include "../../libft-cpp/include/libft.hpp"
#include "../../libft-cpp/include/get_next_line.hpp"
#include <fcntl.h>
#include <unistd.h>

class Routes {

	public:
		Routes();
		Routes(const Routes &other);
		Routes &operator=(const Routes &other);
		~Routes();

		void setDirFile(std::string value);
		void setListen(bool value);
		void setDefault(std::string value);
		void setLocation(std::string value);
		void setCGIPath(std::string value);
		void setLimitClientBody(std::string value);
		void setMethod(std::string value);

		std::string getDirFile() const;
		bool getListen() const;
		std::string getDefault() const;
		std::string getLocation() const;
		std::string getCGIPath() const;
		std::string getLimitClientBody() const;
		std::string getMethod() const;

	private:
		std::string		_dir_file;
		bool			_listen;
		std::string		_default;
		std::string		_location;
		std::string		_cgi_path;
		std::string		_limit_client_body;
		std::string		_method;
};

#endif // !ROUTES_HPP