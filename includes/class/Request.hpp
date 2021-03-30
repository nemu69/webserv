#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <iostream>
#include <unistd.h>
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
		void setAllow(std::string value);
		void setAuthorization(std::string value);
		void setContentLanguage(std::string value);
		void setContentLength(std::string value);
		void setContentLocation(std::string value);
		void setContentType(std::string value);
		void setDate(std::string value);
		void setHost(std::string value);
		void setReferer(std::string value);

		std::string getFirstLine() const;
		std::string getAcceptCharsets() const;
		std::string getAcceptLanguage() const;
		std::string getAllow() const;
		std::string getAuthorization() const;
		std::string getContentLanguage() const;
		std::string getContentLength() const;
		std::string getContentLocation() const;
		std::string getContentType() const;
		std::string getDate() const;
		std::string getHost() const;
		std::string getReferer() const;

		void config_request(int fd);
		void set_line_config(char *line);

		class GNLMallocException : public std::exception
		{
			public:
				virtual const char* what () const throw();
		};

	private:
		std::string _firstLine;
		std::string _acceptCharsets;
		std::string _acceptLanguage;
		std::string _allow;
		std::string _authorization;
		std::string _contentLanguage;
		std::string _contentLength;
		std::string _contentLocation;
		std::string _contentType;
		std::string _date;
		std::string _host;
		std::string _referer;
};

#endif // !REQUEST_HPP