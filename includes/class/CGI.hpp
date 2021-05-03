#ifndef CGI_HPP
#define CGI_HPP

#include <iostream>
#include "../../libft-cpp/include/libft.hpp"
#include "../../libft-cpp/include/get_next_line.hpp"
#include <fcntl.h>
#include <unistd.h>

#include <list>
#include "class/Routes.hpp"
#include "class/Server.hpp"
#include "class/Client.hpp"

class CGI {
    public:
		CGI();
		CGI(const CGI &other);
		~CGI();
		CGI &operator=(const CGI &other);

		void			setEnv(char **value);
		char 			**getEnv() const;
		void			setRoutes(Routes value);
		Routes 			getRoutes() const;
		void			setServer(Server value);
		Server 			getServer() const;
		void			setMethod(std::string value);
		std::string 	getMethod() const;
		void			setFile(std::string value);
		std::string 	getFile() const;
		void			setContent(std::string value);
		std::string 	getContent() const;
		void			setClient(Client* value);
		Client* 		getClient() const;

		std::string		getType();

		int			set_all_variable(std::list<std::string> metavar);
		int			free_cgi(char **tab, int err);
		int			config_cgi(Routes route, Server serv, std::string method, std::string file, std::string content, Client *client);

	private:
		char **_env;
		Routes _route;
		Server _serv;
		std::string _method, _file, _content;
		Client* _client;
};

#endif // !CGI_HPP