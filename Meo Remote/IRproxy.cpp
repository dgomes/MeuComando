//
//  IRproxy.cpp
//  Meo Remote
//
//  Created by Diogo Gomes on 23/01/12.
//  Copyright (c) 2012 Diogo Gomes. All rights reserved.
//

#include <string.h>
#include <iostream>
#import <CoreFoundation/CFSocket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <ifaddrs.h>
#include <net/if.h>
#include "IRproxy.h"

static char stbIP[15] = "";

int connect_timeout(int , struct sockaddr *, socklen_t , struct timeval *);
int set_nonblock(int , int );
void getNetwork(char *);


int set_nonblock(int fd, int value)
{
	int oldflags = fcntl(fd, F_GETFL, 0);
	if(oldflags < 0) return oldflags;
	if(value) oldflags |= O_NONBLOCK;
	else oldflags &= ~O_NONBLOCK;
	return fcntl(fd, F_SETFL, oldflags);
}

int connect_timeout(int sock, struct sockaddr *address, socklen_t address_len, struct timeval *timeout)
{
	fd_set sel;
	int ret = 0;
    
	if(set_nonblock(sock, 1) < 0){
		perror("set_nonblock() error ");
		return -1;
	}
    
	if(connect(sock, address, address_len) < 0){
            if(errno == EINPROGRESS)
            {
                FD_ZERO(&sel);
                FD_SET((unsigned)sock, &sel);
                int mode = select(sock+1, NULL, &sel, NULL, timeout);
                if(mode < 0){
                    perror("select() error ");
                    ret = -1;
                    goto cleanup;
                }else if(mode > 0){
                    ret = 0;
                    goto cleanup;
                }else if(mode == 0){
                    ret = -2;
                    goto cleanup;
                }
            }else{
                perror("connect() error ");
                ret = -1;
            }
	}
	
cleanup:
	if(set_nonblock(sock, 0) < 0){
		perror("set_nonblock() error ");
		return -1;
	}
	
	return ret;
}

void getNetwork(char *res) {
        struct ifaddrs *myaddrs, *ifa;
        struct sockaddr_in *s4;
        int status;
        char buf[18];
        
        status = getifaddrs(&myaddrs);
        if (status != 0)
        {
            perror("getifaddrs");
            exit(1);
        }
        
        for (ifa = myaddrs; ifa != NULL; ifa = ifa->ifa_next)
        {
            if (ifa->ifa_addr == NULL) continue;
            if ((ifa->ifa_flags & IFF_UP) == 0) continue;
            if (strcmp(ifa->ifa_name, "lo0") == 0) continue;
            
            if (ifa->ifa_addr->sa_family == AF_INET)
            {
                struct sockaddr network;
                for(int i=0; i<ifa->ifa_addr->sa_len; i++)
                    network.sa_data[i] = ifa->ifa_addr->sa_data[i] & ifa->ifa_netmask->sa_data[i];
                
                s4 = (struct sockaddr_in *)(&network);
                if (inet_ntop(ifa->ifa_addr->sa_family, (void *)&(s4->sin_addr), buf, sizeof(buf)) == NULL)
                {
                    printf("%s: inet_ntop failed!\n", ifa->ifa_name);
                }
                else
                {
                    bzero(res, 15);
                    strncpy(res, buf, strlen(buf) - strlen(strrchr(buf, '.')));
                    return;
                }
            }
        }
        
    freeifaddrs(myaddrs);
    
}

void searchSTB() {
    int i,err,net;
    
    struct sockaddr_in sa;
    sa.sin_family=PF_INET;
    sa.sin_port=htons(8082);
    
    struct timeval timeout;      
    timeout.tv_sec = 0;
    timeout.tv_usec = 200000;
    
    char network[15];
    getNetwork(network);
    
    for(i=60;i<70;i++)
    {
        char hostname[15];
        sprintf(hostname, "%s.%d", network, i);
        fprintf(stderr,"Scanning %s ...\n", hostname);

        sa.sin_addr.s_addr=inet_addr(hostname);
        net=socket(AF_INET,SOCK_STREAM,0);

        err=connect_timeout(net,(struct sockaddr *)&sa,sizeof(sa), &timeout);
        if(err>=0)
        {
            strcpy(stbIP, hostname);
            close(net);
            return;
        }
        close(net);
    }
}

void pressIRButton(int button) {

    char hello[7];
    bzero(hello, 7);
    char buffer[12];
    sprintf(buffer, "key=%d\n", button);
    struct sockaddr_in sin; 
    struct hostent *host; 
    int s; 
    
    if(!strcmp(stbIP, "")) return;
    host = gethostbyname(stbIP);  
    
    memcpy(&(sin.sin_addr), host->h_addr,host->h_length); 
    sin.sin_family = host->h_addrtype; 
    sin.sin_port = htons(8082);
    // Create socket port 888
    s = socket(AF_INET, SOCK_STREAM,0);
    // 1. Block for server accept 
    connect(s,  (struct sockaddr*)&sin,sizeof(sin));     
    
    // receive "hello";
    recv(s,hello,6,0);
    fprintf(stderr,"%s\n", hello);
    // send "key=?"       
    send(s,buffer,strlen(buffer)+1,0);   
    // receive "ok" 
    recv(s,buffer,3,0);
    // Print received data
    fprintf(stderr, "buffer: %s\n", buffer);

}



