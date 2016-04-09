 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netdb.h> 
 
 void error(char *msg)
 {
     perror(msg);
     exit(0);
 }
 
 int main(int argc, char *argv[])
 {
     int sockfd, portno, n;
 
     struct sockaddr_in serv_addr;
     struct hostent *server;
 
     char buffer[256];
     if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
     }
     portno = atoi(argv[2]);
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
         error("ERROR opening socket");
     server = gethostbyname(argv[1]);
     if (server == NULL) {
         fprintf(stderr,"ERROR, no such host\n");
         exit(0);
     }
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
     serv_addr.sin_port = htons(portno);
     if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
         error("ERROR connecting");
     //printf("Please enter the message: ");
     //bzero(buffer,256);
     //fgets(buffer,255,stdin);
     //n = write(sockfd,buffer,strlen(buffer));
  //   if (n < 0) 
//          error("ERROR writing to socket");
     pid_t child_pid;
     child_pid = fork ();
     int init = 0;
     if (child_pid == 0){
            execvp("display", "1.jpg");
        }
        else
        {
            int i =0;
            scanf("HOLA %d", &i);
         do{

            bzero(buffer,256);
            n = read(sockfd,buffer,255);
    	     //printf("%s",buffer);
             switch(buffer[0]){
                case '0':
                        system("display -remote 0.jpg");    
                        printf("se envio comando 0\n");
                    break;
                case '1': 
                        system("display -remote 1.jpg");    
                        printf("se envio comando 1\n");
                    break;
                case '2':
                        system("display -remote 2.jpg");    
                        printf("se envio comando 2\n");
                    break;
                case '3':
                        system("display -remote 3.jpg");    
                        printf("se envio comando 3\n");
                    break;
                case '4':
                        system("display -remote 4.jpg");    
                        printf("se envio comando 4\n");
                    break;
                case '5':
                        system("display -remote 5.jpg");    
                        printf("se envio comando 5\n");
                    break;
                case '6':
                        system("display -remote 6.jpg");    
                        printf("se envio comando 6\n");
                    break;
                case '7':
                        system("display -remote 7.jpg");    
                        printf("se envio comando 7\n");
                    break;
                case '8':
                        system("display -remote 8.jpg");
                        printf("se envio comando 8\n");
                    break;
                case '9':
                        system("display -remote 9.jpg");    
                        printf("se envio comando 9\n");
                    break;
                default:
                    system("echo default");
                    break;
             }
         }while (1==1);
        }
     //return 0;
 }