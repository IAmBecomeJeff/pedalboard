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
	
	//Set up arrays
	for (uint8_t i = 0; i < 61; i++) {
		backArray[i] = i;
	}
	for (uint8_t i = 0; i < 35; i++) {
		rightArray[i] = i + 61;
		leftArray[i] = i + 162;
	}
	for (uint8_t i = 0; i < 66; i++) {
		frontArray[i] = i + 96;
	}
	
	for (uint8_t i = 0; i < 98; i++) {
		centerRight[i] = 128 - i;
		centerLeft[i] = 129 + 1;;
		if (i > 67) {
			centerLeft[i] = 68 - i;
		}

	}


	strobe_mode(ledMode, 1);
}
	
void loop(){
	EVERY_N_MILLISECONDS(50){
		uint8_t maxChanges = 24;
		nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);
	}
	
	EVERY_N_SECONDS(20){
		oldMode = ledMode;
		ledMode++; //= rand() % maxMode + 1;
    newMode=1;
		if(ledMode>maxMode){ledMode=1;}
		
		//if(oldMode!=ledMode){newMode=1;}
	}

	EVERY_N_SECONDS(10) {
		updatePaletteIndex(targetPalette);
		palette_index = random8(g_gradient_palette_count + 1);
		targetPalette = g_gradient_palettes[palette_index];
	}
	
	EVERY_N_MILLIS_I(thistimer, this_delay){
		thistimer.setPeriod(this_delay);
//		if(newMode){
//			strobe_mode(ledMode,1);
//     newMode=0;
//		}else{
//			strobe_mode(ledMode, 0);
//		}
    strobe_mode(4,0);
	}
	
	FastLED.show();
}
	

void strobe_mode(uint8_t thisMode, bool mc){

	if(mc) {fill_solid(leds,NUM_LEDS,CRGB(0,0,0));}
	
	switch(thisMode){
		
		case  1: if (mc) { this_delay = 10; }			juggle_pal();					break;
		case  2: if (mc) { this_delay = 10; }			juggle_from_center_pal();		break;
		case  3: if (mc) { this_delay = 10; }			palette_motion();				break;
		case  4: if (mc) { this_dir = 0;    }			palette_motion();				break;
		case  5: if (mc) { this_delay = 15; }			center_juggle_pal();			break;
		case  6: if (mc) { this_delay = 10; }			center_matrix_motion();			break;
		case  7: if (mc) { targetPalette = fire_palette; this_delay = 10; } fire_center(); break;
		case  8: if (mc) { targetPalette = fire_palette2; this_delay = 10; } fire_center(); break;
		case  9: if (mc) { targetPalette = fire_palette_blue; this_delay = 10; } fire_center(); break;
	}
}
