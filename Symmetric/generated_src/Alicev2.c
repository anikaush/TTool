#include "Alice.h"


// Header code defined in the model
#include <string.h>
#include <stdio.h>
#include <openssl/aes.h>

char key_enc[] = "thisisasecretkey";

extern int myLovelyArray[100];
extern int nextAvailableID = 0;


  __attribute__((unused)) request __req0;
  __attribute__((unused))int *__params0[1];
  __attribute__((unused))setOfRequests __list;
  __attribute__((unused))pthread_cond_t __myCond;
  __attribute__((unused))request *__returnRequest;






// a simple hex-print routine
static void hex_print(const void* pv, size_t len)
{
      const unsigned char * p = (const unsigned char*)pv;
      if (NULL == pv)
          printf("NULL");
      else
      {
            size_t i = 0;
            for (; i<len;++i)
                printf("%02X ", *p++);
      }
  
      printf("\n");
}



// Function to implement substring function in C
char* substring(char *destination, const char *source, int beg, int n)
{
   // extracts n characters from source string starting from beg index
   // and copy them into the destination string
   while (n > 0)
   {
      *destination = *(source + beg);
    
      destination++;
      source++;
      n--;
   }
  
   // null terminate destination string
   *destination = '\0';
  
   // return the destination string
   return destination;
}

/*
void __userImplemented__Alice__sendInSeveralChunks(int msg__data) {
  printf("\sendinginseveral:%d\t",msg__data);
  
   char text[]="hello world";
   char sub[];
   int chunkSize = 4;
          int stringLength = text.length;
          for (int i = 0; i < stringLength ; i += chunkSize)
          {
    
                if (i + chunkSize > stringLength) 
               {chunkSize = stringLength  - i;}
                 Substring(sub,text,i, chunkSize);
    
          }
  
}

*/

void __userImplemented__Alice__sendInSeveralChunks(int id) {
    printf("send in several chunks has been called\n");
    
   
    
   for ( int j = 0 ; j <strlen(myLovelyArray) ; j ++){
    
       
        printf("send in several chunks iteration %d \n",j);
        
       int m1__data = myLovelyArray[j];
        __params0[0] = &m1__data;
        
        printf("param0 iteration %d in several chunks %d\n",j,  m1__data);
        
      makeNewRequest(&__req0, 2849, SEND_SYNC_REQUEST, 0, 0, 0, 1, __params0);
      __req0.syncChannel = &__System_chin__System_chout;
      __returnRequest = executeOneRequest(&__list, &__req0);
      clearListOfRequests(&__list);
     
     
      printf("sending\n");
      
       
   }
    
    
   
   
  
          
          
  
}



int __userImplemented__Alice__sencrypt(int msg__data, int
k__data) {
      printf("My execution of sencrypt\n");
    unsigned char text[]="hi anish";
    unsigned char enc_out[80];
    unsigned char *p ;
    unsigned char saved [80];
  
          
    int ret = nextAvailableID;
  
    AES_KEY enc_key;
  
    AES_set_encrypt_key(key_enc, 128, &enc_key);
    AES_encrypt(text, enc_out, &enc_key);
  
  //printing the original msg
    printf("\noriginal:%s\t",text);
  
  //printing the original msg in hex
    int i;
    printf("original:\t");
    for(i=0;*(text+i)!=0x00;i++)
     printf("%02X ",*(text+i));
  
  
  // printing the encrypted msg in hex
    printf("\nencrypted:\t");
    hex_print(enc_out, sizeof(enc_out));
  
  
  
  //printing the encrypted msg 
    printf("\nencrypted:%s\t",enc_out);
    printf("\n");
  
  
  for ( int j = 0; j <=strlen(enc_out) ; j ++){
    
     myLovelyArray[nextAvailableID] = (int) (enc_out[j]);
    
    printf("myLovelyArray[%d] = ",nextAvailableID);
     printf(" %d\n",myLovelyArray[nextAvailableID]);
     
     /*printf("enc_out[0] is: %c\t", enc_out[0]);
        
        printf("myLovelyArray[0] in int: %d \n", myLovelyArray[0]);
    
        char msg_d = (char) (myLovelyArray[0]);
        printf("myLovelyArray[0] in char: %c \n", msg_d);*/
    
     
     if(nextAvailableID<99) {
          nextAvailableID ++;
      } else {
          nextAvailableID = 0;
       }
      
  }
  
  
  printf("\n");
     return ret;
}




 

// End of header code defined in the model

#define STATE__START__STATE 0
#define STATE__beforeFinish 1
#define STATE__sendingMessage 2
#define STATE__makingMessage 3
#define STATE__STOP__STATE 4

int Alice__encrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Alice", "encrypt", my__attr);
  return msg__data;
}


int Alice__decrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Alice", "decrypt", my__attr);
  return msg__data;
}


int Alice__sencrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Alice", "sencrypt", my__attr);
  return __userImplemented__Alice__sencrypt(msg__data, k__data);
}


int Alice__sdecrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Alice", "sdecrypt", my__attr);
  return msg__data;
}


int Alice__MAC(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Alice", "MAC", my__attr);
  return msg__data;
}


bool Alice__verifyMAC(int msg__data, int k__data, int macmsg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg__data,k__data,macmsg__data);
  traceFunctionCall("Alice", "verifyMAC", my__attr);
  return msg__data;
}


int Alice__concat2(int msg1__data, int msg2__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg1__data,msg2__data);
  traceFunctionCall("Alice", "concat2", my__attr);
  return msg1__data;
}


int Alice__concat3(int msg1__data, int msg2__data, int msg3__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg1__data,msg2__data,msg3__data);
  traceFunctionCall("Alice", "concat3", my__attr);
  return msg1__data;
}


int Alice__concat4(int msg1__data, int msg2__data, int msg3__data, int msg4__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d",msg1__data,msg2__data,msg3__data,msg4__data);
  traceFunctionCall("Alice", "concat4", my__attr);
  return msg1__data;
}


void Alice__get2(int msg__data, int msg1__data, int msg2__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg__data,msg1__data,msg2__data);
  traceFunctionCall("Alice", "get2", my__attr);
}


void Alice__get3(int msg__data, int msg1__data, int msg2__data, int msg3__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d",msg__data,msg1__data,msg2__data,msg3__data);
  traceFunctionCall("Alice", "get3", my__attr);
}


void Alice__get4(int msg__data, int msg1__data, int msg2__data, int msg3__data, int msg4__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d,%d",msg__data,msg1__data,msg2__data,msg3__data,msg4__data);
  traceFunctionCall("Alice", "get4", my__attr);
}


int Alice__aencrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Alice", "aencrypt", my__attr);
  return msg__data;
}


int Alice__adecrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Alice", "adecrypt", my__attr);
  return msg__data;
}


int Alice__pk(int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",k__data);
  traceFunctionCall("Alice", "pk", my__attr);
  return k__data;
}


int Alice__sign(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Alice", "sign", my__attr);
  return msg__data;
}


bool Alice__verifySign(int msg1__data, int sig__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg1__data,sig__data,k__data);
  traceFunctionCall("Alice", "verifySign", my__attr);
  return msg1__data;
}


int Alice__cert(int k__data, int msg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",k__data,msg__data);
  traceFunctionCall("Alice", "cert", my__attr);
  return k__data;
}


bool Alice__verifyCert(int cert__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",cert__data,k__data);
  traceFunctionCall("Alice", "verifyCert", my__attr);
  return cert__data;
}


int Alice__getpk(int cert__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",cert__data);
  traceFunctionCall("Alice", "getpk", my__attr);
  return cert__data;
}


int Alice__DH(int pubK__data, int privK__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",pubK__data,privK__data);
  traceFunctionCall("Alice", "DH", my__attr);
  return pubK__data;
}


int Alice__hash(int msg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",msg__data);
  traceFunctionCall("Alice", "hash", my__attr);
  return msg__data;
}


void Alice__sendInSeveralChunks(int id) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",id);
  traceFunctionCall("Alice", "sendInSeveralChunks", my__attr);
  __userImplemented__Alice__sendInSeveralChunks(id);
}


void *mainFunc__Alice(void *arg){
  int secretData = 0;
  int m__data = 0;
  int m1__data = 0;
  int sk__data = 0;
  
  int __currentState = STATE__START__STATE;
  
  char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond, NULL);
  
  fillListOfRequests(&__list, __myname, &__myCond, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      __currentState = STATE__makingMessage;
      break;
      
      case STATE__beforeFinish: 
      traceStateEntering(__myname, "beforeFinish");
      __currentState = STATE__STOP__STATE;
      break;
      
      case STATE__sendingMessage: 
      traceStateEntering(__myname, "sendingMessage");
      Alice__sendInSeveralChunks(m__data);
      __params0[0] = &m1__data;
      makeNewRequest(&__req0, 2849, SEND_SYNC_REQUEST, 0, 0, 0, 1, __params0);
      __req0.syncChannel = &__System_chin__System_chout;
      __returnRequest = executeOneRequest(&__list, &__req0);
      clearListOfRequests(&__list);
      traceRequest(__myname, __returnRequest);
      __currentState = STATE__beforeFinish;
      break;
      
      case STATE__makingMessage: 
      traceStateEntering(__myname, "makingMessage");
      m__data = secretData;
      traceVariableModification("Alice", "m__data", m__data,0);
      m1__data = Alice__sencrypt(m__data, sk__data);
      traceVariableModification("Alice", "m1__data", m1__data,0);
      
      __currentState = STATE__sendingMessage;
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

