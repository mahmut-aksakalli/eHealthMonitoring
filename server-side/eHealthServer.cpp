
#include "ws/myws.nsmap"
#include "ws/soapmywsProxy.h" // generated with soapcpp2 -j calc.h
#include "ws/soapmywsService.h"

#include "eHealth.h"

int port = 8080;

float temperature = 0;
float ECG = 0;
int systolic = 0;
int diastolic = 0;
int pulse = 0;

void setup() {
  eHealth.readBloodPressureSensor();
  delay(100);
}

void getSensorReadings() {
	temperature = eHealth.getTemperature(); 	// Temperature Reading
	ECG = eHealth.getECG(); 	// ECG Reading

	// Blood Pressure Reading
	uint8_t numberOfData = eHealth.getBloodPressureLength();
	systolic 	= 30+eHealth.bloodPressureDataVector[numberOfData-1].systolic;
  diastolic = eHealth.bloodPressureDataVector[numberOfData-1].diastolic;
	pulse 		= eHealth.bloodPressureDataVector[numberOfData-1].pulse;

}

int main()
{
  setup();

  mywsService calc(SOAP_XML_INDENT);                     // service class generated with soapcpp2 -j
  calc.soap->accept_timeout = 24*60*60;                  // quit after 24h of inactivity (optional)
  calc.soap->send_timeout = calc.soap->recv_timeout = 5; // max send and receive socket inactivity time (sec)
  calc.soap->transfer_timeout = 10;                      // max time for send or receive of messages (sec)

printf("xxx");		
  while (calc.run(port)){                                 // bind, then loop to accept and serve requests
    calc.soap_stream_fault(std::cerr);
}	
  calc.destroy();        // delete deserialized objects and temp data
  return 0;
}


int mywsService::getSensorData(ns__sensorData* data)
{
  getSensorReadings();
  data->temperature = temperature;
  data->ecg = ECG;
  data->pulse = pulse;
  data->systolic = systolic;
  data->diastolic = diastolic;

  return SOAP_OK;
}
