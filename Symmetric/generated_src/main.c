#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "request.h"
#include "syncchannel.h"
#include "request_manager.h"
#include "debug.h"
#include "random.h"
#include "tracemanager.h"

/* User code */
#include <string.h>
#include <stdio.h>
#include <openssl/aes.h>

int myLovelyArray[100];
int nextAvailableID;
int ReceiArray[100];

void __user_init() {
  
  
  
  
}

/* End of User code */

/* Main mutex */
pthread_mutex_t __mainMutex;

/* Synchronous channels */
syncchannel __System_chin__System_chout;
/* Asynchronous channels */

#include "System.h"
#include "Bob.h"
#include "Alice.h"


int main(int argc, char *argv[]) {
  
  /* disable buffering on stdout */
  setvbuf(stdout, NULL, _IONBF, 0);
  
  /* Synchronous channels */
  __System_chin__System_chout.inname ="chin";
  __System_chin__System_chout.outname ="chout";
  /* Asynchronous channels */
  
  /* Threads of tasks */
  pthread_t thread__System;
  pthread_t thread__Bob;
  pthread_t thread__Alice;
  /* Activating tracing  */
  if (argc>1){
    activeTracingInFile(argv[1]);
  } else {
    activeTracingInConsole();
  }
  /* Activating randomness */
  initRandom();
  /* Initializing the main mutex */
if (pthread_mutex_init(&__mainMutex, NULL) < 0) { exit(-1);}
  
  /* Initializing mutex of messages */
  initMessages();
  /* User initialization */
  __user_init();
  
  
  pthread_create(&thread__System, NULL, mainFunc__System, (void *)"System");
  pthread_create(&thread__Bob, NULL, mainFunc__Bob, (void *)"Bob");
  pthread_create(&thread__Alice, NULL, mainFunc__Alice, (void *)"Alice");
  
  
  pthread_join(thread__System, NULL);
  pthread_join(thread__Bob, NULL);
  pthread_join(thread__Alice, NULL);
  
  
  return 0;
  
}
