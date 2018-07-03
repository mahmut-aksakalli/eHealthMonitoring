

//Include eHealth library
#include "eHealth.h"

void setup() { 
  eHealth.readBloodPressureSensor();
  delay(100);    
}

void loop() {

  uint8_t numberOfData = eHealth.getBloodPressureLength();   
  printf("Number of measures : ");    
  printf("%d\n",numberOfData);   
  delay(100);


 

  delay(200);
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}
