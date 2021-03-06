#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <iostream>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <list>
#include "../../libft-cpp/include/libft.hpp"
#include "../../libft-cpp/include/get_next_line.hpp"

class Request {
    public:
		Request();
		Request(const Request &other);
		Request &operator=(const Request &other);
		~Request();

		void setFirstLine(std::string value);
		void setAcceptCharsets(std::string value);
		void setAcceptLanguage(std::string value);
		void setAuthorization(std::string value);
		void setDate(std::string value);
		void setHost(std::string value);
		void setUserAgent(std::string value);
		void setTransferEncoding(std::string value);
		void setReferer(std::string value);
		void setTime(int value);

		std::string getFirstLine() const;
		std::string getAcceptCharsets() const;
		std::string getAcceptLanguage() const;
		std::string getAuthorization() const;
		std::string getDate() const;
		std::string getHost() const;
		std::string getUserAgent() const;
		std::string getTransferEncoding() const;
		std::string getReferer() const;
		int			getTime() const;

		void set_line_config(std::string line);
		void config_request(std::string file);

		class GNLMallocException : public std::exception
		{
			public:
				virtual const char* what () const throw();
		};

		std::list<std::string> _header;
	private:
		std::string _firstLine;
		std::string _acceptCharsets;
		std::string _acceptLanguage;
		std::string _authorization;
		std::string _date;
		std::string _host;
		std::string _userAgent;
		std::string _transferEncoding;
		std::string _referer;
		int			_time;
};

#endif // !REQUEST_HPP