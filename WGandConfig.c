
#include "webs.h"
#include <stdio.h>
#include <stdlib.h>
#include "webHeader.h"
#include <netdb.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <arpa/inet.h>
#include "WGandConfig.h"
#define  MAXSIZE 4096
#define PORT        60000
#define SERVIP  "192.168.3.230"
#define GATE_CONFIG_FILE "./gate_config.txt"




void GoFormSearchGate(webs_t wp, char_t *path, char_t *query)
{
	
	static int num;
	int testi;
	int door_no;
	char *search_btn;
	char *save_btn;
	FILE *fp;
	char *id, *ip, *port, *name; 
	char buf[20];	
	
	
	unsigned char kahao[MAXSIZE];
	struct __gate_info *gate_info;
	int sockfd, addr_len;

	if(strlen(save_btn) != 0)
	{
		fp = fopen("gate_config.txt","w");
		if(fp == NULL)
		{
			printf("open gate config file error \n");
		}
		int i=0;		
		id = websGetVar(wp,T("gate_sin0"),"");	
		printf("hhhh%s\n",id);	
		while(id!=NULL){	
				
			 sprintf(buf,"gate_sin%d",i); 
			 
			 id = websGetVar(wp,T(buf),"");
			 if(strlen(id)==0)
			 	break;
			 sprintf(buf,"gate_ip%d",i);	
			 ip = websGetVar(wp,T(buf),"");
			 
			 sprintf(buf,"gate_port%d",i); 
			 port = websGetVar(wp,T(buf),"");
			 
			 sprintf(buf,"gate_name%d",i);
			 name = websGetVar(wp,T(buf),"");
			printf("%d %s %s %s %s  mmmmmm!!\n",i,id,ip,port,name);
		
		
			fprintf(fp,"%d %s %s %s %s           \n",i+1,id,ip,port,name);
			i++;	
		
		}	
		fclose(fp);	
		webReadConfigFiles();	
	}
	close(sockfd);
	printf("nnnnnnnnnnnnnnnnnnn\n");
	websRedirect(wp,T("wgateConfig.asp"));
	return;	
}



int AspGetGate(int eid, webs_t wp, int argc, char_t **argv)
{

	websWrite(wp,"<tr class=\"style1\">");
	websWrite(wp,"<td>ID</td>");
	websWrite(wp,"<td>ÐòÁÐºÅ</td>");
 	websWrite(wp,"<td>ÃÅ½ûIPµØÖ·</td>");
	websWrite(wp,"<td>ÃÅ½û¶Ë¿Ú</td>");
	websWrite(wp,"<td>ÃÅ½ûÃû×Ö</td>");
	websWrite(wp,"<td>É¾³ý</td>");
	websWrite(wp,"</tr>");



	int i=0;
	FILE *fp;
		

//	i = atoi(argv[0]);	
//	cmd_no = atoi(argv[1]);
	if( (fp=fopen(GATE_CONFIG_FILE, "r")) == NULL )
	{
	   printf("error : can not open file\n");
	   return -1;
	}
	printf("gate_id is %s\n",gate_config[0].serial_id);
	printf("gate_id2 is %s\n",gate_config[1].serial_id);	

	//fscanf(fp,"%d %s %s %s \n",&gate_num,gate_serial_id,gate_ip_addr,gate_port);

//	printf("%d %s %s %s \n",gate_num,gate_serial_id,gate_ip_addr,gate_port);
	
	while(gate_config[i].num!=NULL)
	{
		websWrite(wp,"<tr class=\"style2\">");
		websWrite(wp,"<td>%d</td>",gate_config[i].num);
		websWrite(wp,"<td><input id=\"sin%d\" type=\"text\" name=\"gate_sin%d\" value=%s /></td>",i,i,gate_config[i].serial_id);
		websWrite(wp,"<td><input id=\"ip%d\" type=\"text\" name=\"gate_ip%d\" value=%s /></td>",i,i,gate_config[i].ip_addr);
		websWrite(wp,"<td><input id=\"port%d\" type=\"text\" name=\"gate_port%d\" value=%s /></td>",i,i,gate_config[i].port);
		websWrite(wp,"<td><input id=\"name%d\" type=\"text\" name=\"gate_name%d\" value=%s /></td>",i,i,gate_config[i].name);
		websWrite(wp,"<td><input type=\"submit\" name=\"deleGate\" value=\"É¾³ý\" onclick=\"del(this)\" /></td>");
		i++;	
	}
	printf("succssssss!");
	
}





