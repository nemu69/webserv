#include "../../includes/class/Request.hpp"

Request::Request()
{

}

Request::Request(const Request &other)
{
	_acceptCharsets = other.getAcceptCharsets();
	_acceptLanguage = other.getAcceptLanguage();
	_authorization = other.getAuthorization();
	_date = other.getDate();
	_host = other.getHost();
}

Request::~Request()
{

}

Request &Request::operator=(const Request &other)
{
    if (this == &other) return(*this);
    this->~Request();
    return *new(this) Request(other);
}

void Request::setFirstLine(std::string value)
{
	this->_firstLine = value;
}

void Request::setAcceptCharsets(std::string value)
{
	this->_acceptCharsets = value;
}

void Request::setAcceptLanguage(std::string value)
{
	this->_acceptLanguage = value;
}

void Request::setAuthorization(std::string value)
{
	this->_authorization = value;
}

void Request::setDate(std::string value)
{
	this->_date = value;
}

void Request::setHost(std::string value)
{
	this->_host = value;
}

void Request::setUserAgent(std::string value)
{
	this->_userAgent = value;
}

void Request::setTransferEncoding(std::string value)
{
	this->_transferEncoding = value;
}

void Request::setReferer(std::string value)
{
	this->_transferEncoding = value;
}

void Request::setTime(int value)
{
	this->_time = value;
}

std::string Request::getFirstLine() const
{
	return(this->_firstLine);
}

std::string Request::getAcceptCharsets() const
{
	return(this->_acceptCharsets);
}

std::string Request::getAcceptLanguage() const
{
	return(this->_acceptLanguage);
}

std::string Request::getAuthorization() const
{
	return(this->_authorization);
}

std::string Request::getDate() const
{
	return(this->_date);
}

std::string Request::getHost() const
{
	return(this->_host);
}

std::string Request::getUserAgent() const
{
	return(this->_userAgent);
}

std::string Request::getTransferEncoding() const
{
	return(this->_transferEncoding);
}

int			Request::getTime() const
{
	return(this->_time);
}

void Request::set_line_config(char *line)
{
	char	*temp;
	
	if (getFirstLine().empty())
		setFirstLine(line);
	else {
		temp = (char *)"Accept-Charset:";
		if (!ft_strncmp(line, temp, ft_strlen(temp)))
			setAcceptCharsets(line);
		temp = (char *)"Accept-Language:";
		if (!ft_strncmp(line, temp, ft_strlen(temp)))
			setAcceptLanguage(line);
		temp = (char *)"Authorization:";
		if (!ft_strncmp(line, temp, ft_strlen(temp)))
			setAuthorization(line);
		temp = (char *)"Date:";
		if (!ft_strncmp(line, temp, ft_strlen(temp)))
			setDate(line);
		temp = (char *)"Host:";
		if (!ft_strncmp(line, temp, ft_strlen(temp)))
			setHost(line);
		temp = (char *)"User-Agent:";
		if (!ft_strncmp(line, temp, ft_strlen(temp)))
			setUserAgent(line);
		temp = (char *)"Transfer-Encoding:";
		if (!ft_strncmp(line, temp, ft_strlen(temp)))
			setTransferEncoding(line);
		temp = (char *)"Referer:";
		if (!ft_strncmp(line, temp, ft_strlen(temp)))
			setReferer(line);
	}
	free(line);
}

void Request::config_request(int fd)
{
	char *line;

	while (get_next_line(fd, &line) > 0)
		set_line_config(line);
	if (line) set_line_config(line);
	else throw Request::GNLMallocException();
}

const char* Request::GNLMallocException::what() const throw ()
{
	return ("\033[1;31m   Error: \033[0;3ii1m GNL malloc failed\033[0m");
}