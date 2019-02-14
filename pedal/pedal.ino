// Pedalboard //

#include "includes.h"

void setup(){
	delay(2000);
	
	LEDS.setBrightness(max_bright);
	LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds,MAX_LEDS);
	
	set_max_power_in_volts_and_milliamps(5,500);
	
	NUM_LEDS = MAX_LEDS;
	
	currentPalette  = CRGBPalette16(CRGB::Black);
	targetPalette   = RainbowColors_p;
	currentBlending = LINEARBLEND;
	
	for (uint8_t i = 0; i < 61; i++) {
		backArray[i] = i;
	}
	for (uint8_t i = 0; i < 35; i++) {
		rightArray[i] = i + 61;
		leftArray[i] = i + 162;
	}
	for (uint8_t = 0; i < 66; i++) {
		frontArray[i] = i + 96;
	}
	
	strobe_mode(ledMode, 1);
}
	
void loop(){
	EVERY_N_MILLISECONDS(50){
		uint8_t maxChanges = 24;
		nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);
	}
	
	EVERY_N_SECONDS(30){
		oldMode = ledMode;
		ledMode = rand() % maxMode + 1;
		if(oldMode!=ledMode){newMode=1};
	}
	
	EVERY_N_MILLIS(thistime, this_delay){
		thistimer.setPeriod(this_delay);
		if(newMode){
			strobe_mode(ledMode,1);
		}else{
			strobe_mode(ledMode, 0);
		}
	}
	
	FastLED.show();
}
	

void strobe_mode(uint8_t thisMode, bool mc){

	if(mc) {fill_solid(leds,NUM_LEDS,CRGB(0,0,0));}
	
	switch(thisMode){
		
		case  0: if(mc) {fill_solid(leds,NUM_LEDS,CRGB(0,0,0));} break;
		case  1: if(mc) {this_delay = 10;} juggle_pal(); break;
		case  2: if(mc) {this_delay = 10;} juggle_from_center_pal(); break;
	}
}