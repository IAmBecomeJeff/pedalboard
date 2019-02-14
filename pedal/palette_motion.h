// Palette Motion

void palette_motion() {
	if (this_dir) { color_index += color_speed; }
	else { color_index -= color_speed; }
	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = ColorFromPalette(currentPalette, color_index, this_bright, currentBlending);
	}
}

void center_matrix_motion() {
	this_index++;

	if (random8(90) > 80) {
		fromCenterPal(0, currentPalette, this_index, this_bright, currentBlending);
	}
	else {
		fromCenterCRGB(0, 0, 0, 0);)
	}
	for (int i = 96; i > 0; i--;) {
		leds[centerRight[i]] = leds[centerRight[i - 1]];
		leds[centerLeft[i]] = leds[centerLeft[i - 1]];
	}
}