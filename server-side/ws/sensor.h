//gsoap ns service name:	myws my ws attempt
//gsoap ns service protocol:	SOAP
//gsoap ns service style:	rpc
//gsoap ns service encoding:	encoded



//gsoap ns schema namespace: myws
class ns__sensorData {
  public:
   @float                        temperature    0 = 9999; // optional ID attribute, defaults to 9999
   @float                        ecg            0 = 9999; // optional ID attribute, defaults to 9999
   @int                          pulse          0 = 9999; // optional ID attribute, defaults to 9999
   @int                          systolic       0 = 9999;
   @int                          diastolic      0 = 9999;

};

//gsoap ns schema namespace:	urn:myws
//gsoap ns service method: getSensorData sensorReadings
int ns__getSensorData(ns__sensorData *sensorReading);
