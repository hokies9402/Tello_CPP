#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstring>

 int Tello_Test()
 {

	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	sockaddr_in addr;
	memset( (char *)&addr, 0, sizeof(addr) );
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl( INADDR_ANY );
	addr.sin_port = htons(0);//find port of tello drone
	socklen_t addrlen = sizeof(addr);

	if ( socket_fd >= 0 )
	{
		
		int bound = bind(socket_fd, (struct sockaddr *)&addr, addrlen );
		if ( bound >= 0 )
		{

		}
		else
		{
			perror("bind failed.");
			return 0;
		}

	}
	else
	{
		perror("socket failed to create");
		return 0;
	}

	return 0;

 }
