//
//  IRproxy.cpp
//  Meo Remote
//
//  Created by Diogo Gomes on 23/01/12.
//  Copyright (c) 2012 Universidade de Aveiro. All rights reserved.
//

#include <iostream>
#import <CoreFoundation/CFSocket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "IRproxy.h"

void pressIRButton(int button) {

    char hello[7];
    bzero(hello, 7);
    char buffer[12];
    sprintf(buffer, "key=%d\n", button);
    struct sockaddr_in sin; 
    struct hostent *host; 
    int s; 
    
    host = gethostbyname("192.168.1.66");  
    
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



