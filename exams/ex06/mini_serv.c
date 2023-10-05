#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct s_data {
	int		fd;
	int		id;
	struct s_data	*next;
}	t_data;

int	g_sockfd = 0;

void	ft_strerr(char *error) {
	size_t	len;

	len = strlen(error);
	write(2, error, len);
}

void	ft_free_nodes(t_data **nodes) {
	t_data	*tmp = *nodes;

	if (!nodes || !(*nodes))
		return ;
	while (tmp) {
		*nodes = (*nodes)->next;
		if (tmp->fd)
			close(tmp->fd);
		free(tmp);
		tmp = *nodes;
	}
	*nodes = NULL;
}

void	ft_check_status(int code, t_data **nodes) {
	if (code >= 0)
		return ;
	ft_strerr("Fatal error\n");
	if (nodes)
		ft_free_nodes(nodes);
	if (g_sockfd)
		close(g_sockfd);
	exit(1);
}

void	*ft_malloc(size_t size, t_data **nodes) {
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_free_nodes(nodes);
	return (ptr);
}

void	*ft_create_node(int fd, int id, t_data **nodes) {
	t_data	*node;

	node = ft_malloc(sizeof(t_data), nodes);
	node->fd = fd;
	node->id = id;
	node->next = NULL;
	return (node);

}

void	ft_push_back(t_data **nodes, t_data *new) {
	t_data	*tmp = *nodes;

	if (!nodes || !new)
		return ;
	if (!(*nodes))
		*nodes = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	ft_get_id(t_data **nodes, int fd) {
	t_data	*tmp = *nodes;

	while (tmp) {
		if (tmp->fd == fd)
			return (tmp->id);
		tmp = tmp->next;
	}
	return (-1);
}

void	ft_send_to_all(t_data **nodes, char *msg, int fd) {
	t_data	*tmp = *nodes;
	size_t	len;
	int	ret;

	len = strlen(msg);
	while (tmp) {
		if (tmp->fd != fd) {
			ret = send(tmp->fd, msg, len, 0);
			ft_check_status(ret, nodes);
		}
		tmp = tmp->next;
	}
}

void	ft_resend_msg(t_data **nodes, char *buf, int fd) {
	char	msg[5000 * 42], str[4096 * 42];
	int	id, i = 0, j = 0;

	id = ft_get_id(nodes, fd);
	bzero(&str, sizeof(str));
	while (buf[i]) {
		str[j] = buf[i];
		++j;
		if (buf[i] == '\n') {
			bzero(&msg, sizeof(msg));
			sprintf(msg, "client %d: %s", id, str);
			ft_send_to_all(nodes, msg, fd);
			j = 0;
			bzero(&str, sizeof(str));
		}
		++i;
	}
}

void	ft_remove_fd(t_data **nodes, int fd) {
	t_data *tmp = *nodes;
	t_data *toRemove;

	if (tmp && tmp->fd == fd) {
		*nodes = (*nodes)->next;
		free(tmp);
		return ;
	}
	while (tmp) {
		if (tmp->next && tmp->next->fd == fd) {
			toRemove = tmp->next;
			tmp->next = tmp->next->next;
			free(toRemove);
			return ;
		}
		tmp = tmp->next;
	}
}

void	launcher(int port) {
	fd_set	master_set, working_set;
	t_data	*nodes = NULL, *new_node = NULL;
	int	new_fd, max_fd, ret, client_id = 0, id;
	size_t	size, len_buf;
	char	msg[4096 * 42], buf[4096 * 42];
	socklen_t	len;
	struct sockaddr_in	address;

	len = sizeof(address);
	len_buf = sizeof(buf);
	bzero(&address, len);
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(2130706433);

	g_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	ft_check_status(g_sockfd, NULL);
	ret = bind(g_sockfd, (struct sockaddr*)&address, len);
	ft_check_status(ret, NULL);
	ret = listen(g_sockfd, 32);
	ft_check_status(ret, NULL);

	FD_ZERO(&master_set);
	FD_SET(g_sockfd, &master_set);
	max_fd = g_sockfd;
	while (19) {
		working_set = master_set;
		ret = select(max_fd + 1, &working_set, NULL, NULL, 0);
		ft_check_status(ret, &nodes);
		for (int i = 0; max_fd >= i; ++i) {
			if (FD_ISSET(i, &working_set)) {
				if (i == g_sockfd) {
					new_fd = accept(g_sockfd, (struct sockaddr*)&address, &len);
					ft_check_status(new_fd, &nodes);
					new_node = ft_create_node(new_fd, client_id, &nodes);
					ft_push_back(&nodes, new_node);
					bzero(&msg, sizeof(msg));
					sprintf(msg, "server: client %d just arrived\n", client_id);
					client_id++;
					ft_send_to_all(&nodes, msg, new_fd);
					FD_SET(new_fd, &master_set);
					if (new_fd > max_fd)
						max_fd = new_fd;
				} // accept
				else {
					size = 0;
					bzero(&buf, len_buf);
					do {
						ret = recv(i, &buf[size], 1000, 0);
						size += ret;
						if (ret <= 0)
							break ;
					} while (buf[size - 1] != '\n' && size < len_buf);
					if (ret <= 0) {
						id = ft_get_id(&nodes, i);
						bzero(&msg, sizeof(msg));
						sprintf(msg, "server: client %d just left\n", id);
						ft_send_to_all(&nodes, msg, i);
						ft_remove_fd(&nodes, i);
						FD_CLR(i, &master_set);
						close(i);
						break ;
					}
					else
						ft_resend_msg(&nodes, buf, i);
				} // respond
			} // FD_ISSET
		} // for loop
	} // main loop
	ft_free_nodes(&nodes);
}

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		ft_strerr("Wrong number of arguments\n");
		exit (1);
	}
	launcher(atoi(argv[1]));
	return (0);
}
