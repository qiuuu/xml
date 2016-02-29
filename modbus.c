#include "webs.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "webHeader.h"
#define BUF_SIZE 1024
#define MYKEY 25

#include<libxml/tree.h>
#include<libxml/parser.h>



void GoFormModbusConfig(webs_t wp, char_t *path, char_t *query)
{
//	int shmid;
//	char *shmptr;
       char *devName, *seriaName;

	char *saveBtn;
	char *getBtn;


	char *nid;
	char *nname;
	char *ntime, *nbaud, *nparity, *ndata, *nstop, *ninfo;
 	printf("HELLO!\n");
	xmlDocPtr pdoc = NULL;
	xmlNodePtr proot = NULL, pcur = NULL;
	xmlChar *xmlId, *xmlName, *xmlBaud,*xmlParity, *xmlStop, *xmlData, *xmlTimeout, *xmlInfo;

        devName = websGetVar(wp,T("name"),"");
        seriaName = websGetVar(wp,T("serialName"),""); 
        printf("%s \n",strcpy(modArg.id,devName));
        printf("seria is %s \n",strcpy(modArg.name,seriaName)); 
        getBtn = websGetVar(wp,T("getBtn"),T(""));
	saveBtn = websGetVar(wp,T("saveBtn"),T(""));
        printf("ready button \n");
        if(strlen(getBtn)!=0)
	{

	    pdoc = xmlReadFile("modbus.xml","UTF-8",XML_PARSE_RECOVER);
	    
	    proot = xmlDocGetRootElement(pdoc);
            printf("get the proot !!!\n");
	    pcur = proot->xmlChildrenNode;
	    while(pcur!=NULL)
	    {
	 	if(!xmlStrcmp(pcur->name, (const xmlChar*)"dev")){
	  		xmlId = xmlGetProp(pcur,(const xmlChar*)"ID");
			xmlName = xmlGetProp(pcur,(const xmlChar*)"Sname"); 
                        printf("the devNa is %s\n",devName); 
			if(!strcmp(xmlId,devName) && !strcmp(xmlName,seriaName))
			{
              		     xmlBaud = xmlGetProp(pcur,(const xmlChar*)"baud");
 		             xmlTimeout = xmlGetProp(pcur,(const xmlChar*)"timeout");
                             xmlParity = xmlGetProp(pcur,(const xmlChar*)"parity");
                             xmlStop = xmlGetProp(pcur,(const xmlChar*)"stop");
		       	     xmlData = xmlGetProp(pcur,(const xmlChar*)"data");
                             xmlInfo = xmlGetProp(pcur,(const xmlChar*)"info"); 



			     printf("get the id is : %s\n",strcpy(modArg.id,xmlId));
                             printf("get the serianame is : %s\n",strcpy(modArg.name,xmlName));
                             printf("get the baud is :!!%s\n",strcpy(modArg.baud,xmlBaud));
			     printf("get the parity is : %s\n",strcpy(modArg.parity,xmlParity));
			     printf("get the data is :!!%s\n",strcpy(modArg.data_bit,xmlData));	 	
			     printf("get the stop_bit is : %s\n",strcpy(modArg.stop_bit,xmlStop));
                             printf("get the timeout is : %s\n",strcpy(modArg.time_out,xmlTimeout));
                             printf("get the information is :!!%s\n",strcpy(modArg.info,xmlInfo));


                             xmlFree(xmlId);
			     xmlFree(xmlName);
                             xmlFree(xmlBaud);
			     xmlFree(xmlTimeout);    
                             xmlFree(xmlParity);
			     xmlFree(xmlStop); 
                             xmlFree(xmlData);
                             xmlFree(xmlInfo); 
                             break;
			} 		
		}
		pcur = pcur->next;
	    }
	
        	xmlFreeDoc(pdoc);
        }else if(strlen(saveBtn)!=0){
	    printf("enter the save area!!!\n");


            pdoc = xmlReadFile("modbus.xml","UTF-8",XML_PARSE_RECOVER);
            proot = xmlDocGetRootElement(pdoc);
            pcur = proot->xmlChildrenNode;
            printf("the pcur is %s\n",pcur->name); 
       	    while(pcur!=NULL)
            {
                 printf("the pcur in while is%s\n",pcur->name); 
                 xmlId = xmlGetProp(pcur,(const xmlChar*)"ID");
	         if(!xmlStrcmp(xmlId, (const xmlChar*)devName))
	         {			

                         
         	                     printf("the dev is %s\n",devName); 
  		                   
                                     nid = websGetVar(wp,T("name"),T(""));		 
                                     nname = websGetVar(wp,T("serialName"),T("")); 
				     nbaud = websGetVar(wp,T("opSelect1"),T(""));
                                     nparity = websGetVar(wp,T("opSelect2"),T(""));
                                     ndata = websGetVar(wp,T("opSelect3"),T(""));
                                     nstop = websGetVar(wp,T("opSelect4"),T(""));
                                     ntime = websGetVar(wp,T("time"),T(""));
                                     ninfo = websGetVar(wp,T("info"),T(""));
                                      




                                     xmlSetProp(pcur,(const xmlChar*)"ID",(const xmlChar*)nid);
				     xmlSetProp(pcur,(const xmlChar*)"Sname",(const xmlChar*)nname);
	 	
                                     xmlSetProp(pcur,(const xmlChar*)"baud",(const xmlChar*)nbaud);
                                     xmlSetProp(pcur,(const xmlChar*)"parity",(const xmlChar*)nparity);
                                     xmlSetProp(pcur,(const xmlChar*)"data",(const xmlChar*)ndata);
                                     xmlSetProp(pcur,(const xmlChar*)"stop",(const xmlChar*)nstop); 
                                     xmlSetProp(pcur,(const xmlChar*)"timeout",(const xmlChar*)ntime);
                                     xmlSetProp(pcur,(const xmlChar*)"info",(const xmlChar*)ninfo); 
                                     
				     

				     xmlBaud = xmlGetProp(pcur,(const xmlChar*)"baud");
				     xmlParity = xmlGetProp(pcur,(const xmlChar*)"parity"); 
				     xmlTimeout = xmlGetProp(pcur,(const xmlChar*)"timeout"); 
				     xmlStop = xmlGetProp(pcur,(const xmlChar*)"stop");
                                     xmlData = xmlGetProp(pcur,(const xmlChar*)"data");
      

                                     xmlInfo = xmlGetProp(pcur,(const xmlChar*)"info");  
       

                                     printf("sur info ssss %s\n",strcpy(modArg.info,xmlInfo));
                                     printf("sur baud ssss %s\n",strcpy(modArg.baud,(const char*)xmlBaud));
				     printf("show parity %s\n",strcpy(modArg.parity,xmlParity));
                                     printf("save the timeout After is %s\n",strcpy(modArg.time_out,(const char*)xmlTimeout));
 				     printf("show the stop_bit is %s\n",strcpy(modArg.stop_bit,xmlStop)); 

                                     printf("data_bit is %s\n",strcpy(modArg.data_bit,xmlData));
                                        


			             xmlSaveFormatFileEnc("modbus.xml",pdoc,"UTF-8",1); 
                                
				     
                                     xmlFree(xmlBaud);
                                     xmlFree(xmlParity);
                                     xmlFree(xmlStop);
				     xmlFree(xmlTimeout);
                                     xmlFree(xmlData);
                                     xmlFree(xmlInfo);
                         
                                      break;
                 }
		 pcur = pcur->next;
  		if(pcur==NULL)
		{
			printf("make a new dev\n");
			pcur = xmlNewNode(NULL,(const xmlChar*)"dev");
			xmlAddChild(proot,pcur);
			xmlNewProp(pcur,(const xmlChar*)"ID",(const xmlChar*)devName);
			xmlNewProp(pcur,(const xmlChar*)"Sname",(const xmlChar*)seriaName);
			xmlNewProp(pcur,(const xmlChar*)"baud",(const xmlChar*)"NULL");
			xmlNewProp(pcur,(const xmlChar*)"parity",(const xmlChar*)"NULL");
			xmlNewProp(pcur,(const xmlChar*)"data",(const xmlChar*)"NULL");
			xmlNewProp(pcur,(const xmlChar*)"stop",(const xmlChar*)"NULL");
			xmlNewProp(pcur,(const xmlChar*)"timeout",(const xmlChar*)"NULL");
			xmlNewProp(pcur,(const xmlChar*)"info",(const xmlChar*)"NULL");
			printf("successful new!%s\n",pcur->name);	
		}
	   }
     

           xmlFreeDoc(pdoc); 

	} 
/*
	if((shmid = shmget(MYKEY,BUF_SIZE,IPC_CREAT)) ==-1)     
        {     
           printf("shmget error!\n");     
           exit(1);     
        }

        if((shmptr = shmat(shmid,0,0)) == (void *)-1)     
        {     
 	   printf("shmat error!\n");     
           exit(1);     
        }     
        
	   printf("string:%s\n",shmptr);
	   sleep(3);

        fp = fopen("modbus.txt","w");
        
        fprintf(fp, "%s\n",shmptr);

        fclose(fp);
*/
        websRedirect(wp,T("modbus.asp")); 
	return ;	
}





int AspModbusIdShow(int eid, webs_t wp, int argc, char_t **argv)
{
	
	websWrite(wp,T(modArg.id));
	return 1;

}



int AspModbusNameShow(int eid, webs_t wp, int argc, char_t **argv)
{
	websWrite(wp,T(modArg.name));
	return 1;


}



int AspModbusBaudShow(int eid, webs_t wp, int argc, char_t **argv)
{
        int select_num = atoi(argv[0]); 
	if(!strcmp(modArg.baud,"9600") && select_num == 1)
             websWrite(wp,"selected");
        else if(!strcmp(modArg.baud,"9800") && select_num ==2) 
	     websWrite(wp,"selected");

       return 1;

}


int AspModbusParityShow(int eid, webs_t wp, int argc, char_t **argv)
{
        int select_num = atoi(argv[0]);	 
        if(!strcmp(modArg.parity,"1") && select_num == 1) 
	     websWrite(wp,"selected");
	else if(!strcmp(modArg.parity,"0") && select_num == 2)
	     websWrite(wp,"selected"); 
       return 1;

}


int AspModbusDataShow(int eid, webs_t wp, int argc, char_t **argv)
{
        int select_num = atoi(argv[0]);
        if(!strcmp(modArg.data_bit,"3") && select_num == 1)
             websWrite(wp,"selected");
        else if(!strcmp(modArg.data_bit,"8") && select_num ==2)
             websWrite(wp,"selected"); 

	return 1;

}

int AspModbusStopShow(int eid, webs_t wp, int argc, char_t **argv)
{
        int select_num = atoi(argv[0]);
        if(!strcmp(modArg.stop_bit,"1") && select_num == 1)
             websWrite(wp,"selected");
        else if(!strcmp(modArg.stop_bit,"2") && select_num ==2)
             websWrite(wp,"selected"); 
	return 1;

}

int AspModbusTimeoutShow(int eid, webs_t wp, int argc, char_t **argv)
{
        websWrite(wp,T(modArg.time_out));
        return 1;

}

int AspModbusInfoShow(int eid, webs_t wp, int argc, char_t **argv)
{
        websWrite(wp,T(modArg.info));
        return 1;

}


int AspModbusShow(int eid, webs_t wp, int argc, char_t **argv)
{
        //printf("shmptr is :%s\n", modArg.baud); 	
       // websWrite(wp,T(modArg.baud));
        return 1;

}


