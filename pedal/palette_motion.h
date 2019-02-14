// Palette Motion

void palette_motion() {
	if (this_dir) { color_index += color_speed; }
	else { color_index -= color_speed; }
	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = ColorFromPalette(currentPalette, color_index, this_bright, currentBlending);
	}
}