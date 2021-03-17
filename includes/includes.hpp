#ifndef INCLUDES_HPP
#define INCLUDES_HPP

class Server;

/***
 *** server_data.cpp
***/
int		config_data_serv(Server serv, int server_fd, int new_socket, int fd_opt);
void	one_client(Server serv, char **env, int new_socket, int server_fd);

/***
 *** server_fnct.cpp
***/
void	exit_err(std::string err, char *freevar, int new_socket, int server_fd);
int		accept_one_client(int server_fd, sockaddr_in *address);
void	waiting_client(Server serv, char **env, int server_fd, sockaddr_in *address);
void	launch_serv(Server serv, char **env);

/***
 *** server_parse_conf.cpp
***/
int		parse_conf(const char *path, std::vector<Server> *all);

/***
 *** main.cpp
***/
void	waiting_screen();
#endif