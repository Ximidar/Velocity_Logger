//Velocity_Logger.ino

int LED = 13;
int flow_data_pin  = 2;

volatile long steps = 0;
bool led_state = false;

double flow_rate = 0.00;
long last_time = 0;

void setup() {
	Serial.begin(9600);
	Serial.println("Starting Velocity_Logger");
	pinMode(LED, OUTPUT);
	pinMode(flow_data_pin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(flow_data_pin), interupt, RISING);
	Serial.println("Finished Set up");
}

void loop() {
	steps = 0;
	sei();
  	delay(500);
	cli();
	flow_rate = steps ;
	Serial.print("steps per half second: ");
	Serial.println(flow_rate);
	led_state = !led_state;
	digitalWrite(LED, led_state);
  	
}

void interupt(){
	steps++;
	
	
}
