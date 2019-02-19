#ifndef ONE_SIN_H
#define ONE_SIN_H


/*
 * Usage - one_sin_pal();
 * 
 * all_freq - What is the frequency
 * bg_bri - The background brightness
 * bg_clr - The background colour
 * start_index  - What foreground colour are we starting with?
 * this_bright - How bright is it?
 * this_cutoff - If the brightness is lower than this_, then brightness=0
 * this_inc - incrementer to change the starting colour after each pass
 * this_index - rotating colours down the strip counter
 * this_phase - the counter used in conjunction with the frequency to move down the strip
 * this_rot - How quickly to rotate those colours down the strip
 * this_speed  - How fast does it whip down the strand
 */


void one_sin_pal() { 
	start_index += this_inc;
	this_index = start_index;
	this_phase -= this_speed;                                                                     // You can change direction and speed individually.
	for (int k = 0; k<MAX_LEDS; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		int this_bright = qsubd(cubicwave8((k*all_freq) + this_phase), this_cutoff);          // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
		leds[k] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
		leds[k] += ColorFromPalette(current_palette, this_index + k * this_inc, this_bright, current_blending);
		this_index += this_rot;
	}
}

void one_sin_center_pal() { 
	start_index += this_inc;
	this_index = start_index;
	this_phase -= this_speed;                                                                     // You can change direction and speed individually.
	for (int k = 0; k<STRAND_LENGTH; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		int this_bright = qsubd(cubicwave8((k*all_freq) + this_phase), this_cutoff);          // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
		leds[rightFromCenter[k]] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
		leds[rightFromCenter[k]] += ColorFromPalette(current_palette, this_index + k * this_inc, this_bright, current_blending);
		leds[leftFromCenter[k]] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
		leds[leftFromCenter[k]] += ColorFromPalette(current_palette, this_index + k * this_inc, this_bright, current_blending);
		this_index += this_rot;
	}
}




#endif
