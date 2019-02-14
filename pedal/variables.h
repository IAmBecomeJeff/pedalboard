// Variables

#define LED_DT 7
#define COLOR_ORDER GRB
#define MAX_LEDS 197
#define LED_TYPE WS2812

uint8_t NUM_LEDS;
uint8_t max_bright = 255;
struct CRGB leds[MAX_LEDS];

CRGBPalette16 currentPalette;
CRGBPalette16 targetPalette;
TBlendType currentBlending;


// Variables

int this_delay = 10;
int maxMode = 10;

uint8_t start_index = 0;
uint8_t this_beat = 24;
uint8_t this_bright = 255;
uint8_t this_diff = 64;
uint8_t this_fade = 16;
uint8_t this_index = 0;
uint8_t num_dots = 1;
uint8_t this_hue;

int leftArray[35];
int rightArray[35];
int frontArray[66];
int backArray[61];
int LeftToRight[68];

uint8_t ledMode = 1;
bool newMode = 1;
uint8_t oldMode;

extern const TprogmemRGBGradientPalettePtr gGradientPalettes[];
extern const uint8_t gGradientPaletteCount;
uint8_t gCurrentPaletteNumber = 0;
uint8_t currentPaletteIndex = 0;