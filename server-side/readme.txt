g++ -I/home/pi/gsoap-2.8/ -lpthread -lrt -o server ../eHealth.o ../arduPi.o ../eHealthServer.cpp soapC.cpp soapmywsService.cpp soapmywsProxy.cpp -lgsoap++
