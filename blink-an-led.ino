SYSTEM_THREAD(ENABLED);

const pin_t SENSOR_PIN = A0;

int analogvalue;
bool litUp;
int ledToggle(String command); // Forward declaration

void setup()
{
    //setups initial value for litUp
    litUp = false;
    
}

void loop()
{
    //checks phototransister values
    analogvalue = analogRead(SENSOR_PIN);

    //checks if light turned on or off 
    if(analogvalue > 100 && litUp == false){
        litUp = true;
        Particle.publish("phototransistor", String(litUp), PRIVATE);
    }
    else if(analogvalue < 100 && litUp == true){
        litUp = false;
        Particle.publish("phototransistor", String(litUp), PRIVATE);
    }
    //delayed in order to not oversample
    delay(5000ms);
}
