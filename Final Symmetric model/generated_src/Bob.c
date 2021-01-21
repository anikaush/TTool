#include "Bob.h"


// Header code defined in the model
///bob's side



#include <string.h>
#include <stdio.h>
#include <openssl/aes.h>
extern int myLovelyArray[100];
extern int nextAvailableID ;
char key_dec[] = "thisisasecretkey";

extern int ReceiArray[100];
 char Receistring[160];

int m2__data;
int m1__data;

  __attribute__((unused)) request __req0__bob;
  __attribute__((unused))int *__params0__bob[1];
  __attribute__((unused))setOfRequests __list__bob;
  __attribute__((unused))pthread_cond_t __myCond__bob;
  __attribute__((unused))request *__returnRequest__bob;

// a simple hex-print routine. could be modified to print 16 bytes-per-line
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




int __userImplemented__Bob__receiveInSeveralChunks(int id){
   int z =0;
   
  printf("we are in receive in several chunks\n");
  while (z < nextAvailableID) 
    {    __params0__bob[0] = &m2__data;
          makeNewRequest(&__req0__bob, 2849, RECEIVE_SYNC_REQUEST, 0, 0, 0, 1, __params0__bob);
         
 /*           printf("param0 Bob __req0 1 %d : %d \n",z,__req0__bob); 
      printf("param0 Bob  RECEIVE_SYNC_REQUEST %d : %d \n",z,RECEIVE_SYNC_REQUEST); 
      printf("param0 Bob __System_chin__System_chout %d : %d \n",z,__System_chin__System_chout); 
      printf("param0 Bob __list 1 %d : %d \n",z,__list__bob); 
      
      printf("param0 Bob m1__data %d : %d \n",z,m1__data); 
      printf("param0 Bob m2__data %d : %d \n",z,&m2__data); 
      printf("param0 Bob __params0[0] %d : %d \n",z,__params0__bob[0]); 
       printf("---------------------------------- \n");
  */
          __req0__bob.syncChannel = &__System_chin__System_chout;
          __returnRequest__bob = executeOneRequest(&__list__bob, &__req0__bob);
       /*   
           printf("param0 Bob __list 2 %d : %d \n",z,__list__bob); 
      printf("param0 Bob __req0 2  %d : %d \n",z,__req0__bob); 
      printf("param0 Bob __returnRequest %d : %d \n",z,__returnRequest__bob); */
          clearListOfRequests(&__list__bob);
    
     
    
      ReceiArray[z] = m2__data;
      printf("received data %d \n",ReceiArray[z]);
      Receistring[z] = (char) (ReceiArray[z]);
      printf("Receistring[%d] = ",z);
      printf(" %d\n",Receistring[z]);
      
 
    
     z++;  
    }
    
        return (0);
  
}



int __userImplemented__Bob__sdecrypt(int msg__data, int
k__data) {
  
  printf("Welcome to bob's side\n \n");
      printf("My execution of sdecrypt\n");
  
  
  
  
  
  unsigned char dec_out[160];
  
  AES_KEY dec_key;
  
  int i;
  
 
  hex_print(dec_out, sizeof(dec_out));
  
  AES_set_decrypt_key(key_dec, 128, &dec_key);
  AES_decrypt(Receistring, dec_out, &dec_key);
  
  
  
  printf("\ndecrypted:%s\t \n",dec_out);
  printf("\n");
     
  
  
   int x =0 ;
   while (x <= nextAvailableID)
   {
     printf("ReceiArray[%d] = ",x);
      printf(" %d\n",ReceiArray[x]);
      x++;
     
     
   }
   
    return dec_out;
      
      
  
}

// End of header code defined in the model

#define STATE__START__STATE 0
#define STATE__messageDecrypted 1
#define STATE__SecretDataReceived 2
#define STATE__messageDecrypt 3
#define STATE__waitingForMessage 4
#define STATE__STOP__STATE 5

int Bob__encrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Bob", "encrypt", my__attr);
  return msg__data;
}


int Bob__decrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Bob", "decrypt", my__attr);
  return msg__data;
}


int Bob__sencrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Bob", "sencrypt", my__attr);
  return msg__data;
}


int Bob__sdecrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Bob", "sdecrypt", my__attr);
  return __userImplemented__Bob__sdecrypt(msg__data, k__data);
}


int Bob__MAC(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Bob", "MAC", my__attr);
  return msg__data;
}


bool Bob__verifyMAC(int msg__data, int k__data, int macmsg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg__data,k__data,macmsg__data);
  traceFunctionCall("Bob", "verifyMAC", my__attr);
  return msg__data;
}


int Bob__concat2(int msg1__data, int msg2__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg1__data,msg2__data);
  traceFunctionCall("Bob", "concat2", my__attr);
  return msg1__data;
}


int Bob__concat3(int msg1__data, int msg2__data, int msg3__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg1__data,msg2__data,msg3__data);
  traceFunctionCall("Bob", "concat3", my__attr);
  return msg1__data;
}


int Bob__concat4(int msg1__data, int msg2__data, int msg3__data, int msg4__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d",msg1__data,msg2__data,msg3__data,msg4__data);
  traceFunctionCall("Bob", "concat4", my__attr);
  return msg1__data;
}


void Bob__get2(int msg__data, int msg1__data, int msg2__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg__data,msg1__data,msg2__data);
  traceFunctionCall("Bob", "get2", my__attr);
}


void Bob__get3(int msg__data, int msg1__data, int msg2__data, int msg3__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d",msg__data,msg1__data,msg2__data,msg3__data);
  traceFunctionCall("Bob", "get3", my__attr);
}


void Bob__get4(int msg__data, int msg1__data, int msg2__data, int msg3__data, int msg4__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d,%d,%d",msg__data,msg1__data,msg2__data,msg3__data,msg4__data);
  traceFunctionCall("Bob", "get4", my__attr);
}


int Bob__aencrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Bob", "aencrypt", my__attr);
  return msg__data;
}


int Bob__adecrypt(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Bob", "adecrypt", my__attr);
  return msg__data;
}


int Bob__pk(int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",k__data);
  traceFunctionCall("Bob", "pk", my__attr);
  return k__data;
}


int Bob__sign(int msg__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",msg__data,k__data);
  traceFunctionCall("Bob", "sign", my__attr);
  return msg__data;
}


bool Bob__verifySign(int msg1__data, int sig__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d,%d",msg1__data,sig__data,k__data);
  traceFunctionCall("Bob", "verifySign", my__attr);
  return msg1__data;
}


int Bob__cert(int k__data, int msg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",k__data,msg__data);
  traceFunctionCall("Bob", "cert", my__attr);
  return k__data;
}


bool Bob__verifyCert(int cert__data, int k__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",cert__data,k__data);
  traceFunctionCall("Bob", "verifyCert", my__attr);
  return cert__data;
}


int Bob__getpk(int cert__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",cert__data);
  traceFunctionCall("Bob", "getpk", my__attr);
  return cert__data;
}


int Bob__DH(int pubK__data, int privK__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d,%d",pubK__data,privK__data);
  traceFunctionCall("Bob", "DH", my__attr);
  return pubK__data;
}


int Bob__hash(int msg__data) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",msg__data);
  traceFunctionCall("Bob", "hash", my__attr);
  return msg__data;
}


int Bob__receiveInSeveralChunks(int id) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",id);
  traceFunctionCall("Bob", "receiveInSeveralChunks", my__attr);
  return __userImplemented__Bob__receiveInSeveralChunks(id);
}


void *mainFunc__Bob(void *arg){
  int m__data = 0;
  int m2__data = 0;
  int sk__data = 0;
  int receivedData = 0;
  
  int __currentState = STATE__START__STATE;

  
 char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond__bob, NULL);
  
  fillListOfRequests(&__list__bob, __myname, &__myCond__bob, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      __currentState = STATE__waitingForMessage;
      break;
      
      case STATE__messageDecrypted: 
      traceStateEntering(__myname, "messageDecrypted");
      receivedData = m__data;
      traceVariableModification("Bob", "receivedData", receivedData,0);
      __currentState = STATE__SecretDataReceived;
      break;
      
      case STATE__SecretDataReceived: 
      traceStateEntering(__myname, "SecretDataReceived");
      __currentState = STATE__STOP__STATE;
      break;
      
      case STATE__messageDecrypt: 
      traceStateEntering(__myname, "messageDecrypt");
      m2__data = Bob__receiveInSeveralChunks(receivedData);
      traceVariableModification("Bob", "m2__data", m2__data,0);
      m__data = Bob__sdecrypt(m2__data, sk__data);
      traceVariableModification("Bob", "m__data", m__data,0);
      __currentState = STATE__messageDecrypted;
      break;
      
      case STATE__waitingForMessage: 
      traceStateEntering(__myname, "waitingForMessage");
      __params0__bob[0] = &m2__data;
      makeNewRequest(&__req0__bob, 2849, RECEIVE_SYNC_REQUEST, 0, 0, 0, 1, __params0__bob);
      __req0__bob.syncChannel = &__System_chin__System_chout;
      __returnRequest__bob = executeOneRequest(&__list__bob, &__req0__bob);
      clearListOfRequests(&__list__bob);
      traceRequest(__myname, __returnRequest__bob);
      __currentState = STATE__messageDecrypt;
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

